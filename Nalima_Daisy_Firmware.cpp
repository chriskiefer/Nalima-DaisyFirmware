#include "daisy_patch_sm.h"
#include "daisysp.h"
#include "RPC.hpp"
#include "RingBuf.hpp"




// #include "Maximilian/src/maximilian.h"
// #include "daisysp-lgpl.h"



#define USE_DAISYSP_LGPL 1

#ifndef PI
#define PI 3.1415926535897932384626433832795
#endif

/** These are namespaces for the daisy libraries.
 *  These lines allow us to omit the "daisy::" and "daisysp::" before
 * referencing modules, and functions within the daisy libraries.
 */
using namespace daisy;
using namespace patch_sm;
using namespace daisysp;

DaisyPatchSM patch;

class maxiDCBlocker
{
public:
    double xm1, ym1;
    maxiDCBlocker() : xm1(0), ym1(0) {}
    /*! Remove DC from a signal \param input a signal \param R the sensitivity (0-1) */
    inline double play(double input, double R)
    {
        ym1 = input - xm1 + R * ym1;
        xm1 = input;
        return ym1;
    }   
};

class maxiBiquad
{
public:
    maxiBiquad() {}
    /*! A variety of filter types*/
    enum filterTypes
    {
        LOWPASS,
        HIGHPASS,
        BANDPASS,
        NOTCH,
        PEAK,
        LOWSHELF,
        HIGHSHELF
    };

    /*! Process a signal through the filter \param input A signal*/
    inline double play(double input)
    {
        v[0] = input - (b1 * v[1]) - (b2 * v[2]);
        double y = (a0 * v[0]) + (a1 * v[1]) + (a2 * v[2]);
        v[2] = v[1];
        v[1] = v[0];
        return y;
    }

    /** Configure the filter
     * \param filtType  The type of filter, set from maxiBiquad::filterTypes
     * \param cutoff The filter cutoff frequency in Hz
     * \param Q The resonance of the filter
     * \param peakGain The gain of the filter (only used for PEAK, HIGHSHELF and LOWSHELF)
     */
    inline void set(filterTypes filtType, double cutoff, double Q, double peakGain)
    {
        double norm = 0;
        double V = pow(10.0, abs(peakGain) / 20.0);
        double K = tan(PI * cutoff / patch.AudioSampleRate());
        switch (filtType)
        {
        case LOWPASS:
            norm = 1.0 / (1.0 + K / Q + K * K);
            a0 = K * K * norm;
            a1 = 2.0 * a0;
            a2 = a0;
            b1 = 2.0 * (K * K - 1.0) * norm;
            b2 = (1.0 - K / Q + K * K) * norm;
            break;

        case HIGHPASS:
            norm = 1. / (1. + K / Q + K * K);
            a0 = 1 * norm;
            a1 = -2 * a0;
            a2 = a0;
            b1 = 2 * (K * K - 1) * norm;
            b2 = (1 - K / Q + K * K) * norm;
            break;

        case BANDPASS:
            norm = 1. / (1. + K / Q + K * K);
            a0 = K / Q * norm;
            a1 = 0.;
            a2 = -a0;
            b1 = 2. * (K * K - 1.) * norm;
            b2 = (1. - K / Q + K * K) * norm;
            break;

        case NOTCH:
            norm = 1. / (1. + K / Q + K * K);
            a0 = (1. + K * K) * norm;
            a1 = 2. * (K * K - 1.) * norm;
            a2 = a0;
            b1 = a1;
            b2 = (1. - K / Q + K * K) * norm;
            break;

        case PEAK:
            if (peakGain >= 0.0)
            { // boost
                norm = 1. / (1. + 1. / Q * K + K * K);
                a0 = (1. + V / Q * K + K * K) * norm;
                a1 = 2. * (K * K - 1.) * norm;
                a2 = (1. - V / Q * K + K * K) * norm;
                b1 = a1;
                b2 = (1. - 1. / Q * K + K * K) * norm;
            }
            else
            { // cut
                norm = 1. / (1. + V / Q * K + K * K);
                a0 = (1. + 1 / Q * K + K * K) * norm;
                a1 = 2. * (K * K - 1) * norm;
                a2 = (1. - 1. / Q * K + K * K) * norm;
                b1 = a1;
                b2 = (1. - V / Q * K + K * K) * norm;
            }
            break;
        case LOWSHELF:
            if (peakGain >= 0.)
            { // boost
                norm = 1. / (1. + SQRT2 * K + K * K);
                a0 = (1. + sqrt(2. * V) * K + V * K * K) * norm;
                a1 = 2. * (V * K * K - 1.) * norm;
                a2 = (1. - sqrt(2. * V) * K + V * K * K) * norm;
                b1 = 2. * (K * K - 1.) * norm;
                b2 = (1. - SQRT2 * K + K * K) * norm;
            }
            else
            { // cut
                norm = 1. / (1. + sqrt(2. * V) * K + V * K * K);
                a0 = (1. + SQRT2 * K + K * K) * norm;
                a1 = 2. * (K * K - 1.) * norm;
                a2 = (1. - SQRT2 * K + K * K) * norm;
                b1 = 2. * (V * K * K - 1.) * norm;
                b2 = (1. - sqrt(2. * V) * K + V * K * K) * norm;
            }
            break;
        case HIGHSHELF:
            if (peakGain >= 0.)
            { // boost
                norm = 1. / (1. + SQRT2 * K + K * K);
                a0 = (V + sqrt(2. * V) * K + K * K) * norm;
                a1 = 2. * (K * K - V) * norm;
                a2 = (V - sqrt(2. * V) * K + K * K) * norm;
                b1 = 2. * (K * K - 1) * norm;
                b2 = (1. - SQRT2 * K + K * K) * norm;
            }
            else
            { // cut
                norm = 1. / (V + sqrt(2. * V) * K + K * K);
                a0 = (1. + SQRT2 * K + K * K) * norm;
                a1 = 2. * (K * K - 1.) * norm;
                a2 = (1. - SQRT2 * K + K * K) * norm;
                b1 = 2. * (K * K - V) * norm;
                b2 = (V - sqrt(2. * V) * K + K * K) * norm;
            }
            break;
        }
    }

private:
    double a0 = 0, a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    filterTypes filterType;
    const double SQRT2 = sqrt(2.0);
    double v[3] = {0, 0, 0};
};




Compressor comp;
ReverbSc verb;
//DSY_QSPI_DATA
Compressor rpcLimiter;
Compressor limiter;

maxiBiquad hpfilter,hpfilter2, lpfilter;
maxiDCBlocker dcblock;
PitchShifter pshift1;

RingBuf<float> ringBuf;
size_t           hopCounter = 0;
float           rpc = 0;
Eigen::MatrixXf proj;
size_t           mMaxWindowSize;



struct controlData {
    float gain;
    float thresh1;
    float limthresh;
    float rpcLimThresh;
    float verbfeedback;
    float pitchtrans;
    float pitchfun;
    float lpf;
    float limAtt;
} controls;


void AudioCallback(AudioHandle::InputBuffer  in,
                   AudioHandle::OutputBuffer out,
                   size_t                    size)
{
    patch.ProcessAnalogControls();



    controls.pitchtrans = patch.GetAdcValue(CV_1) * -12.f;
    controls.pitchfun = 0.4f; //patch.GetAdcValue(CV_2);
    // controls.limAtt = patch.GetAdcValue(CV_2) * 0.3f;
    controls.thresh1 = patch.GetAdcValue(CV_3) * -80.f;
    controls.rpcLimThresh = patch.GetAdcValue(CV_4) * -80.f;
    controls.verbfeedback = patch.GetAdcValue(CV_5) * 1.0;
    controls.lpf = fmap(patch.GetAdcValue(CV_6), 1000, 10000, Mapping::EXP);
    controls.limthresh = patch.GetAdcValue(CV_7) * -30.f;
    controls.gain = patch.GetAdcValue(CV_8);


    verb.SetFeedback(controls.verbfeedback);
    verb.SetLpFreq(15000);
    
    comp.SetRatio(10);
    comp.SetThreshold(controls.thresh1);
    comp.AutoMakeup(true);
    rpcLimiter.SetRatio(8);
    rpcLimiter.SetThreshold(controls.rpcLimThresh);
    rpcLimiter.SetAttack(0.1);
    rpcLimiter.SetRelease(0.9);

    limiter.SetRatio(60);
    limiter.SetThreshold(controls.limthresh);
    limiter.SetAttack(0.05);
    limiter.SetRelease(0.5);
    pshift1.SetTransposition(controls.pitchtrans);
    pshift1.SetFun(controls.pitchfun);

     
    lpfilter.set(maxiBiquad::LOWPASS, controls.lpf, 0.7, 0);

    float windowSize = 10.0; 
    float hopSize = 0.5 * windowSize; 

    
    


    for(size_t i = 0; i < size; i++)
    {
        float sig = IN_L[i]; //left channel
        
        ringBuf.push(sig);
        hopCounter++;
        size_t hopSizeInSamples = static_cast<size_t>(hopSize / 1000.f * patch.AudioSampleRate());

        if (hopCounter >= std::min(hopSizeInSamples, mMaxWindowSize))
        {
            hopCounter = 0;
            size_t windowSizeInSamples =
                static_cast<size_t>(windowSize / 1000.f * patch.AudioSampleRate());
            auto window = ringBuf.getBuffer(std::min(windowSizeInSamples, mMaxWindowSize));

            rpc = (float) RPC::calc(proj, window, 10, 0.5);
            if (rpc > 80.f) rpc=90.f;
            rpc = (90.f-rpc) / 90.f;
            // patch.PrintLine(FLT_FMT3, FLT_VAR3(rpc));
        }

        sig = comp.Process(sig);
        sig = rpcLimiter.Process(sig, rpc);


        sig = sig + pshift1.Process(sig);
        sig = lpfilter.play(sig);


        float dryl  = sig * 1.0f;

        float sendl = sig * 0.5f;
        float wetl, wetr;
        verb.Process(sendl, sendl, &wetl, &wetr);
        sig = dryl + wetl;

        sig = hpfilter.play(sig);
        sig = hpfilter2.play(sig);
        sig = sig * 10.f ;
        sig = limiter.Process(sig);
        sig = dcblock.play(sig, 0.996);
        OUT_L[i] = sig  * controls.gain * 0.2;
        OUT_R[i] = 0;


    }
}

int main(void)
{
    /** Initialize the hardware */
    patch.Init();
    // patch.StartLog(true);
    // patch.PrintLine("Hello...");

    double maxWindowSize = 50; 
    mMaxWindowSize = static_cast<size_t>(maxWindowSize / 1000.0 * patch.AudioSampleRate());
    ringBuf.setSize(mMaxWindowSize);
    proj = RPC::createProjectionMatrix(10,3);
    
    comp.Init(patch.AudioSampleRate());
    limiter.Init(patch.AudioSampleRate());
    verb.Init(patch.AudioSampleRate());
    pshift1.Init(patch.AudioSampleRate());

    hpfilter.set(maxiBiquad::HIGHPASS, 200, 0.7, 0);
    hpfilter2.set(maxiBiquad::HIGHPASS, 200, 0.7, 0);
    lpfilter.set(maxiBiquad::LOWPASS, 10000, 0.7, 0);

    //setup
    controls.gain = 1.0;
    controls.verbfeedback = 0.2;
    controls.thresh1 = -40;
    controls.limthresh = -20;
    controls.pitchtrans=0.f;


    /** Start Processing the audio */
    patch.StartAudio(AudioCallback);
    while(1) {}
}
