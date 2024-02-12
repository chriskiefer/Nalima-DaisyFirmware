#define MY_BUFFER_SIZE 16
#define MY_SAMPLE_RATE 44100
/* ------------------------------------------------------------
author: "Julian Parker, bug fixes by Till Bovermann"
copyright: "(c) Julian Parker 2013"
license: "GPL2+"
name: "JPverbRaw"
version: "1.1"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -a /usr/share/faust/daisy/ex_faust.cpp -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

/************************************************************************
 IMPORTANT NOTE : this file contains two clearly delimited sections :
 the ARCHITECTURE section (in two parts) and the USER section. Each section
 is governed by its own copyright and license. Please check individually
 each section for license and copyright information.
 *************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2020-2021 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 
 ************************************************************************
 ************************************************************************/

#include "daisysp.h"

#ifdef PATCH
#include "daisy_patch.h"
#else
#include "daisy_seed.h"
#endif

/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

#endif
/************************** BEGIN DaisyControlUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2020 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_DAISYCONTROL_H
#define FAUST_DAISYCONTROL_H

#include <string>
#include <vector>
#include <memory>
#include <string.h>

#include "daisysp.h"
#include "daisy_seed.h"

/************************** BEGIN DecoratorUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef Decorator_UI_H
#define Decorator_UI_H


//----------------------------------------------------------------
//  Generic UI empty implementation
//----------------------------------------------------------------

class GenericUI : public UI
{
    
    public:
        
        GenericUI() {}
        virtual ~GenericUI() {}
        
        // -- widget's layouts
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* soundpath, Soundfile** sf_zone) {}
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) {}
    
};

//----------------------------------------------------------------
//  Generic UI decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    
    protected:
        
        UI* fUI;
        
    public:
        
        DecoratorUI(UI* ui = 0):fUI(ui) {}
        virtual ~DecoratorUI() { delete fUI; }
        
        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addVerticalBargraph(label, zone, min, max); }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) { fUI->addSoundfile(label, filename, sf_zone); }
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }
    
};

// Defined here to simplify header #include inclusion 
class SoundUIInterface : public GenericUI {};

#endif
/**************************  END  DecoratorUI.h **************************/
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef __ValueConverter__
#define __ValueConverter__

/***************************************************************************************
								ValueConverter.h
							    (GRAME, © 2015)

Set of conversion objects used to map user interface values (for example a gui slider
delivering values between 0 and 1) to faust values (for example a vslider between
20 and 20000) using a log scale.

-- Utilities

Range(lo,hi) : clip a value x between lo and hi
Interpolator(lo,hi,v1,v2) : Maps a value x between lo and hi to a value y between v1 and v2
Interpolator3pt(lo,mi,hi,v1,vm,v2) : Map values between lo mid hi to values between v1 vm v2

-- Value Converters

ValueConverter::ui2faust(x)
ValueConverter::faust2ui(x)

-- ValueConverters used for sliders depending of the scale

LinearValueConverter(umin, umax, fmin, fmax)
LogValueConverter(umin, umax, fmin, fmax)
ExpValueConverter(umin, umax, fmin, fmax)

-- ValueConverters used for accelerometers based on 3 points

AccUpConverter(amin, amid, amax, fmin, fmid, fmax)		-- curve 0
AccDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 1
AccUpDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 2
AccDownUpConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 3

-- lists of ZoneControl are used to implement accelerometers metadata for each axes

ZoneControl(zone, valueConverter) : a zone with an accelerometer data converter

-- ZoneReader are used to implement screencolor metadata

ZoneReader(zone, valueConverter) : a zone with a data converter

****************************************************************************************/

#include <float.h>
#include <algorithm>    // std::max
#include <cmath>
#include <vector>
#include <assert.h>

//--------------------------------------------------------------------------------------
// Interpolator(lo,hi,v1,v2)
// Maps a value x between lo and hi to a value y between v1 and v2
// y = v1 + (x-lo)/(hi-lo)*(v2-v1)
// y = v1 + (x-lo) * coef   		with coef = (v2-v1)/(hi-lo)
// y = v1 + x*coef - lo*coef
// y = v1 - lo*coef + x*coef
// y = offset + x*coef				with offset = v1 - lo*coef
//--------------------------------------------------------------------------------------
class Interpolator
{
    private:

        //--------------------------------------------------------------------------------------
        // Range(lo,hi) clip a value between lo and hi
        //--------------------------------------------------------------------------------------
        struct Range
        {
            double fLo;
            double fHi;

            Range(double x, double y) : fLo(std::min<double>(x,y)), fHi(std::max<double>(x,y)) {}
            double operator()(double x) { return (x<fLo) ? fLo : (x>fHi) ? fHi : x; }
        };


        Range fRange;
        double fCoef;
        double fOffset;

    public:

        Interpolator(double lo, double hi, double v1, double v2) : fRange(lo,hi)
        {
            if (hi != lo) {
                // regular case
                fCoef = (v2-v1)/(hi-lo);
                fOffset = v1 - lo*fCoef;
            } else {
                // degenerate case, avoids division by zero
                fCoef = 0;
                fOffset = (v1+v2)/2;
            }
        }
        double operator()(double v)
        {
            double x = fRange(v);
            return  fOffset + x*fCoef;
        }

        void getLowHigh(double& amin, double& amax)
        {
            amin = fRange.fLo;
            amax = fRange.fHi;
        }
};

//--------------------------------------------------------------------------------------
// Interpolator3pt(lo,mi,hi,v1,vm,v2)
// Map values between lo mid hi to values between v1 vm v2
//--------------------------------------------------------------------------------------
class Interpolator3pt
{

    private:

        Interpolator fSegment1;
        Interpolator fSegment2;
        double fMid;

    public:

        Interpolator3pt(double lo, double mi, double hi, double v1, double vm, double v2) :
            fSegment1(lo, mi, v1, vm),
            fSegment2(mi, hi, vm, v2),
            fMid(mi) {}
        double operator()(double x) { return  (x < fMid) ? fSegment1(x) : fSegment2(x); }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fSegment1.getLowHigh(amin, amid);
            fSegment2.getLowHigh(amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Abstract ValueConverter class. Converts values between UI and Faust representations
//--------------------------------------------------------------------------------------
class ValueConverter
{

    public:

        virtual ~ValueConverter() {}
        virtual double ui2faust(double x) = 0;
        virtual double faust2ui(double x) = 0;
};

//--------------------------------------------------------------------------------------
// Linear conversion between ui and faust values
//--------------------------------------------------------------------------------------
class LinearValueConverter : public ValueConverter
{

    private:

        Interpolator fUI2F;
        Interpolator fF2UI;

    public:

        LinearValueConverter(double umin, double umax, double fmin, double fmax) :
            fUI2F(umin,umax,fmin,fmax), fF2UI(fmin,fmax,umin,umax)
        {}

        LinearValueConverter() :
            fUI2F(0.,0.,0.,0.), fF2UI(0.,0.,0.,0.)
        {}
        virtual double ui2faust(double x) {	return fUI2F(x); }
        virtual double faust2ui(double x) {	return fF2UI(x); }

};

//--------------------------------------------------------------------------------------
// Logarithmic conversion between ui and faust values
//--------------------------------------------------------------------------------------
class LogValueConverter : public LinearValueConverter
{

    public:

        LogValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, log(std::max<double>(DBL_MIN, fmin)), log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) 	{ return exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x)	{ return LinearValueConverter::faust2ui(log(std::max<double>(x, DBL_MIN))); }

};

//--------------------------------------------------------------------------------------
// Exponential conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class ExpValueConverter : public LinearValueConverter
{

    public:

        ExpValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, exp(fmin), exp(fmax))
        {}

        virtual double ui2faust(double x) { return log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(exp(x)); }

};

//--------------------------------------------------------------------------------------
// A converter than can be updated
//--------------------------------------------------------------------------------------

class UpdatableValueConverter : public ValueConverter {

    protected:

        bool fActive;

    public:

        UpdatableValueConverter():fActive(true)
        {}
        virtual ~UpdatableValueConverter()
        {}

        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max) = 0;
        virtual void getMappingValues(double& amin, double& amid, double& amax) = 0;

        void setActive(bool on_off) { fActive = on_off; }
        bool getActive() { return fActive; }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up curve (curve 0)
//--------------------------------------------------------------------------------------
class AccUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt fA2F;
        Interpolator3pt fF2A;

    public:

        AccUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmid,fmax),
            fF2A(fmin,fmid,fmax,amin,amid,amax)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmid,fmax);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amin,amid,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down curve (curve 1)
//--------------------------------------------------------------------------------------
class AccDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator3pt	fF2A;

    public:

        AccDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmid,fmin),
            fF2A(fmin,fmid,fmax,amax,amid,amin)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmid,fmin);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amax,amid,amin);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up-Down curve (curve 2)
//--------------------------------------------------------------------------------------
class AccUpDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccUpDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmax,fmin),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmax,fmin);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down-Up curve (curve 3)
//--------------------------------------------------------------------------------------
class AccDownUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccDownUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmin,fmax),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmin,fmax);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Base class for ZoneControl
//--------------------------------------------------------------------------------------
class ZoneControl
{

    protected:

        FAUSTFLOAT*	fZone;

    public:

        ZoneControl(FAUSTFLOAT* zone) : fZone(zone) {}
        virtual ~ZoneControl() {}

        virtual void update(double v) {}

        virtual void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max) {}
        virtual void getMappingValues(double& amin, double& amid, double& amax) {}

        FAUSTFLOAT* getZone() { return fZone; }

        virtual void setActive(bool on_off) {}
        virtual bool getActive() { return false; }

        virtual int getCurve() { return -1; }

};

//--------------------------------------------------------------------------------------
//  Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class ConverterZoneControl : public ZoneControl
{

    private:

        ValueConverter* fValueConverter;

    public:

        ConverterZoneControl(FAUSTFLOAT* zone, ValueConverter* valueConverter) : ZoneControl(zone), fValueConverter(valueConverter) {}
        virtual ~ConverterZoneControl() { delete fValueConverter; } // Assuming fValueConverter is not kept elsewhere...

        void update(double v) { *fZone = fValueConverter->ui2faust(v); }

        ValueConverter* getConverter() { return fValueConverter; }

};

//--------------------------------------------------------------------------------------
// Association of a zone and a four value converter, each one for each possible curve.
// Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class CurveZoneControl : public ZoneControl
{

    private:

        std::vector<UpdatableValueConverter*> fValueConverters;
        int fCurve;

    public:

        CurveZoneControl(FAUSTFLOAT* zone, int curve, double amin, double amid, double amax, double min, double init, double max) : ZoneControl(zone), fCurve(0)
        {
            assert(curve >= 0 && curve <= 3);
            fValueConverters.push_back(new AccUpConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccUpDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownUpConverter(amin, amid, amax, min, init, max));
            fCurve = curve;
        }
        virtual ~CurveZoneControl()
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                delete(*it);
            }
        }
        void update(double v) { if (fValueConverters[fCurve]->getActive()) *fZone = fValueConverters[fCurve]->ui2faust(v); }

        void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max)
        {
            fValueConverters[curve]->setMappingValues(amin, amid, amax, min, init, max);
            fCurve = curve;
        }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fValueConverters[fCurve]->getMappingValues(amin, amid, amax);
        }

        void setActive(bool on_off)
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                (*it)->setActive(on_off);
            }
        }

        int getCurve() { return fCurve; }
};

class ZoneReader
{

    private:

        FAUSTFLOAT*     fZone;
        Interpolator    fInterpolator;

    public:

        ZoneReader(FAUSTFLOAT* zone, double lo, double hi) : fZone(zone), fInterpolator(lo, hi, 0, 255) {}

        virtual ~ZoneReader() {}

        int getValue() {
            if (fZone != 0) {
                return (int)fInterpolator(*fZone);
            } else {
                return 127;
            }
        }

};

#endif

/*******************************************************************************
 * DaisyControlUI : Faust User Interface
 ******************************************************************************/

// Compatible with Seed Rev3 and Rev4
/*
#define SW_1_PIN 28
#define SW_2_PIN 27
*/

// Seems to be inverted (compared to daisy_pod.cpp)
#define SW_1_PIN 5 // buttons
#define SW_2_PIN 6 // buttons

#define SW_3_PIN 1 // spdt switches
#define SW_4_PIN 2 // spdt switches

#define KNOB_1_PIN 15 // 1
#define KNOB_2_PIN 16 // 2

#define KNOB_3_PIN 21
#define KNOB_4_PIN 18

#define KNOB_5_PIN 19
#define KNOB_6_PIN 17

class DaisyControlUI : public GenericUI
{
    
    private:
    
        // Base class for updatable items
        struct UpdatableZone {
            FAUSTFLOAT* fZone;
            
            UpdatableZone(FAUSTFLOAT* zone) : fZone(zone) {}
            virtual ~UpdatableZone() {}
            
            virtual void update() = 0;
        };
    
        struct SwitchButton : daisy::Switch, UpdatableZone {
            
            SwitchButton(FAUSTFLOAT* zone):UpdatableZone(zone)
            {}
            
            void update()
            {
                *fZone = RawState();
            }
        };
    
        // Implement checkbox using daisy::Switch
        struct CheckButton : daisy::Switch, UpdatableZone {
            
            FAUSTFLOAT fLastButton;
            
            CheckButton(FAUSTFLOAT* zone):UpdatableZone(zone), fLastButton(0)
            {}
            
            void update()
            {
                FAUSTFLOAT button = RawState();
                if (button == 1.0 && (button != fLastButton)) {
                    *fZone = !*fZone;
                }
                fLastButton = button;
            }
        };
    
        struct AnalogKnob : daisy::AnalogControl, UpdatableZone {
            
            std::unique_ptr<ValueConverter> fConverter;
            
            AnalogKnob(uint16_t* adcptr, FAUSTFLOAT* zone, std::unique_ptr<ValueConverter>& converter, int rate)
            :UpdatableZone(zone), fConverter(std::move(converter))
            {
                Init(adcptr, rate);
            }
            
            void update()
            {
                *fZone = fConverter->ui2faust(Process());
            }
        };
    
        std::vector<std::unique_ptr<UpdatableZone>> fItems;
        daisy::DaisySeed* fSeed;
    
        std::string fKey, fValue, fScale;
        int fRate, fBoxLevel;
    
        struct KnobContext
        {
            int fKnobId;
            int fAdcId;
            FAUSTFLOAT* fZone;
            FAUSTFLOAT fMin;
            FAUSTFLOAT fMax;
            std::string fScale;
            KnobContext(int kid,
                        int adcid,
                        FAUSTFLOAT* zone,
                        FAUSTFLOAT min,
                        FAUSTFLOAT max,
                        const std::string& scale)
            :fKnobId(kid), fAdcId(adcid), fZone(zone), fMin(min), fMax(max), fScale(scale)
            {}
        };
        std::vector<KnobContext> fKnobs;
    
        void InitKnob(int knob_pin, int adc_id, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, const std::string& scale)
        {
            // context is kept, to be used in InitKnobs()
            fKnobs.push_back(KnobContext(knob_pin, adc_id, zone, min, max, scale));
        }
    
        void InitKnobs()
        {
            // initialize all knobs in a single step
            daisy::AdcChannelConfig knobs_init[fKnobs.size()];
            for (size_t i = 0; i < fKnobs.size(); i++) {
                knobs_init[i].InitSingle(fSeed->GetPin(fKnobs[i].fKnobId));
            }
            fSeed->adc.Init(knobs_init, fKnobs.size());
            
            for (size_t i = 0; i < fKnobs.size(); i++) {
                std::unique_ptr<ValueConverter> converter;
                if (fKnobs[i].fScale == "log") {
                    converter = std::make_unique<LogValueConverter>(0., 1., fKnobs[i].fMin, fKnobs[i].fMax);
                } else if (fKnobs[i].fScale == "exp") {
                    converter = std::make_unique<ExpValueConverter>(0., 1., fKnobs[i].fMin, fKnobs[i].fMax);
                } else {
                    converter = std::make_unique<LinearValueConverter>(0., 1., fKnobs[i].fMin, fKnobs[i].fMax);
                }
                std::unique_ptr<AnalogKnob> knob = std::make_unique<AnalogKnob>(fSeed->adc.GetPtr(fKnobs[i].fAdcId),
                                                  fKnobs[i].fZone,
                                                  converter,
                                                  fRate);
                fItems.push_back(std::move(knob));
            }
        }
        
    public:
        
        DaisyControlUI(daisy::DaisySeed* seed, int rate)
        :fSeed(seed), fScale("lin"),fRate(rate), fBoxLevel(0)
        {}
    
        // -- widget's layouts
        void openTabBox(const char* label) { fBoxLevel++; }
        void openHorizontalBox(const char* label) { fBoxLevel++; }
        void openVerticalBox(const char* label) { fBoxLevel++; }
        void closeBox()
        {
            if (--fBoxLevel == 0) InitKnobs();
        }
    
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            if (fKey == "switch")
            {
                std::unique_ptr<SwitchButton> button = std::make_unique<SwitchButton>(zone);
                if (fValue == "1") {
                    button->Init(fSeed->GetPin(SW_1_PIN), fRate);
                } else if (fValue == "2") {
                    button->Init(fSeed->GetPin(SW_2_PIN), fRate);
                } else if (fValue == "3") {
                    button->Init(fSeed->GetPin(SW_3_PIN), fRate);
                } else if (fValue == "4") {
                    button->Init(fSeed->GetPin(SW_4_PIN), fRate);
                }
                fItems.push_back(std::move(button));
            }
            fValue = fKey = "";
        }
    
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            if (fKey == "switch")
            {
                std::unique_ptr<CheckButton> button = std::make_unique<CheckButton>(zone);
                if (fValue == "1") {
                    button->Init(fSeed->GetPin(SW_1_PIN), fRate);
                } else if (fValue == "2") {
                    button->Init(fSeed->GetPin(SW_2_PIN), fRate);
                } else if (fValue == "3") {
                    button->Init(fSeed->GetPin(SW_3_PIN), fRate);
                } else if (fValue == "4") {
                    button->Init(fSeed->GetPin(SW_4_PIN), fRate);
                }
                fItems.push_back(std::move(button));
            }
            fValue = fKey = fScale = "";
        }
    
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addNumEntry(label, zone, init, min, max, step);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addNumEntry(label, zone, init, min, max, step);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            if (fKey == "knob")
            {
                if (fValue == "1")
                {
                    InitKnob(KNOB_1_PIN, 0, zone, min, max, fScale);
                } else if (fValue == "2") {
                    InitKnob(KNOB_2_PIN, 1, zone, min, max, fScale);
                } else if (fValue == "3") {
                    InitKnob(KNOB_3_PIN, 2, zone, min, max, fScale);
                } else if (fValue == "4") {
                    InitKnob(KNOB_4_PIN, 3, zone, min, max, fScale);
                } else if (fValue == "5") {
                    InitKnob(KNOB_5_PIN, 4, zone, min, max, fScale);
                } else if (fValue == "6") {
                    InitKnob(KNOB_6_PIN, 5, zone, min, max, fScale);
                }
            }
            fValue = fKey = fScale = "";
        }
    
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            if (strcmp(key, "switch") == 0
                || strcmp(key, "knob") == 0
                || strcmp(key, "encoder") == 0) {
                fKey = key;
                fValue = val;
            } else if (std::string(key) == "scale") {
                fScale = val;
            }
        }
    
        void update()
        {
            for (const auto& it : fItems) it->update();
        }
    
};

#endif // FAUST_DAISYCONTROL_H
/**************************  END  DaisyControlUI.h **************************/
/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

								FAUST DSP

*******************************************************************************
*******************************************************************************/

#ifndef __dsp__
#define __dsp__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the UI* parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the UI* user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /** Global init, calls the following methods:
         * - static class 'classInit': static table initialisation
         * - 'instanceInit': constants and instance table initialisation
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void init(int samplingRate) = 0;
    
        /** Init instance state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceInit(int samplingRate) = 0;
    
        /** Init instance constant state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
    
        /**  
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value metadata).
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with sucessive in/out audio buffers.
         *
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { return fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
       
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif

#ifdef MIDICTRL
/************************** BEGIN daisy-midi.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2020 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __daisy_midi__
#define __daisy_midi__

#include <cstdlib>

#include "daisysp.h"
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/

#ifndef __midi__
#define __midi__

#include <vector>
#include <string>
#include <algorithm>

class MapUI;

//----------------------------------------------------------------
//  MIDI processor definition
//----------------------------------------------------------------

class midi {

    public:

        midi() {}
        virtual ~midi() {}

        // Additional time-stamped API for MIDI input
        virtual MapUI* keyOn(double, int channel, int pitch, int velocity)
        {
            return keyOn(channel, pitch, velocity);
        }
        
        virtual void keyOff(double, int channel, int pitch, int velocity = 127)
        {
            keyOff(channel, pitch, velocity);
        }
        
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
       
        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
        
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
       
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }

        // MIDI sync
        virtual void start_sync(double date)  {}
        virtual void stop_sync(double date)   {}
        virtual void clock(double date)  {}

        // Standard MIDI API
        virtual MapUI* keyOn(int channel, int pitch, int velocity)      { return 0; }
        virtual void keyOff(int channel, int pitch, int velocity)       {}
        virtual void keyPress(int channel, int pitch, int press)        {}
        virtual void chanPress(int channel, int press)                  {}
        virtual void ctrlChange(int channel, int ctrl, int value)       {}
        virtual void ctrlChange14bits(int channel, int ctrl, int value) {}
        virtual void pitchWheel(int channel, int wheel)                 {}
        virtual void progChange(int channel, int pgm)                   {}

        enum MidiStatus {

            // channel voice messages
            MIDI_NOTE_OFF           = 0x80,
            MIDI_NOTE_ON            = 0x90,
            MIDI_CONTROL_CHANGE     = 0xB0,
            MIDI_PROGRAM_CHANGE     = 0xC0,
            MIDI_PITCH_BEND         = 0xE0,
            MIDI_AFTERTOUCH         = 0xD0,	// aka channel pressure
            MIDI_POLY_AFTERTOUCH    = 0xA0,	// aka key pressure
            MIDI_CLOCK              = 0xF8,
            MIDI_START              = 0xFA,
            MIDI_STOP               = 0xFC

        };

        enum MidiCtrl {

            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120

        };
};

//----------------------------------------------------------------
//  Base class for MIDI API handling
//----------------------------------------------------------------

class midi_handler : public midi {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;

    public:

        midi_handler(const std::string& name = "MIDIHandler"):fName(name) {}
        virtual ~midi_handler() {}

        virtual void addMidiIn(midi* midi_dsp) { if (midi_dsp) fMidiInputs.push_back(midi_dsp); }
        virtual void removeMidiIn(midi* midi_dsp)
        {
            std::vector<midi*>::iterator it = std::find(fMidiInputs.begin(), fMidiInputs.end(), midi_dsp);
            if (it != fMidiInputs.end()) {
                fMidiInputs.erase(it);
            }
        }

        virtual bool start_midi() { return true; }
        virtual void stop_midi() {}
        
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->clock(time);
                }
            } else if (type == MIDI_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->start_sync(time);
                }
            } else if (type == MIDI_STOP) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->stop_sync(time);
                }
            }
        }

        void handleData1(double time, int type, int channel, int data1)
        {
            if (type == MIDI_PROGRAM_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->progChange(time, channel, data1);
                }
            } else if (type == MIDI_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->chanPress(time, channel, data1);
                }
            }
        }

        void handleData2(double time, int type, int channel, int data1, int data2)
        {
            if (type == MIDI_NOTE_OFF || ((type == MIDI_NOTE_ON) && (data2 == 0))) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOff(time, channel, data1, data2);
                }
            } else if (type == MIDI_NOTE_ON) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOn(time, channel, data1, data2);
                }
            } else if (type == MIDI_CONTROL_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->ctrlChange(time, channel, data1, data2);
                }
            } else if (type == MIDI_PITCH_BEND) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->pitchWheel(time, channel, (data2 * 128.0) + data1);
                }
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyPress(time, channel, data1, data2);
                }
            }
        }


};

#endif // __midi__
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_GUI_H
#define FAUST_GUI_H

/*
  Copyright (C) 2000 Paul Davis
  Copyright (C) 2003 Rohan Drape
  Copyright (C) 2016 GRAME (renaming for internal use)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

  ISO/POSIX C version of Paul Davis's lock free ringbuffer C++ code.
  This is safe for the case of one read thread and one write thread.
*/

#ifndef __ring_buffer__
#define __ring_buffer__

#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    size_t len;
}
ringbuffer_data_t;

typedef struct {
    char *buf;
    volatile size_t write_ptr;
    volatile size_t read_ptr;
    size_t	size;
    size_t	size_mask;
    int	mlocked;
}
ringbuffer_t;

ringbuffer_t *ringbuffer_create(size_t sz);
void ringbuffer_free(ringbuffer_t *rb);
void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_read_space(const ringbuffer_t *rb);
int ringbuffer_mlock(ringbuffer_t *rb);
void ringbuffer_reset(ringbuffer_t *rb);
void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two.  */

inline ringbuffer_t *
ringbuffer_create (size_t sz)
{
	size_t power_of_two;
	ringbuffer_t *rb;

	if ((rb = (ringbuffer_t *) malloc (sizeof (ringbuffer_t))) == NULL) {
		return NULL;
	}

	for (power_of_two = 1u; 1u << power_of_two < sz; power_of_two++);

	rb->size = 1u << power_of_two;
	rb->size_mask = rb->size;
	rb->size_mask -= 1;
	rb->write_ptr = 0;
	rb->read_ptr = 0;
	if ((rb->buf = (char *) malloc (rb->size)) == NULL) {
		free (rb);
		return NULL;
	}
	rb->mlocked = 0;

	return rb;
}

/* Free all data associated with the ringbuffer `rb'. */

inline void
ringbuffer_free (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (rb->mlocked) {
		munlock (rb->buf, rb->size);
	}
#endif /* USE_MLOCK */
	free (rb->buf);
	free (rb);
}

/* Lock the data block of `rb' using the system call 'mlock'.  */

inline int
ringbuffer_mlock (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (mlock (rb->buf, rb->size)) {
		return -1;
	}
#endif /* USE_MLOCK */
	rb->mlocked = 1;
	return 0;
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
ringbuffer_reset_size (ringbuffer_t * rb, size_t sz)
{
    rb->size = sz;
    rb->size_mask = rb->size;
    rb->size_mask -= 1;
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}

/* Return the number of bytes available for reading.  This is the
   number of bytes in front of the read pointer and behind the write
   pointer.  */

inline size_t
ringbuffer_read_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return w - r;
	} else {
		return (w - r + rb->size) & rb->size_mask;
	}
}

/* Return the number of bytes available for writing.  This is the
   number of bytes in front of the write pointer and behind the read
   pointer.  */

inline size_t
ringbuffer_write_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		return (r - w) - 1;
	} else {
		return rb->size - 1;
	}
}

/* The copying data reader.  Copy at most `cnt' bytes from `rb' to
   `dest'.  Returns the actual number of bytes copied. */

inline size_t
ringbuffer_read (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[rb->read_ptr]), n1);
	rb->read_ptr = (rb->read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[rb->read_ptr]), n2);
		rb->read_ptr = (rb->read_ptr + n2) & rb->size_mask;
	}

	return to_read;
}

/* The copying data reader w/o read pointer advance.  Copy at most
   `cnt' bytes from `rb' to `dest'.  Returns the actual number of bytes
   copied. */

inline size_t
ringbuffer_peek (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;
	size_t tmp_read_ptr;

	tmp_read_ptr = rb->read_ptr;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = tmp_read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - tmp_read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[tmp_read_ptr]), n1);
	tmp_read_ptr = (tmp_read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[tmp_read_ptr]), n2);
	}

	return to_read;
}

/* The copying data writer.  Copy at most `cnt' bytes to `rb' from
   `src'.  Returns the actual number of bytes copied. */

inline size_t
ringbuffer_write (ringbuffer_t * rb, const char *src, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_write;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_write_space (rb)) == 0) {
		return 0;
	}

	to_write = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->write_ptr + to_write;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->write_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_write;
		n2 = 0;
	}

	memcpy (&(rb->buf[rb->write_ptr]), src, n1);
	rb->write_ptr = (rb->write_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (&(rb->buf[rb->write_ptr]), src + n1, n2);
		rb->write_ptr = (rb->write_ptr + n2) & rb->size_mask;
	}

	return to_write;
}

/* Advance the read pointer `cnt' places. */

inline void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

inline void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader.  `vec' is an array of two places.  Set
   the values at `vec' to hold the current readable data at `rb'.  If
   the readable data is in one segment the second segment has zero
   length.  */

inline void
ringbuffer_get_read_vector (const ringbuffer_t * rb,
				 ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = w - r;
	} else {
		free_cnt = (w - r + rb->size) & rb->size_mask;
	}

	cnt2 = r + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = rb->size - r;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;

	} else {

		/* Single part vector: just the rest of the buffer */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

/* The non-copying data writer.  `vec' is an array of two places.  Set
   the values at `vec' to hold the current writeable data at `rb'.  If
   the writeable data is in one segment the second segment has zero
   length.  */

inline void
ringbuffer_get_write_vector (const ringbuffer_t * rb,
				  ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		free_cnt = (r - w) - 1;
	} else {
		free_cnt = rb->size - 1;
	}

	cnt2 = w + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[w]);
		vec[0].len = rb->size - w;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;
	} else {
		vec[0].buf = &(rb->buf[w]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

#endif // __ring_buffer__

#include <list>
#include <map>
#include <vector>

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

class clist : public std::list<uiItem*>
{
    public:
    
        virtual ~clist();
        
};

typedef std::map<FAUSTFLOAT*, clist*> zmap;

typedef std::map<FAUSTFLOAT*, ringbuffer_t*> ztimedmap;

class GUI : public UI
{
		
    private:
     
        static std::list<GUI*>  fGuiList;
        zmap                    fZoneMap;
        bool                    fStopped;
        
     public:
            
        GUI() : fStopped(false) 
        {	
            fGuiList.push_back(this);
        }
        
        virtual ~GUI() 
        {   
            // delete all 
            zmap::iterator g;
            for (g = fZoneMap.begin(); g != fZoneMap.end(); g++) {
                delete (*g).second;
            }
            // suppress 'this' in static fGuiList
            fGuiList.remove(this);
        }

        // -- registerZone(z,c) : zone management
        
        void registerZone(FAUSTFLOAT* z, uiItem* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }

        void updateAllZones();
        
        void updateZone(FAUSTFLOAT* z);
        
        static void updateAllGuis()
        {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->updateAllZones();
            }
        }
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data);
        virtual void show() {};	
        virtual bool run() { return false; };
    
        virtual void stop() { fStopped = true; }
        bool stopped() { return fStopped; }
    
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {};
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* , const char* , const char*) {}
    
        // Static global for timed zones, shared between all UI that will set timed values
        static ztimedmap gTimedZoneMap;

};

/**
 * User Interface Item: abstract definition
 */

class uiItem
{
    protected:
          
        GUI*            fGUI;
        FAUSTFLOAT*     fZone;
        FAUSTFLOAT      fCache;

        uiItem(GUI* ui, FAUSTFLOAT* zone):fGUI(ui), fZone(zone), fCache(FAUSTFLOAT(-123456.654321))
        { 
            ui->registerZone(zone, this); 
        }

    public:

        virtual ~uiItem() 
        {}

        void modifyZone(FAUSTFLOAT v) 	
        { 
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }
                
        FAUSTFLOAT		cache()	{ return fCache; }
        virtual void 	reflectZone() = 0;	
};

/**
 * User Interface item owned (and so deleted) by external code
 */

class uiOwnedItem : public uiItem {
    
    protected:
    
        uiOwnedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
    
     public:
    
        virtual ~uiOwnedItem()
        {}
    
        virtual void reflectZone() {}
};

/**
 * Callback Item
 */

struct uiCallbackItem : public uiItem
{
	uiCallback	fCallback;
	void*		fData;
	
	uiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data) 
			: uiItem(ui, zone), fCallback(foo), fData(data) {}
	
	virtual void reflectZone() 
    {		
		FAUSTFLOAT 	v = *fZone;
		fCache = v; 
		fCallback(v, fData);	
	}
};

/**
 * Allows to group a set of zones.
 */
 
class uiGroupItem : public uiItem 
{
    protected:
    
        std::vector<FAUSTFLOAT*> fZoneMap;

    public:
    
        uiGroupItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
        virtual ~uiGroupItem() 
        {}
        
        virtual void reflectZone() 
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            
            // Update all zones of the same group
            std::vector<FAUSTFLOAT*>::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                (*(*it)) = v;
            }
        }
        
        void addZone(FAUSTFLOAT* zone) { fZoneMap.push_back(zone); }

};

/**
 * Update all user items reflecting zone z
 */

inline void GUI::updateZone(FAUSTFLOAT* z)
{
	FAUSTFLOAT v = *z;
	clist* l = fZoneMap[z];
	for (clist::iterator c = l->begin(); c != l->end(); c++) {
		if ((*c)->cache() != v) (*c)->reflectZone();
	}
}

/**
 * Update all user items not up to date
 */

inline void GUI::updateAllZones()
{
	for (zmap::iterator m = fZoneMap.begin(); m != fZoneMap.end(); m++) {
		FAUSTFLOAT* z = m->first;
		clist*	l = m->second;
        if (z) {
            FAUSTFLOAT	v = *z;
            for (clist::iterator c = l->begin(); c != l->end(); c++) {
                if ((*c)->cache() != v) (*c)->reflectZone();
            }
        }
	}
}

inline void GUI::addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data) 
{ 
	new uiCallbackItem(this, zone, foo, data); 
};

inline clist::~clist() 
{
    std::list<uiItem*>::iterator it;
    for (it = begin(); it != end(); it++) {
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(*it);
        // owned items are deleted by external code
        if (!owned) {
            delete (*it);
        }
    }
}

// For precise timestamped control
struct DatedControl {

    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}

};
  
#endif

class daisy_midi : public midi_handler {
    
    private:
    
        daisy::MidiHandler fMidi;
    
    public:
    
        daisy_midi():midi_handler("daisy")
        {}
    
        virtual ~daisy_midi()
        {
            stopMidi();
        }

        bool startMidi()
        {
            fMidi.Init(daisy::MidiHandler::INPUT_MODE_UART1, daisy::MidiHandler::OUTPUT_MODE_NONE);
            return true;
        }

        void stopMidi()
        {}
    
        void processMidi()
        {
            fMidi.Listen();
            while (fMidi.HasEvents()) {
                
                double time = 0.;
                daisy::MidiEvent m = fMidi.PopEvent();
                switch(m.type) {
                        
                    case daisy::MidiMessageType::NoteOff: {
                        // TODO
                        //NoteOff p = m.AsNoteOff();
                        //handleKeyOff(time, p.channel, p.note, p.velocity);
                        break;
                    }
                        
                    case daisy::MidiMessageType::NoteOn: {
                        daisy::NoteOnEvent p = m.AsNoteOn();
                        handleKeyOn(time, p.channel, p.note, p.velocity);
                        break;
                    }
                        
                    case daisy::MidiMessageType::PolyphonicKeyPressure: {
                        // TODO
                        //handlePolyAfterTouch(time, m.channel, m.control_number, m.value);
                        break;
                    }
                        
                    case daisy::MidiMessageType::ControlChange: {
                        daisy::ControlChangeEvent p = m.AsControlChange();
                        handleCtrlChange(time, p.channel, p.control_number, p.value);
                        break;
                    }
                        
                    case daisy::MidiMessageType::ProgramChange: {
                        // TODO
                        //handleProgChange(time, p.channel, p.control_number, p.value);
                        break;
                    }
                        
                    case daisy::MidiMessageType::PitchBend: {
                        // TODO
                        //handlePitchWheel(time, p.channel, p.control_number, p.value);
                        break;
                    }
                        
                    default:
                        break;
                }
            }
            // Synchronize all GUI controllers
            GUI::updateAllGuis();
        }
   
};

#endif
/**************************  END  daisy-midi.h **************************/
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/

#ifndef FAUST_MIDIUI_H
#define FAUST_MIDIUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <vector>
#include <string>
#include <utility>
#include <iostream>

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <assert.h>

/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 ******************************************************************************/

class JSONUI : public PathBuilder, public Meta, public UI
{

    protected:
    
        std::stringstream fJSON;
        std::stringstream fUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fName;
        std::string fExpandedCode;
        std::string fSHAKey;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        void addMeta(int tab_val, bool quote = true)
        {
            if (fMetaAux.size() > 0) {
                tab(tab_val, fUI); fUI << "\"meta\": [";
                std::string sep = "";
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    fUI << sep;
                    tab(tab_val + 1, fUI); fUI << "{ \"" << fMetaAux[i].first << "\": \"" << fMetaAux[i].second << "\" }";
                    sep = ",";
                }
                tab(tab_val, fUI); fUI << ((quote) ? "],": "]");
                fMetaAux.clear();
            }
        }
        
        void init(const std::string& name, int inputs, int outputs, const std::string& sha_key, const std::string& dsp_code)
        {
            fTab = 1;
            
            // Start Meta generation
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fInputs = inputs;
            fOutputs = outputs;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
        }
        
        inline std::string flatten(const std::string& src)
        {
            std::stringstream dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        dst << ' ';
                        break;
                    case '"':
                        dst << "\\" << '"';
                        break;
                    default:
                        dst << src[i];
                        break;
                }
            }
            return dst.str();
        }
      
     public:
     
        JSONUI(const std::string& name, int inputs, int outputs, const std::string& sha_key, const std::string& dsp_code)
        {
            init(name, inputs, outputs, sha_key, dsp_code);
        }

        JSONUI(const std::string& name, int inputs, int outputs)
        {
            init(name, inputs, outputs, "", "");
        }

        JSONUI(int inputs, int outputs)
        {
            init("", inputs, outputs, "", "");
        }
        
        JSONUI()
        {
            init("", -1, -1, "", "");
        }
 
        virtual ~JSONUI() {}

        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            fControlsLevel.push_back(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab + 1);
            tab(fTab, fUI); fUI << "\"items\": [";
            fCloseUIPar = ' ';
            fTab += 1;
        }

        virtual void openTabBox(const char* label)
        {
            openGenericGroup(label, "tgroup");
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openGenericGroup(label, "hgroup");
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openGenericGroup(label, "vgroup");
        }
    
        virtual void closeBox()
        {
            fControlsLevel.pop_back();
            fTab -= 1;
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        // -- active widgets
    
        virtual void addGenericButton(const char* label, const char* name)
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            addMeta(fTab + 1, false);
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ",";
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"init\": \"" << init << "\",";
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\",";
            tab(fTab + 1, fUI); fUI << "\"step\": \"" << step << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ",";
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        std::string JSON(bool flat = false)
        {
            fTab = 0;
            fJSON << "{";
            fTab += 1;
            tab(fTab, fJSON); fJSON << "\"name\": \"" << fName << "\",";
            if (fSHAKey != "") { tab(fTab, fJSON); fJSON << "\"sha_key\": \"" << fSHAKey << "\","; }
            if (fExpandedCode != "") { tab(fTab, fJSON); fJSON << "\"code\": \"" << fExpandedCode << "\","; }
            tab(fTab, fJSON); fJSON << "\"inputs\": \"" << fInputs << "\","; 
            tab(fTab, fJSON); fJSON << "\"outputs\": \"" << fOutputs << "\",";
            tab(fTab, fMeta); fMeta << "],";
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                fJSON << fMeta.str() << fUI.str();
            } else {
                fJSON << fUI.str();
            }
            tab(fTab, fJSON); fJSON << "}" << std::endl;
            return (flat) ? flatten(fJSON.str()) : fJSON.str();
        }
    
};

#endif // FAUST_JSONUI_H

#ifdef _MSC_VER
#define gsscanf sscanf_s
#else
#define gsscanf sscanf
#endif

/*****************************************************************************
* Helper code for MIDI meta and polyphonic 'nvoices' parsing
******************************************************************************/

struct MidiMeta : public Meta, public std::map<std::string, std::string>
{
    void declare(const char* key, const char* value)
    {
        (*this)[key] = value;
    }
    
    const std::string get(const char* key, const char* def)
    {
        if (this->find(key) != this->end()) {
            return (*this)[key];
        } else {
            return def;
        }
    }
    
    static void analyse(dsp* tmp_dsp, bool& midi_sync, int& nvoices)
    {
        JSONUI jsonui;
        tmp_dsp->buildUserInterface(&jsonui);
        std::string json = jsonui.JSON();
        midi_sync = ((json.find("midi") != std::string::npos) &&
                     ((json.find("start") != std::string::npos) ||
                      (json.find("stop") != std::string::npos) ||
                      (json.find("clock") != std::string::npos)));
    
    #if defined(NVOICES) && NVOICES!=NUM_VOICES
        nvoices = NVOICES;
    #else
        MidiMeta meta;
        tmp_dsp->metadata(&meta);
        std::string numVoices = meta.get("nvoices", "0");
        nvoices = atoi(numVoices.c_str());
        if (nvoices < 0) nvoices = 0;
    #endif
    }
};

/*******************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI meta data and maps incoming MIDI messages to them.
 * Currently ctrl, keyon/keyoff, keypress, pgm, chanpress, pitchwheel/pitchbend 
 * start/stop/clock meta data is handled.
 ******************************************************************************/
 
class uiMidiItem : public uiItem {
 
    protected:
    
         midi* fMidiOut;
         bool fInputCtrl;

    public:
    
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input)
            :uiItem(ui, zone), fMidiOut(midi_out), fInputCtrl(input) {}
        virtual ~uiMidiItem() {}
 
};
 
class uiMidiTimedItem : public uiMidiItem
{
    protected:
    
        bool fDelete;
   
    public:
       
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input)
        {
            if (GUI::gTimedZoneMap.find(fZone) == GUI::gTimedZoneMap.end()) {
                GUI::gTimedZoneMap[fZone] = ringbuffer_create(8192);
                fDelete = true;
            } else {
                fDelete = false;
            }
        }
        
        virtual ~uiMidiTimedItem() 
        {
            ztimedmap::iterator it;
            if (fDelete && ((it = GUI::gTimedZoneMap.find(fZone)) != GUI::gTimedZoneMap.end())) {
                ringbuffer_free((*it).second);
                GUI::gTimedZoneMap.erase(it);
            }
        }

        void modifyZone(double date, FAUSTFLOAT v) 	
        { 
            size_t res;
            DatedControl dated_val(date, v);
            if ((res = ringbuffer_write(GUI::gTimedZoneMap[fZone], (const char*)&dated_val, sizeof(DatedControl))) != sizeof(DatedControl)) {
                std::cerr << "ringbuffer_write error DatedControl" << std::endl;
            }
        }
        
        // TODO
        virtual void reflectZone() {}

};

// MIDI sync

class uiMidiStart : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStart(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStart()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->start_sync(0);
            }
        }
        
};

class uiMidiStop : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStop(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStop()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(1)) {
                fMidiOut->stop_sync(0);
            }
        }
};

class uiMidiClock : public uiMidiTimedItem
{

    private:
        
        bool fState;
  
    public:
    
        uiMidiClock(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fState(false)
        {}
        virtual ~uiMidiClock()
        {}
        
        void modifyZone(double date, FAUSTFLOAT v) 	
        { 
            if (fInputCtrl) {
                fState = !fState;
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fState));
            }
        }
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->clock(0);
        }
};

class uiMidiProgChange : public uiMidiItem
{
    private:
        
        int fPgm;
  
    public:
    
        uiMidiProgChange(midi* midi_out, int pgm, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPgm(pgm)
        {}
        virtual ~uiMidiProgChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->progChange(0, fPgm);
            }
        }
        
};

class uiMidiChanPress : public uiMidiItem
{
    private:
        
        int fPress;
  
    public:
    
        uiMidiChanPress(midi* midi_out, int press, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPress(press)
        {}
        virtual ~uiMidiChanPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->chanPress(0, fPress);
            }
        }
        
};

class uiMidiCtrlChange : public uiMidiItem
{
    private:
    
        int fCtrl;
        LinearValueConverter fConverter;
 
    public:
    
        uiMidiCtrlChange(midi* midi_out, int ctrl, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fCtrl(ctrl), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiCtrlChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->ctrlChange(0, fCtrl, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
 
};

class uiMidiPitchWheel : public uiMidiItem
{

    private:
    	
		// currently, the range is of pitchwheel if fixed (-2/2 semitones)
        FAUSTFLOAT wheel2bend(float v)
        {
            return pow(2.0,(v/16383.0*4-2)/12);
        }

        int bend2wheel(float v)
        {
            return (int)((12*log(v)/log(2)+2)/4*16383);
        }
 
    public:
    
        uiMidiPitchWheel(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->pitchWheel(0, bend2wheel(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(wheel2bend(v));
            }
        }
 
};

class uiMidiKeyOn : public uiMidiItem
{

    private:
        
        int fKeyOn;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOn(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOn(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOn()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOn(0, fKeyOn, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class uiMidiKeyOff : public uiMidiItem
{

    private:
        
        int fKeyOff;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOff(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOff(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOff()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOff(0, fKeyOff, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class uiMidiKeyPress : public uiMidiItem
{

    private:
        
        int fKey;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKey(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyPress(0, fKey, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class MapUI;

class MidiUI : public GUI, public midi
{

    protected:
    
        std::map <int, std::vector<uiMidiCtrlChange*> > fCtrlChangeTable;
        std::map <int, std::vector<uiMidiProgChange*> > fProgChangeTable;
        std::map <int, std::vector<uiMidiChanPress*> >  fChanPressTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyOnTable;
        std::map <int, std::vector<uiMidiKeyOff*> >     fKeyOffTable;
        std::map <int, std::vector<uiMidiKeyPress*> >   fKeyPressTable;
        std::vector<uiMidiPitchWheel*>                  fPitchWheelTable;
        
        std::vector<uiMidiStart*>   fStartTable;
        std::vector<uiMidiStop*>    fStopTable;
        std::vector<uiMidiClock*>   fClockTable;
        
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        
        midi_handler* fMidiHandler;
        
        void addGenericZone(FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
        {
            if (fMetaAux.size() > 0) {
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    unsigned num;
                    if (fMetaAux[i].first == "midi") {
                        if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u", &num) == 1) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u", &num) == 1) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u", &num) == 1) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u", &num) == 1) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "pgm %u", &num) == 1) {
                            fProgChangeTable[num].push_back(new uiMidiProgChange(fMidiHandler, num, this, zone, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "chanpress %u", &num) == 1) {
                            fChanPressTable[num].push_back(new uiMidiChanPress(fMidiHandler, num, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "pitchwheel") == 0 
                            || strcmp(fMetaAux[i].second.c_str(), "pitchbend") == 0) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, input));
                        // MIDI sync
                        } else if (strcmp(fMetaAux[i].second.c_str(), "start") == 0) {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "stop") == 0) {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "clock") == 0) {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        }
                    }
                }
            }
            fMetaAux.clear();
        }

    public:

        MidiUI(midi_handler* midi_handler)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
        }
 
        virtual ~MidiUI() 
        { 
            fMidiHandler->removeMidiIn(this);
        }
        
        bool run() { return fMidiHandler->start_midi(); }
        void stop() { fMidiHandler->stop_midi(); }
        
        void addMidiIn(midi* midi_dsp) { fMidiHandler->addMidiIn(midi_dsp); }
        void removeMidiIn(midi* midi_dsp) { fMidiHandler->removeMidiIn(midi_dsp); }
      
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericZone(zone, min, max, false);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericZone(zone, min, max, false);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
        
        // -- MIDI API 
        
        MapUI* keyOn(double date, int channel, int note, int velocity)
        {
            if (fKeyOnTable.find(note) != fKeyOnTable.end()) {
                for (unsigned int i = 0; i < fKeyOnTable[note].size(); i++) {
                    fKeyOnTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            return 0;
        }
        
        void keyOff(double date,  int channel, int note, int velocity)
        {
            if (fKeyOffTable.find(note) != fKeyOffTable.end()) {
                for (unsigned int i = 0; i < fKeyOffTable[note].size(); i++) {
                    fKeyOffTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
        }
           
        void ctrlChange(double date, int channel, int ctrl, int value)
        {
            if (fCtrlChangeTable.find(ctrl) != fCtrlChangeTable.end()) {
                for (unsigned int i = 0; i < fCtrlChangeTable[ctrl].size(); i++) {
                    fCtrlChangeTable[ctrl][i]->modifyZone(FAUSTFLOAT(value));
                }
            } 
        }
        
        void progChange(double date, int channel, int pgm)
        {
            if (fProgChangeTable.find(pgm) != fProgChangeTable.end()) {
                for (unsigned int i = 0; i < fProgChangeTable[pgm].size(); i++) {
                    fProgChangeTable[pgm][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void pitchWheel(double date, int channel, int wheel) 
        {
            for (unsigned int i = 0; i < fPitchWheelTable.size(); i++) {
                fPitchWheelTable[i]->modifyZone(FAUSTFLOAT(wheel));
            }
        }
        
        void keyPress(double date, int channel, int pitch, int press) 
        {
            if (fKeyPressTable.find(pitch) != fKeyPressTable.end()) {
                for (unsigned int i = 0; i < fKeyPressTable[pitch].size(); i++) {
                    fKeyPressTable[pitch][i]->modifyZone(FAUSTFLOAT(press));
                }
            } 
        }
        
        void chanPress(double date, int channel, int press)
        {
            if (fChanPressTable.find(press) != fChanPressTable.end()) {
                for (unsigned int i = 0; i < fChanPressTable[press].size(); i++) {
                    fChanPressTable[press][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void ctrlChange14bits(double date, int channel, int ctrl, int value) {}
        
        // MIDI sync
        
        void start_sync(double date)
        {
            for (unsigned int i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stop_sync(double date)
        {
            for (unsigned int i = 0; i < fStopTable.size(); i++) {
                fStopTable[i]->modifyZone(date, FAUSTFLOAT(0));
            }
        }
        
        void clock(double date)
        {
            for (unsigned int i = 0; i < fClockTable.size(); i++) {
                fClockTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
};

#endif // FAUST_MIDIUI_H
#endif

using namespace daisysp;
using namespace std;

/******************************************************************************
 *******************************************************************************
 
 VECTOR INTRINSICS
 
 *******************************************************************************
 *******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "primes" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <jprev.h>
#include <math.h>

static float mydsp_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int iVec0[2];
	FAUSTFLOAT fHslider2;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider3;
	float fRec15[2];
	float fRec16[2];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	float fConst2;
	FAUSTFLOAT fHslider7;
	int IOTA;
	float fVec1[16384];
	float fRec53[2];
	float fVec2[2];
	float fRec52[2];
	float fRec50[2];
	float fVec3[16384];
	float fRec55[2];
	float fVec4[2];
	float fRec54[2];
	float fRec51[2];
	float fVec5[16384];
	float fRec56[2];
	float fVec6[2];
	float fRec49[2];
	float fRec47[2];
	float fVec7[16384];
	float fRec58[2];
	float fVec8[2];
	float fRec57[2];
	float fRec48[2];
	float fVec9[16384];
	float fRec59[2];
	float fVec10[2];
	float fRec46[2];
	float fRec44[2];
	float fVec11[16384];
	float fRec61[2];
	float fVec12[2];
	float fRec60[2];
	float fRec45[2];
	float fVec13[16384];
	float fRec62[2];
	float fVec14[2];
	float fRec43[2];
	float fRec41[2];
	float fVec15[16384];
	float fRec64[2];
	float fVec16[2];
	float fRec63[2];
	float fRec42[2];
	float fVec17[16384];
	float fRec65[2];
	float fVec18[2];
	float fRec40[2];
	float fRec38[2];
	float fVec19[16384];
	float fRec67[2];
	float fVec20[2];
	float fRec66[2];
	float fRec39[2];
	float fVec21[1024];
	float fVec22[16384];
	float fRec68[2];
	float fVec23[2];
	float fRec37[2];
	float fVec24[1024];
	float fVec25[16384];
	float fRec70[2];
	float fVec26[2];
	float fRec69[2];
	float fVec27[16384];
	float fRec71[2];
	float fVec28[2];
	float fRec36[2];
	float fRec34[2];
	float fVec29[16384];
	float fRec73[2];
	float fVec30[2];
	float fRec72[2];
	float fRec35[2];
	float fVec31[16384];
	float fRec74[2];
	float fVec32[2];
	float fRec33[2];
	float fRec31[2];
	float fVec33[16384];
	float fRec76[2];
	float fVec34[2];
	float fRec75[2];
	float fRec32[2];
	float fVec35[16384];
	float fRec77[2];
	float fVec36[2];
	float fRec30[2];
	float fRec28[2];
	float fVec37[16384];
	float fRec79[2];
	float fVec38[2];
	float fRec78[2];
	float fRec29[2];
	float fVec39[16384];
	float fRec80[2];
	float fVec40[2];
	float fRec27[2];
	float fRec25[2];
	float fVec41[16384];
	float fRec82[2];
	float fVec42[2];
	float fRec81[2];
	float fRec26[2];
	float fVec43[16384];
	float fRec83[2];
	float fVec44[2];
	float fRec24[2];
	float fRec22[2];
	float fVec45[16384];
	float fRec85[2];
	float fVec46[2];
	float fRec84[2];
	float fRec23[2];
	float fVec47[16384];
	float fVec48[16384];
	float fRec86[2];
	float fVec49[2];
	float fRec21[2];
	float fRec20[2];
	float fRec19[3];
	float fRec18[3];
	FAUSTFLOAT fHslider8;
	float fRec17[3];
	FAUSTFLOAT fHslider9;
	float fRec92[2];
	float fRec91[3];
	float fRec90[3];
	float fVec50[2];
	float fRec89[2];
	float fRec88[3];
	float fRec87[3];
	FAUSTFLOAT fHslider10;
	float fRec95[2];
	float fRec94[3];
	float fRec93[3];
	float fVec51[1024];
	float fRec14[2];
	float fVec52[16384];
	float fVec53[16384];
	float fRec102[2];
	float fVec54[2];
	float fRec101[2];
	float fRec100[2];
	float fRec99[3];
	float fRec98[3];
	float fRec97[3];
	float fRec108[2];
	float fRec107[3];
	float fRec106[3];
	float fVec55[2];
	float fRec105[2];
	float fRec104[3];
	float fRec103[3];
	float fRec111[2];
	float fRec110[3];
	float fRec109[3];
	float fVec56[1024];
	float fRec96[2];
	float fVec57[16384];
	float fVec58[2];
	float fRec13[2];
	float fRec11[2];
	float fVec59[16384];
	float fRec113[2];
	float fVec60[2];
	float fRec112[2];
	float fRec12[2];
	float fVec61[16384];
	float fVec62[2];
	float fRec10[2];
	float fRec8[2];
	float fVec63[16384];
	float fVec64[2];
	float fRec114[2];
	float fRec9[2];
	float fVec65[16384];
	float fVec66[2];
	float fRec7[2];
	float fRec5[2];
	float fVec67[16384];
	float fRec116[2];
	float fVec68[2];
	float fRec115[2];
	float fRec6[2];
	float fVec69[16384];
	float fRec117[2];
	float fVec70[2];
	float fRec4[2];
	float fRec2[2];
	float fVec71[16384];
	float fVec72[2];
	float fRec118[2];
	float fRec3[2];
	float fRec0[2];
	float fRec1[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.1");
		m->declare("author", "Julian Parker, bug fixes by Till Bovermann");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-a /usr/share/faust/daisy/ex_faust.cpp -lang cpp -es 1 -single -ftz 0");
		m->declare("copyright", "(c) Julian Parker 2013");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "JPverbRaw.dsp");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass_plus_lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass_plus_lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass_plus_lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("license", "GPL2+");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "JPverbRaw");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.1");
		m->declare("version", "1.1");
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (6.28318548f / fConst0);
		fConst2 = (3.14159274f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.70699999999999996f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.10000000000000001f);
		fHslider3 = FAUSTFLOAT(2.0f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fHslider5 = FAUSTFLOAT(1.0f);
		fHslider6 = FAUSTFLOAT(1.0f);
		fHslider7 = FAUSTFLOAT(2000.0f);
		fHslider8 = FAUSTFLOAT(500.0f);
		fHslider9 = FAUSTFLOAT(1.0f);
		fHslider10 = FAUSTFLOAT(1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec15[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec16[l2] = 0.0f;
		}
		IOTA = 0;
		for (int l3 = 0; (l3 < 16384); l3 = (l3 + 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec53[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fVec2[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec52[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec50[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 16384); l8 = (l8 + 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec55[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fVec4[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec54[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec51[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 16384); l13 = (l13 + 1)) {
			fVec5[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec56[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fVec6[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec49[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec47[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 16384); l18 = (l18 + 1)) {
			fVec7[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec58[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fVec8[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec57[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec48[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 16384); l23 = (l23 + 1)) {
			fVec9[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec59[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fVec10[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec46[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec44[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 16384); l28 = (l28 + 1)) {
			fVec11[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec61[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fVec12[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec60[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec45[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 16384); l33 = (l33 + 1)) {
			fVec13[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec62[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fVec14[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec43[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec41[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 16384); l38 = (l38 + 1)) {
			fVec15[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec64[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fVec16[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec63[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec42[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 16384); l43 = (l43 + 1)) {
			fVec17[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec65[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fVec18[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec40[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec38[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 16384); l48 = (l48 + 1)) {
			fVec19[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec67[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fVec20[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec66[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec39[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 1024); l53 = (l53 + 1)) {
			fVec21[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 16384); l54 = (l54 + 1)) {
			fVec22[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec68[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fVec23[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec37[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 1024); l58 = (l58 + 1)) {
			fVec24[l58] = 0.0f;
		}
		for (int l59 = 0; (l59 < 16384); l59 = (l59 + 1)) {
			fVec25[l59] = 0.0f;
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec70[l60] = 0.0f;
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fVec26[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec69[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 16384); l63 = (l63 + 1)) {
			fVec27[l63] = 0.0f;
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec71[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fVec28[l65] = 0.0f;
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec36[l66] = 0.0f;
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec34[l67] = 0.0f;
		}
		for (int l68 = 0; (l68 < 16384); l68 = (l68 + 1)) {
			fVec29[l68] = 0.0f;
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec73[l69] = 0.0f;
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fVec30[l70] = 0.0f;
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec72[l71] = 0.0f;
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec35[l72] = 0.0f;
		}
		for (int l73 = 0; (l73 < 16384); l73 = (l73 + 1)) {
			fVec31[l73] = 0.0f;
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec74[l74] = 0.0f;
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fVec32[l75] = 0.0f;
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec33[l76] = 0.0f;
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec31[l77] = 0.0f;
		}
		for (int l78 = 0; (l78 < 16384); l78 = (l78 + 1)) {
			fVec33[l78] = 0.0f;
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec76[l79] = 0.0f;
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fVec34[l80] = 0.0f;
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec75[l81] = 0.0f;
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec32[l82] = 0.0f;
		}
		for (int l83 = 0; (l83 < 16384); l83 = (l83 + 1)) {
			fVec35[l83] = 0.0f;
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec77[l84] = 0.0f;
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fVec36[l85] = 0.0f;
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec30[l86] = 0.0f;
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec28[l87] = 0.0f;
		}
		for (int l88 = 0; (l88 < 16384); l88 = (l88 + 1)) {
			fVec37[l88] = 0.0f;
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec79[l89] = 0.0f;
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fVec38[l90] = 0.0f;
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec78[l91] = 0.0f;
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec29[l92] = 0.0f;
		}
		for (int l93 = 0; (l93 < 16384); l93 = (l93 + 1)) {
			fVec39[l93] = 0.0f;
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec80[l94] = 0.0f;
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fVec40[l95] = 0.0f;
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec27[l96] = 0.0f;
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec25[l97] = 0.0f;
		}
		for (int l98 = 0; (l98 < 16384); l98 = (l98 + 1)) {
			fVec41[l98] = 0.0f;
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec82[l99] = 0.0f;
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fVec42[l100] = 0.0f;
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec81[l101] = 0.0f;
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec26[l102] = 0.0f;
		}
		for (int l103 = 0; (l103 < 16384); l103 = (l103 + 1)) {
			fVec43[l103] = 0.0f;
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec83[l104] = 0.0f;
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fVec44[l105] = 0.0f;
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec24[l106] = 0.0f;
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec22[l107] = 0.0f;
		}
		for (int l108 = 0; (l108 < 16384); l108 = (l108 + 1)) {
			fVec45[l108] = 0.0f;
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec85[l109] = 0.0f;
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fVec46[l110] = 0.0f;
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec84[l111] = 0.0f;
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec23[l112] = 0.0f;
		}
		for (int l113 = 0; (l113 < 16384); l113 = (l113 + 1)) {
			fVec47[l113] = 0.0f;
		}
		for (int l114 = 0; (l114 < 16384); l114 = (l114 + 1)) {
			fVec48[l114] = 0.0f;
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec86[l115] = 0.0f;
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fVec49[l116] = 0.0f;
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec21[l117] = 0.0f;
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec20[l118] = 0.0f;
		}
		for (int l119 = 0; (l119 < 3); l119 = (l119 + 1)) {
			fRec19[l119] = 0.0f;
		}
		for (int l120 = 0; (l120 < 3); l120 = (l120 + 1)) {
			fRec18[l120] = 0.0f;
		}
		for (int l121 = 0; (l121 < 3); l121 = (l121 + 1)) {
			fRec17[l121] = 0.0f;
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec92[l122] = 0.0f;
		}
		for (int l123 = 0; (l123 < 3); l123 = (l123 + 1)) {
			fRec91[l123] = 0.0f;
		}
		for (int l124 = 0; (l124 < 3); l124 = (l124 + 1)) {
			fRec90[l124] = 0.0f;
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fVec50[l125] = 0.0f;
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec89[l126] = 0.0f;
		}
		for (int l127 = 0; (l127 < 3); l127 = (l127 + 1)) {
			fRec88[l127] = 0.0f;
		}
		for (int l128 = 0; (l128 < 3); l128 = (l128 + 1)) {
			fRec87[l128] = 0.0f;
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec95[l129] = 0.0f;
		}
		for (int l130 = 0; (l130 < 3); l130 = (l130 + 1)) {
			fRec94[l130] = 0.0f;
		}
		for (int l131 = 0; (l131 < 3); l131 = (l131 + 1)) {
			fRec93[l131] = 0.0f;
		}
		for (int l132 = 0; (l132 < 1024); l132 = (l132 + 1)) {
			fVec51[l132] = 0.0f;
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec14[l133] = 0.0f;
		}
		for (int l134 = 0; (l134 < 16384); l134 = (l134 + 1)) {
			fVec52[l134] = 0.0f;
		}
		for (int l135 = 0; (l135 < 16384); l135 = (l135 + 1)) {
			fVec53[l135] = 0.0f;
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec102[l136] = 0.0f;
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fVec54[l137] = 0.0f;
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec101[l138] = 0.0f;
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec100[l139] = 0.0f;
		}
		for (int l140 = 0; (l140 < 3); l140 = (l140 + 1)) {
			fRec99[l140] = 0.0f;
		}
		for (int l141 = 0; (l141 < 3); l141 = (l141 + 1)) {
			fRec98[l141] = 0.0f;
		}
		for (int l142 = 0; (l142 < 3); l142 = (l142 + 1)) {
			fRec97[l142] = 0.0f;
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec108[l143] = 0.0f;
		}
		for (int l144 = 0; (l144 < 3); l144 = (l144 + 1)) {
			fRec107[l144] = 0.0f;
		}
		for (int l145 = 0; (l145 < 3); l145 = (l145 + 1)) {
			fRec106[l145] = 0.0f;
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fVec55[l146] = 0.0f;
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec105[l147] = 0.0f;
		}
		for (int l148 = 0; (l148 < 3); l148 = (l148 + 1)) {
			fRec104[l148] = 0.0f;
		}
		for (int l149 = 0; (l149 < 3); l149 = (l149 + 1)) {
			fRec103[l149] = 0.0f;
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec111[l150] = 0.0f;
		}
		for (int l151 = 0; (l151 < 3); l151 = (l151 + 1)) {
			fRec110[l151] = 0.0f;
		}
		for (int l152 = 0; (l152 < 3); l152 = (l152 + 1)) {
			fRec109[l152] = 0.0f;
		}
		for (int l153 = 0; (l153 < 1024); l153 = (l153 + 1)) {
			fVec56[l153] = 0.0f;
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec96[l154] = 0.0f;
		}
		for (int l155 = 0; (l155 < 16384); l155 = (l155 + 1)) {
			fVec57[l155] = 0.0f;
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fVec58[l156] = 0.0f;
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec13[l157] = 0.0f;
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec11[l158] = 0.0f;
		}
		for (int l159 = 0; (l159 < 16384); l159 = (l159 + 1)) {
			fVec59[l159] = 0.0f;
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec113[l160] = 0.0f;
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fVec60[l161] = 0.0f;
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec112[l162] = 0.0f;
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec12[l163] = 0.0f;
		}
		for (int l164 = 0; (l164 < 16384); l164 = (l164 + 1)) {
			fVec61[l164] = 0.0f;
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fVec62[l165] = 0.0f;
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec10[l166] = 0.0f;
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec8[l167] = 0.0f;
		}
		for (int l168 = 0; (l168 < 16384); l168 = (l168 + 1)) {
			fVec63[l168] = 0.0f;
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fVec64[l169] = 0.0f;
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec114[l170] = 0.0f;
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec9[l171] = 0.0f;
		}
		for (int l172 = 0; (l172 < 16384); l172 = (l172 + 1)) {
			fVec65[l172] = 0.0f;
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fVec66[l173] = 0.0f;
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec7[l174] = 0.0f;
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec5[l175] = 0.0f;
		}
		for (int l176 = 0; (l176 < 16384); l176 = (l176 + 1)) {
			fVec67[l176] = 0.0f;
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec116[l177] = 0.0f;
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fVec68[l178] = 0.0f;
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec115[l179] = 0.0f;
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec6[l180] = 0.0f;
		}
		for (int l181 = 0; (l181 < 16384); l181 = (l181 + 1)) {
			fVec69[l181] = 0.0f;
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec117[l182] = 0.0f;
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fVec70[l183] = 0.0f;
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec4[l184] = 0.0f;
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec2[l185] = 0.0f;
		}
		for (int l186 = 0; (l186 < 16384); l186 = (l186 + 1)) {
			fVec71[l186] = 0.0f;
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fVec72[l187] = 0.0f;
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec118[l188] = 0.0f;
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec3[l189] = 0.0f;
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec0[l190] = 0.0f;
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec1[l191] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("JPverbRaw");
		ui_interface->addHorizontalSlider("damp", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.999000013f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("earlyDiff", &fHslider0, FAUSTFLOAT(0.707000017f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.99000001f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("highBand", &fHslider7, FAUSTFLOAT(2000.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(10000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("highX", &fHslider6, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("lowBand", &fHslider8, FAUSTFLOAT(500.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(6000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("lowX", &fHslider10, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("mDepth", &fHslider2, FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("mFreq", &fHslider3, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("midX", &fHslider9, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("size", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("t60", &fHslider5, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(60.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fHslider0);
		float fSlow1 = std::cos(fSlow0);
		float fSlow2 = float(fHslider1);
		float fSlow3 = (1.0f - fSlow2);
		float fSlow4 = (50.0f * float(fHslider2));
		float fSlow5 = (fConst1 * float(fHslider3));
		float fSlow6 = std::sin(fSlow5);
		float fSlow7 = std::cos(fSlow5);
		float fSlow8 = float(fHslider4);
		float fSlow9 = std::pow(10.0f, (0.0f - (0.50999999f * (((1.25f * fSlow8) + -0.25f) / float(fHslider5)))));
		float fSlow10 = float(fHslider6);
		float fSlow11 = std::tan((fConst2 * float(fHslider7)));
		float fSlow12 = (1.0f / fSlow11);
		float fSlow13 = (((fSlow12 + 0.618034005f) / fSlow11) + 1.0f);
		float fSlow14 = (1.0f / fSlow13);
		float fSlow15 = mydsp_faustpower2_f(fSlow11);
		float fSlow16 = (1.0f / fSlow15);
		float fSlow17 = (1.0f / (((fSlow12 + 1.61803401f) / fSlow11) + 1.0f));
		float fSlow18 = (fSlow12 + 1.0f);
		float fSlow19 = (0.0f - (1.0f / (fSlow11 * fSlow18)));
		int iSlow20 = int(primes(int((10.0f * fSlow8))));
		float fSlow21 = (9.99999975e-05f * float(iSlow20));
		int iSlow22 = int(primes(int((110.0f * fSlow8))));
		float fSlow23 = (9.99999975e-05f * float(iSlow22));
		int iSlow24 = int(primes(int((40.0f * fSlow8))));
		float fSlow25 = (9.99999975e-05f * float(iSlow24));
		int iSlow26 = int(primes(int((140.0f * fSlow8))));
		float fSlow27 = (9.99999975e-05f * float(iSlow26));
		int iSlow28 = int(primes(int((70.0f * fSlow8))));
		float fSlow29 = (9.99999975e-05f * float(iSlow28));
		int iSlow30 = int(primes(int((170.0f * fSlow8))));
		float fSlow31 = (9.99999975e-05f * float(iSlow30));
		int iSlow32 = int(primes(int((100.0f * fSlow8))));
		float fSlow33 = (9.99999975e-05f * float(iSlow32));
		int iSlow34 = int(primes(int((200.0f * fSlow8))));
		float fSlow35 = (9.99999975e-05f * float(iSlow34));
		int iSlow36 = int(primes(int((130.0f * fSlow8))));
		float fSlow37 = (9.99999975e-05f * float(iSlow36));
		int iSlow38 = int(primes(int((230.0f * fSlow8))));
		float fSlow39 = (9.99999975e-05f * float(iSlow38));
		int iSlow40 = int(primes(int((54.0f * fSlow8))));
		float fSlow41 = (0.00499999989f * float(iSlow40));
		float fSlow42 = (0.0f - fSlow4);
		int iSlow43 = int(primes(int((204.0f * fSlow8))));
		float fSlow44 = (0.00499999989f * float(iSlow43));
		int iSlow45 = int(primes(int((125.0f * fSlow8))));
		float fSlow46 = (9.99999975e-05f * float(iSlow45));
		int iSlow47 = int(primes(int((25.0f * fSlow8))));
		float fSlow48 = (9.99999975e-05f * float(iSlow47));
		int iSlow49 = int(primes(int((155.0f * fSlow8))));
		float fSlow50 = (9.99999975e-05f * float(iSlow49));
		int iSlow51 = int(primes(int((55.0f * fSlow8))));
		float fSlow52 = (9.99999975e-05f * float(iSlow51));
		int iSlow53 = int(primes(int((185.0f * fSlow8))));
		float fSlow54 = (9.99999975e-05f * float(iSlow53));
		int iSlow55 = int(primes(int((85.0f * fSlow8))));
		float fSlow56 = (9.99999975e-05f * float(iSlow55));
		int iSlow57 = int(primes(int((215.0f * fSlow8))));
		float fSlow58 = (9.99999975e-05f * float(iSlow57));
		int iSlow59 = int(primes(int((115.0f * fSlow8))));
		float fSlow60 = (9.99999975e-05f * float(iSlow59));
		int iSlow61 = int(primes(int((245.0f * fSlow8))));
		float fSlow62 = (9.99999975e-05f * float(iSlow61));
		int iSlow63 = int(primes(int((145.0f * fSlow8))));
		float fSlow64 = (9.99999975e-05f * float(iSlow63));
		int iSlow65 = int(primes(int((134.0f * fSlow8))));
		float fSlow66 = (0.00499999989f * float(iSlow65));
		float fSlow67 = (1.0f / fSlow18);
		float fSlow68 = (1.0f - fSlow12);
		float fSlow69 = (((fSlow12 + -1.61803401f) / fSlow11) + 1.0f);
		float fSlow70 = (2.0f * (1.0f - fSlow16));
		float fSlow71 = (0.0f - (2.0f / fSlow15));
		float fSlow72 = (((fSlow12 + -0.618034005f) / fSlow11) + 1.0f);
		float fSlow73 = std::tan((fConst2 * float(fHslider8)));
		float fSlow74 = (1.0f / fSlow73);
		float fSlow75 = (1.0f / (((fSlow74 + 1.61803401f) / fSlow73) + 1.0f));
		float fSlow76 = (((fSlow74 + -1.61803401f) / fSlow73) + 1.0f);
		float fSlow77 = mydsp_faustpower2_f(fSlow73);
		float fSlow78 = (1.0f / fSlow77);
		float fSlow79 = (2.0f * (1.0f - fSlow78));
		float fSlow80 = (1.0f / (((fSlow74 + 0.618034005f) / fSlow73) + 1.0f));
		float fSlow81 = float(fHslider9);
		float fSlow82 = (1.0f / (((fSlow74 + 1.61803401f) / fSlow73) + 1.0f));
		float fSlow83 = (fSlow74 + 1.0f);
		float fSlow84 = (0.0f - (1.0f / (fSlow73 * fSlow83)));
		float fSlow85 = (1.0f / fSlow83);
		float fSlow86 = (1.0f - fSlow74);
		float fSlow87 = (1.0f / (fSlow73 * fSlow13));
		float fSlow88 = (((fSlow74 + -1.61803401f) / fSlow73) + 1.0f);
		float fSlow89 = (0.0f - (2.0f / fSlow77));
		float fSlow90 = (((fSlow74 + -0.618034005f) / fSlow73) + 1.0f);
		float fSlow91 = float(fHslider10);
		float fSlow92 = std::sin(fSlow0);
		int iSlow93 = int(primes(int((34.0f * fSlow8))));
		float fSlow94 = (0.00499999989f * float(iSlow93));
		int iSlow95 = int(primes(int((240.0f * fSlow8))));
		float fSlow96 = (9.99999975e-05f * float(iSlow95));
		int iSlow97 = int(primes(int((190.0f * fSlow8))));
		float fSlow98 = (9.99999975e-05f * float(iSlow97));
		int iSlow99 = int(primes(int((175.0f * fSlow8))));
		float fSlow100 = (9.99999975e-05f * float(iSlow99));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iVec0[0] = 1;
			fRec15[0] = ((fSlow6 * fRec16[1]) + (fSlow7 * fRec15[1]));
			int iTemp0 = (1 - iVec0[1]);
			fRec16[0] = ((float(iTemp0) + (fSlow7 * fRec16[1])) - (fSlow6 * fRec15[1]));
			float fTemp1 = (fSlow4 * (fRec15[0] + 1.0f));
			float fTemp2 = (fTemp1 + 3.50000501f);
			float fTemp3 = std::floor(fTemp2);
			float fTemp4 = (fTemp1 + (4.0f - fTemp3));
			float fTemp5 = (0.0f - fTemp4);
			float fTemp6 = (fTemp1 + (3.0f - fTemp3));
			float fTemp7 = (0.0f - (0.5f * fTemp6));
			float fTemp8 = (fTemp1 + (2.0f - fTemp3));
			float fTemp9 = (0.0f - (0.333333343f * fTemp8));
			float fTemp10 = (fTemp1 + (1.0f - fTemp3));
			float fTemp11 = (0.0f - (0.25f * fTemp10));
			float fTemp12 = ((0.760313988f * fRec0[1]) - (0.649555743f * fRec50[1]));
			float fTemp13 = ((0.760313988f * fRec1[1]) - (0.649555743f * fRec51[1]));
			fVec1[(IOTA & 16383)] = ((0.707106769f * fTemp12) - (0.707106769f * fTemp13));
			fRec53[0] = (fSlow21 + (0.999899983f * (fRec53[1] + float((iSlow20 * iTemp0)))));
			float fTemp14 = (fRec53[0] + -1.49998999f);
			float fTemp15 = fVec1[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp14)))) & 16383)];
			fVec2[0] = fTemp15;
			float fTemp16 = std::floor(fTemp14);
			fRec52[0] = (fVec2[1] - (((fTemp16 + (2.0f - fRec53[0])) * (fRec52[1] - fTemp15)) / (fRec53[0] - fTemp16)));
			fRec50[0] = fRec52[0];
			fVec3[(IOTA & 16383)] = ((0.707106769f * fTemp12) + (0.707106769f * fTemp13));
			fRec55[0] = (fSlow23 + (0.999899983f * (fRec55[1] + float((iSlow22 * iTemp0)))));
			float fTemp17 = (fRec55[0] + -1.49998999f);
			float fTemp18 = fVec3[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp17)))) & 16383)];
			fVec4[0] = fTemp18;
			float fTemp19 = std::floor(fTemp17);
			fRec54[0] = (fVec4[1] - (((fTemp19 + (2.0f - fRec55[0])) * (fRec54[1] - fTemp18)) / (fRec55[0] - fTemp19)));
			fRec51[0] = fRec54[0];
			float fTemp20 = ((0.760313988f * fRec50[1]) + (0.649555743f * fRec0[1]));
			float fTemp21 = ((0.760313988f * fTemp20) - (0.649555743f * fRec47[1]));
			float fTemp22 = ((0.760313988f * fRec51[1]) + (0.649555743f * fRec1[1]));
			float fTemp23 = ((0.760313988f * fTemp22) - (0.649555743f * fRec48[1]));
			fVec5[(IOTA & 16383)] = ((0.707106769f * fTemp21) - (0.707106769f * fTemp23));
			fRec56[0] = (fSlow25 + (0.999899983f * (fRec56[1] + float((iSlow24 * iTemp0)))));
			float fTemp24 = (fRec56[0] + -1.49998999f);
			float fTemp25 = fVec5[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp24)))) & 16383)];
			fVec6[0] = fTemp25;
			float fTemp26 = std::floor(fTemp24);
			fRec49[0] = (fVec6[1] - (((fTemp26 + (2.0f - fRec56[0])) * (fRec49[1] - fTemp25)) / (fRec56[0] - fTemp26)));
			fRec47[0] = fRec49[0];
			fVec7[(IOTA & 16383)] = ((0.707106769f * fTemp21) + (0.707106769f * fTemp23));
			fRec58[0] = (fSlow27 + (0.999899983f * (fRec58[1] + float((iSlow26 * iTemp0)))));
			float fTemp27 = (fRec58[0] + -1.49998999f);
			float fTemp28 = fVec7[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp27)))) & 16383)];
			fVec8[0] = fTemp28;
			float fTemp29 = std::floor(fTemp27);
			fRec57[0] = (fVec8[1] - (((fTemp29 + (2.0f - fRec58[0])) * (fRec57[1] - fTemp28)) / (fRec58[0] - fTemp29)));
			fRec48[0] = fRec57[0];
			float fTemp30 = ((0.760313988f * fRec47[1]) + (0.649555743f * fTemp20));
			float fTemp31 = ((0.760313988f * fTemp30) - (0.649555743f * fRec44[1]));
			float fTemp32 = ((0.760313988f * fRec48[1]) + (0.649555743f * fTemp22));
			float fTemp33 = ((0.760313988f * fTemp32) - (0.649555743f * fRec45[1]));
			fVec9[(IOTA & 16383)] = ((0.707106769f * fTemp31) - (0.707106769f * fTemp33));
			fRec59[0] = (fSlow29 + (0.999899983f * (fRec59[1] + float((iSlow28 * iTemp0)))));
			float fTemp34 = (fRec59[0] + -1.49998999f);
			float fTemp35 = fVec9[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp34)))) & 16383)];
			fVec10[0] = fTemp35;
			float fTemp36 = std::floor(fTemp34);
			fRec46[0] = (fVec10[1] - (((fTemp36 + (2.0f - fRec59[0])) * (fRec46[1] - fTemp35)) / (fRec59[0] - fTemp36)));
			fRec44[0] = fRec46[0];
			fVec11[(IOTA & 16383)] = ((0.707106769f * fTemp31) + (0.707106769f * fTemp33));
			fRec61[0] = (fSlow31 + (0.999899983f * (fRec61[1] + float((iSlow30 * iTemp0)))));
			float fTemp37 = (fRec61[0] + -1.49998999f);
			float fTemp38 = fVec11[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp37)))) & 16383)];
			fVec12[0] = fTemp38;
			float fTemp39 = std::floor(fTemp37);
			fRec60[0] = (fVec12[1] - (((fTemp39 + (2.0f - fRec61[0])) * (fRec60[1] - fTemp38)) / (fRec61[0] - fTemp39)));
			fRec45[0] = fRec60[0];
			float fTemp40 = ((0.760313988f * fRec44[1]) + (0.649555743f * fTemp30));
			float fTemp41 = ((0.760313988f * fTemp40) - (0.649555743f * fRec41[1]));
			float fTemp42 = ((0.760313988f * fRec45[1]) + (0.649555743f * fTemp32));
			float fTemp43 = ((0.760313988f * fTemp42) - (0.649555743f * fRec42[1]));
			fVec13[(IOTA & 16383)] = ((0.707106769f * fTemp41) - (0.707106769f * fTemp43));
			fRec62[0] = (fSlow33 + (0.999899983f * (fRec62[1] + float((iSlow32 * iTemp0)))));
			float fTemp44 = (fRec62[0] + -1.49998999f);
			float fTemp45 = fVec13[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp44)))) & 16383)];
			fVec14[0] = fTemp45;
			float fTemp46 = std::floor(fTemp44);
			fRec43[0] = (fVec14[1] - (((fTemp46 + (2.0f - fRec62[0])) * (fRec43[1] - fTemp45)) / (fRec62[0] - fTemp46)));
			fRec41[0] = fRec43[0];
			fVec15[(IOTA & 16383)] = ((0.707106769f * fTemp41) + (0.707106769f * fTemp43));
			fRec64[0] = (fSlow35 + (0.999899983f * (fRec64[1] + float((iSlow34 * iTemp0)))));
			float fTemp47 = (fRec64[0] + -1.49998999f);
			float fTemp48 = fVec15[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp47)))) & 16383)];
			fVec16[0] = fTemp48;
			float fTemp49 = std::floor(fTemp47);
			fRec63[0] = (fVec16[1] - (((fTemp49 + (2.0f - fRec64[0])) * (fRec63[1] - fTemp48)) / (fRec64[0] - fTemp49)));
			fRec42[0] = fRec63[0];
			float fTemp50 = ((0.760313988f * fRec41[1]) + (0.649555743f * fTemp40));
			float fTemp51 = ((0.760313988f * fTemp50) - (0.649555743f * fRec38[1]));
			float fTemp52 = ((0.760313988f * fRec42[1]) + (0.649555743f * fTemp42));
			float fTemp53 = ((0.760313988f * fTemp52) - (0.649555743f * fRec39[1]));
			fVec17[(IOTA & 16383)] = ((0.707106769f * fTemp51) - (0.707106769f * fTemp53));
			fRec65[0] = (fSlow37 + (0.999899983f * (fRec65[1] + float((iSlow36 * iTemp0)))));
			float fTemp54 = (fRec65[0] + -1.49998999f);
			float fTemp55 = fVec17[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp54)))) & 16383)];
			fVec18[0] = fTemp55;
			float fTemp56 = std::floor(fTemp54);
			fRec40[0] = (fVec18[1] - (((fTemp56 + (2.0f - fRec65[0])) * (fRec40[1] - fTemp55)) / (fRec65[0] - fTemp56)));
			fRec38[0] = fRec40[0];
			fVec19[(IOTA & 16383)] = ((0.707106769f * fTemp51) + (0.707106769f * fTemp53));
			fRec67[0] = (fSlow39 + (0.999899983f * (fRec67[1] + float((iSlow38 * iTemp0)))));
			float fTemp57 = (fRec67[0] + -1.49998999f);
			float fTemp58 = fVec19[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp57)))) & 16383)];
			fVec20[0] = fTemp58;
			float fTemp59 = std::floor(fTemp57);
			fRec66[0] = (fVec20[1] - (((fTemp59 + (2.0f - fRec67[0])) * (fRec66[1] - fTemp58)) / (fRec67[0] - fTemp59)));
			fRec39[0] = fRec66[0];
			float fTemp60 = ((0.760313988f * fRec38[1]) + (0.649555743f * fTemp50));
			fVec21[(IOTA & 1023)] = fTemp60;
			float fTemp61 = (fSlow4 * (fRec16[0] + 1.0f));
			float fTemp62 = (fTemp61 + 3.50000501f);
			int iTemp63 = int(fTemp62);
			int iTemp64 = std::min<int>(512, std::max<int>(0, iTemp63));
			float fTemp65 = std::floor(fTemp62);
			float fTemp66 = (fTemp61 + (4.0f - fTemp65));
			float fTemp67 = (0.0f - fTemp66);
			float fTemp68 = (fTemp61 + (3.0f - fTemp65));
			float fTemp69 = (0.0f - (0.5f * fTemp68));
			float fTemp70 = (fTemp61 + (2.0f - fTemp65));
			float fTemp71 = (0.0f - (0.333333343f * fTemp70));
			float fTemp72 = (fTemp61 + (1.0f - fTemp65));
			float fTemp73 = (0.0f - (0.25f * fTemp72));
			float fTemp74 = (fTemp61 + (5.0f - fTemp65));
			int iTemp75 = std::min<int>(512, std::max<int>(0, (iTemp63 + 1)));
			float fTemp76 = (0.0f - fTemp68);
			float fTemp77 = (0.0f - (0.5f * fTemp70));
			float fTemp78 = (0.0f - (0.333333343f * fTemp72));
			int iTemp79 = std::min<int>(512, std::max<int>(0, (iTemp63 + 2)));
			float fTemp80 = (0.0f - fTemp70);
			float fTemp81 = (0.0f - (0.5f * fTemp72));
			float fTemp82 = (fTemp66 * fTemp68);
			int iTemp83 = std::min<int>(512, std::max<int>(0, (iTemp63 + 3)));
			float fTemp84 = (0.0f - fTemp72);
			float fTemp85 = (fTemp82 * fTemp70);
			int iTemp86 = std::min<int>(512, std::max<int>(0, (iTemp63 + 4)));
			fVec22[(IOTA & 16383)] = (((((fVec21[((IOTA - iTemp64) & 1023)] * fTemp67) * fTemp69) * fTemp71) * fTemp73) + (fTemp74 * ((((((fVec21[((IOTA - iTemp75) & 1023)] * fTemp76) * fTemp77) * fTemp78) + (0.5f * (((fTemp66 * fVec21[((IOTA - iTemp79) & 1023)]) * fTemp80) * fTemp81))) + (0.166666672f * ((fTemp82 * fVec21[((IOTA - iTemp83) & 1023)]) * fTemp84))) + (0.0416666679f * (fTemp85 * fVec21[((IOTA - iTemp86) & 1023)])))));
			fRec68[0] = (fSlow41 + (0.995000005f * (fRec68[1] + float((iSlow40 * iTemp0)))));
			float fTemp87 = (fRec68[0] + -1.49998999f);
			float fTemp88 = fVec22[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp87)))) & 16383)];
			fVec23[0] = fTemp88;
			float fTemp89 = std::floor(fTemp87);
			fRec37[0] = (fVec23[1] - (((fTemp89 + (2.0f - fRec68[0])) * (fRec37[1] - fTemp88)) / (fRec68[0] - fTemp89)));
			float fTemp90 = ((0.760313988f * fRec37[0]) - (0.649555743f * fRec34[1]));
			float fTemp91 = ((0.760313988f * fRec39[1]) + (0.649555743f * fTemp52));
			fVec24[(IOTA & 1023)] = fTemp91;
			float fTemp92 = (fSlow42 * fRec16[0]);
			float fTemp93 = (fSlow4 + (fTemp92 + 3.50000501f));
			int iTemp94 = int(fTemp93);
			float fTemp95 = std::floor(fTemp93);
			float fTemp96 = (fSlow4 + (fTemp92 + (4.0f - fTemp95)));
			float fTemp97 = (fSlow4 + (fTemp92 + (3.0f - fTemp95)));
			float fTemp98 = (fSlow4 + (fTemp92 + (2.0f - fTemp95)));
			float fTemp99 = (fSlow4 + (fTemp92 + (1.0f - fTemp95)));
			float fTemp100 = (fTemp96 * fTemp97);
			fVec25[(IOTA & 16383)] = (((((fVec24[((IOTA - std::min<int>(512, std::max<int>(0, iTemp94))) & 1023)] * (0.0f - fTemp96)) * (0.0f - (0.5f * fTemp97))) * (0.0f - (0.333333343f * fTemp98))) * (0.0f - (0.25f * fTemp99))) + ((fSlow4 + (fTemp92 + (5.0f - fTemp95))) * ((((((fVec24[((IOTA - std::min<int>(512, std::max<int>(0, (iTemp94 + 1)))) & 1023)] * (0.0f - fTemp97)) * (0.0f - (0.5f * fTemp98))) * (0.0f - (0.333333343f * fTemp99))) + (0.5f * (((fTemp96 * fVec24[((IOTA - std::min<int>(512, std::max<int>(0, (iTemp94 + 2)))) & 1023)]) * (0.0f - fTemp98)) * (0.0f - (0.5f * fTemp99))))) + (0.166666672f * ((fTemp100 * fVec24[((IOTA - std::min<int>(512, std::max<int>(0, (iTemp94 + 3)))) & 1023)]) * (0.0f - fTemp99)))) + (0.0416666679f * ((fTemp100 * fTemp98) * fVec24[((IOTA - std::min<int>(512, std::max<int>(0, (iTemp94 + 4)))) & 1023)])))));
			fRec70[0] = (fSlow44 + (0.995000005f * (fRec70[1] + float((iSlow43 * iTemp0)))));
			float fTemp101 = (fRec70[0] + -1.49998999f);
			float fTemp102 = fVec25[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp101)))) & 16383)];
			fVec26[0] = fTemp102;
			float fTemp103 = std::floor(fTemp101);
			fRec69[0] = (fVec26[1] - (((fTemp103 + (2.0f - fRec70[0])) * (fRec69[1] - fTemp102)) / (fRec70[0] - fTemp103)));
			float fTemp104 = ((0.760313988f * fRec69[0]) - (0.649555743f * fRec35[1]));
			fVec27[(IOTA & 16383)] = ((0.707106769f * fTemp90) - (0.707106769f * fTemp104));
			fRec71[0] = (fSlow46 + (0.999899983f * (fRec71[1] + float((iSlow45 * iTemp0)))));
			float fTemp105 = (fRec71[0] + -1.49998999f);
			float fTemp106 = fVec27[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp105)))) & 16383)];
			fVec28[0] = fTemp106;
			float fTemp107 = std::floor(fTemp105);
			fRec36[0] = (fVec28[1] - (((fTemp107 + (2.0f - fRec71[0])) * (fRec36[1] - fTemp106)) / (fRec71[0] - fTemp107)));
			fRec34[0] = fRec36[0];
			fVec29[(IOTA & 16383)] = ((0.707106769f * fTemp90) + (0.707106769f * fTemp104));
			fRec73[0] = (fSlow48 + (0.999899983f * (fRec73[1] + float((iSlow47 * iTemp0)))));
			float fTemp108 = (fRec73[0] + -1.49998999f);
			float fTemp109 = fVec29[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp108)))) & 16383)];
			fVec30[0] = fTemp109;
			float fTemp110 = std::floor(fTemp108);
			fRec72[0] = (fVec30[1] - (((fTemp110 + (2.0f - fRec73[0])) * (fRec72[1] - fTemp109)) / (fRec73[0] - fTemp110)));
			fRec35[0] = fRec72[0];
			float fTemp111 = ((0.760313988f * fRec34[1]) + (0.649555743f * fRec37[0]));
			float fTemp112 = ((0.760313988f * fTemp111) - (0.649555743f * fRec31[1]));
			float fTemp113 = ((0.760313988f * fRec35[1]) + (0.649555743f * fRec69[0]));
			float fTemp114 = ((0.760313988f * fTemp113) - (0.649555743f * fRec32[1]));
			fVec31[(IOTA & 16383)] = ((0.707106769f * fTemp112) - (0.707106769f * fTemp114));
			fRec74[0] = (fSlow50 + (0.999899983f * (fRec74[1] + float((iSlow49 * iTemp0)))));
			float fTemp115 = (fRec74[0] + -1.49998999f);
			float fTemp116 = fVec31[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp115)))) & 16383)];
			fVec32[0] = fTemp116;
			float fTemp117 = std::floor(fTemp115);
			fRec33[0] = (fVec32[1] - (((fTemp117 + (2.0f - fRec74[0])) * (fRec33[1] - fTemp116)) / (fRec74[0] - fTemp117)));
			fRec31[0] = fRec33[0];
			fVec33[(IOTA & 16383)] = ((0.707106769f * fTemp112) + (0.707106769f * fTemp114));
			fRec76[0] = (fSlow52 + (0.999899983f * (fRec76[1] + float((iSlow51 * iTemp0)))));
			float fTemp118 = (fRec76[0] + -1.49998999f);
			int iTemp119 = std::min<int>(8192, std::max<int>(0, int(fTemp118)));
			float fTemp120 = fVec33[((IOTA - iTemp119) & 16383)];
			fVec34[0] = fTemp120;
			float fTemp121 = std::floor(fTemp118);
			float fTemp122 = (fTemp121 + (2.0f - fRec76[0]));
			float fTemp123 = (fRec76[0] - fTemp121);
			fRec75[0] = (fVec34[1] - ((fTemp122 * (fRec75[1] - fTemp120)) / fTemp123));
			fRec32[0] = fRec75[0];
			float fTemp124 = ((0.760313988f * fRec31[1]) + (0.649555743f * fTemp111));
			float fTemp125 = ((0.760313988f * fTemp124) - (0.649555743f * fRec28[1]));
			float fTemp126 = ((0.760313988f * fRec32[1]) + (0.649555743f * fTemp113));
			float fTemp127 = ((0.760313988f * fTemp126) - (0.649555743f * fRec29[1]));
			fVec35[(IOTA & 16383)] = ((0.707106769f * fTemp125) - (0.707106769f * fTemp127));
			fRec77[0] = (fSlow54 + (0.999899983f * (fRec77[1] + float((iSlow53 * iTemp0)))));
			float fTemp128 = (fRec77[0] + -1.49998999f);
			float fTemp129 = fVec35[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp128)))) & 16383)];
			fVec36[0] = fTemp129;
			float fTemp130 = std::floor(fTemp128);
			fRec30[0] = (fVec36[1] - (((fTemp130 + (2.0f - fRec77[0])) * (fRec30[1] - fTemp129)) / (fRec77[0] - fTemp130)));
			fRec28[0] = fRec30[0];
			fVec37[(IOTA & 16383)] = ((0.707106769f * fTemp125) + (0.707106769f * fTemp127));
			fRec79[0] = (fSlow56 + (0.999899983f * (fRec79[1] + float((iSlow55 * iTemp0)))));
			float fTemp131 = (fRec79[0] + -1.49998999f);
			int iTemp132 = std::min<int>(8192, std::max<int>(0, int(fTemp131)));
			float fTemp133 = fVec37[((IOTA - iTemp132) & 16383)];
			fVec38[0] = fTemp133;
			float fTemp134 = std::floor(fTemp131);
			float fTemp135 = (fTemp134 + (2.0f - fRec79[0]));
			float fTemp136 = (fRec79[0] - fTemp134);
			fRec78[0] = (fVec38[1] - ((fTemp135 * (fRec78[1] - fTemp133)) / fTemp136));
			fRec29[0] = fRec78[0];
			float fTemp137 = ((0.760313988f * fRec28[1]) + (0.649555743f * fTemp124));
			float fTemp138 = ((0.760313988f * fTemp137) - (0.649555743f * fRec25[1]));
			float fTemp139 = ((0.760313988f * fRec29[1]) + (0.649555743f * fTemp126));
			float fTemp140 = ((0.760313988f * fTemp139) - (0.649555743f * fRec26[1]));
			fVec39[(IOTA & 16383)] = ((0.707106769f * fTemp138) - (0.707106769f * fTemp140));
			fRec80[0] = (fSlow58 + (0.999899983f * (fRec80[1] + float((iSlow57 * iTemp0)))));
			float fTemp141 = (fRec80[0] + -1.49998999f);
			int iTemp142 = std::min<int>(8192, std::max<int>(0, int(fTemp141)));
			float fTemp143 = fVec39[((IOTA - iTemp142) & 16383)];
			fVec40[0] = fTemp143;
			float fTemp144 = std::floor(fTemp141);
			float fTemp145 = (fTemp144 + (2.0f - fRec80[0]));
			float fTemp146 = (fRec80[0] - fTemp144);
			fRec27[0] = (fVec40[1] - ((fTemp145 * (fRec27[1] - fTemp143)) / fTemp146));
			fRec25[0] = fRec27[0];
			fVec41[(IOTA & 16383)] = ((0.707106769f * fTemp138) + (0.707106769f * fTemp140));
			fRec82[0] = (fSlow60 + (0.999899983f * (fRec82[1] + float((iSlow59 * iTemp0)))));
			float fTemp147 = (fRec82[0] + -1.49998999f);
			int iTemp148 = std::min<int>(8192, std::max<int>(0, int(fTemp147)));
			float fTemp149 = fVec41[((IOTA - iTemp148) & 16383)];
			fVec42[0] = fTemp149;
			float fTemp150 = std::floor(fTemp147);
			float fTemp151 = (fTemp150 + (2.0f - fRec82[0]));
			float fTemp152 = (fRec82[0] - fTemp150);
			fRec81[0] = (fVec42[1] - ((fTemp151 * (fRec81[1] - fTemp149)) / fTemp152));
			fRec26[0] = fRec81[0];
			float fTemp153 = ((0.760313988f * fRec25[1]) + (0.649555743f * fTemp137));
			float fTemp154 = ((0.760313988f * fTemp153) - (0.649555743f * fRec22[1]));
			float fTemp155 = ((0.760313988f * fRec26[1]) + (0.649555743f * fTemp139));
			float fTemp156 = ((0.760313988f * fTemp155) - (0.649555743f * fRec23[1]));
			fVec43[(IOTA & 16383)] = ((0.707106769f * fTemp154) - (0.707106769f * fTemp156));
			fRec83[0] = (fSlow62 + (0.999899983f * (fRec83[1] + float((iSlow61 * iTemp0)))));
			float fTemp157 = (fRec83[0] + -1.49998999f);
			float fTemp158 = fVec43[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp157)))) & 16383)];
			fVec44[0] = fTemp158;
			float fTemp159 = std::floor(fTemp157);
			fRec24[0] = (fVec44[1] - (((fTemp159 + (2.0f - fRec83[0])) * (fRec24[1] - fTemp158)) / (fRec83[0] - fTemp159)));
			fRec22[0] = fRec24[0];
			fVec45[(IOTA & 16383)] = ((0.707106769f * fTemp154) + (0.707106769f * fTemp156));
			fRec85[0] = (fSlow64 + (0.999899983f * (fRec85[1] + float((iSlow63 * iTemp0)))));
			float fTemp160 = (fRec85[0] + -1.49998999f);
			int iTemp161 = std::min<int>(8192, std::max<int>(0, int(fTemp160)));
			float fTemp162 = fVec45[((IOTA - iTemp161) & 16383)];
			fVec46[0] = fTemp162;
			float fTemp163 = std::floor(fTemp160);
			float fTemp164 = (fTemp163 + (2.0f - fRec85[0]));
			float fTemp165 = (fRec85[0] - fTemp163);
			fRec84[0] = (fVec46[1] - ((fTemp164 * (fRec84[1] - fTemp162)) / fTemp165));
			fRec23[0] = fRec84[0];
			float fTemp166 = ((0.760313988f * fRec22[1]) + (0.649555743f * fTemp153));
			fVec47[(IOTA & 16383)] = fTemp166;
			int iTemp167 = int(fTemp2);
			int iTemp168 = std::max<int>(0, iTemp167);
			float fTemp169 = (fTemp1 + (5.0f - fTemp3));
			int iTemp170 = std::max<int>(0, (iTemp167 + 1));
			float fTemp171 = (0.0f - fTemp6);
			float fTemp172 = (0.0f - (0.5f * fTemp8));
			float fTemp173 = (0.0f - (0.333333343f * fTemp10));
			int iTemp174 = std::max<int>(0, (iTemp167 + 2));
			float fTemp175 = (0.0f - fTemp8);
			float fTemp176 = (0.0f - (0.5f * fTemp10));
			float fTemp177 = (fTemp4 * fTemp6);
			int iTemp178 = std::max<int>(0, (iTemp167 + 3));
			float fTemp179 = (0.0f - fTemp10);
			float fTemp180 = (fTemp177 * fTemp8);
			int iTemp181 = std::max<int>(0, (iTemp167 + 4));
			fVec48[(IOTA & 16383)] = (((((fVec47[((IOTA - std::min<int>(8192, iTemp168)) & 16383)] * fTemp5) * fTemp7) * fTemp9) * fTemp11) + (fTemp169 * ((((((fVec47[((IOTA - std::min<int>(8192, iTemp170)) & 16383)] * fTemp171) * fTemp172) * fTemp173) + (0.5f * (((fTemp4 * fVec47[((IOTA - std::min<int>(8192, iTemp174)) & 16383)]) * fTemp175) * fTemp176))) + (0.166666672f * ((fTemp177 * fVec47[((IOTA - std::min<int>(8192, iTemp178)) & 16383)]) * fTemp179))) + (0.0416666679f * (fTemp180 * fVec47[((IOTA - std::min<int>(8192, iTemp181)) & 16383)])))));
			fRec86[0] = (fSlow66 + (0.995000005f * (fRec86[1] + float((iSlow65 * iTemp0)))));
			float fTemp182 = (fRec86[0] + -1.49998999f);
			float fTemp183 = fVec48[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp182)))) & 16383)];
			fVec49[0] = fTemp183;
			float fTemp184 = std::floor(fTemp182);
			fRec21[0] = (fVec49[1] - (((fTemp184 + (2.0f - fRec86[0])) * (fRec21[1] - fTemp183)) / (fRec86[0] - fTemp184)));
			fRec20[0] = ((fSlow19 * fRec21[1]) - (fSlow67 * ((fSlow68 * fRec20[1]) - (fSlow12 * fRec21[0]))));
			fRec19[0] = (fRec20[0] - (fSlow17 * ((fSlow69 * fRec19[2]) + (fSlow70 * fRec19[1]))));
			fRec18[0] = ((fSlow17 * (((fSlow16 * fRec19[0]) + (fSlow71 * fRec19[1])) + (fSlow16 * fRec19[2]))) - (fSlow14 * ((fSlow72 * fRec18[2]) + (fSlow70 * fRec18[1]))));
			float fTemp185 = (fSlow79 * fRec17[1]);
			fRec17[0] = ((fSlow14 * (((fSlow16 * fRec18[0]) + (fSlow71 * fRec18[1])) + (fSlow16 * fRec18[2]))) - (fSlow75 * ((fSlow76 * fRec17[2]) + fTemp185)));
			fRec92[0] = (0.0f - (fSlow67 * ((fSlow68 * fRec92[1]) - (fRec21[0] + fRec21[1]))));
			fRec91[0] = (fRec92[0] - (fSlow17 * ((fSlow69 * fRec91[2]) + (fSlow70 * fRec91[1]))));
			fRec90[0] = ((fSlow17 * (fRec91[2] + (fRec91[0] + (2.0f * fRec91[1])))) - (fSlow14 * ((fSlow72 * fRec90[2]) + (fSlow70 * fRec90[1]))));
			float fTemp186 = (fRec90[2] + (fRec90[0] + (2.0f * fRec90[1])));
			float fTemp187 = (fSlow14 * fTemp186);
			fVec50[0] = fTemp187;
			fRec89[0] = ((fSlow84 * fVec50[1]) - (fSlow85 * ((fSlow86 * fRec89[1]) - (fSlow87 * fTemp186))));
			fRec88[0] = (fRec89[0] - (fSlow82 * ((fSlow88 * fRec88[2]) + (fSlow79 * fRec88[1]))));
			fRec87[0] = ((fSlow82 * (((fSlow78 * fRec88[0]) + (fSlow89 * fRec88[1])) + (fSlow78 * fRec88[2]))) - (fSlow80 * ((fSlow90 * fRec87[2]) + (fSlow79 * fRec87[1]))));
			fRec95[0] = (0.0f - (fSlow85 * ((fSlow86 * fRec95[1]) - (fTemp187 + fVec50[1]))));
			fRec94[0] = (fRec95[0] - (fSlow82 * ((fSlow88 * fRec94[2]) + (fSlow79 * fRec94[1]))));
			fRec93[0] = ((fSlow82 * (fRec94[2] + (fRec94[0] + (2.0f * fRec94[1])))) - (fSlow80 * ((fSlow90 * fRec93[2]) + (fSlow79 * fRec93[1]))));
			float fTemp188 = (float(input0[i0]) + (fSlow9 * ((fSlow10 * (fRec17[2] + (fSlow75 * (fTemp185 + (fSlow76 * fRec17[0]))))) + (fSlow80 * ((fSlow81 * (((fSlow78 * fRec87[0]) + (fSlow89 * fRec87[1])) + (fSlow78 * fRec87[2]))) + (fSlow91 * (fRec93[2] + (fRec93[0] + (2.0f * fRec93[1])))))))));
			fVec51[(IOTA & 1023)] = fTemp188;
			fRec14[0] = ((fSlow2 * fRec14[1]) + (fSlow3 * (((((fTemp5 * fTemp7) * fTemp9) * fTemp11) * fVec51[((IOTA - std::min<int>(512, iTemp168)) & 1023)]) + (fTemp169 * ((((((fTemp171 * fTemp172) * fTemp173) * fVec51[((IOTA - std::min<int>(512, iTemp170)) & 1023)]) + (0.5f * (((fTemp4 * fTemp175) * fTemp176) * fVec51[((IOTA - std::min<int>(512, iTemp174)) & 1023)]))) + (0.166666672f * ((fTemp177 * fTemp179) * fVec51[((IOTA - std::min<int>(512, iTemp178)) & 1023)]))) + (0.0416666679f * (fTemp180 * fVec51[((IOTA - std::min<int>(512, iTemp181)) & 1023)])))))));
			float fTemp189 = ((fSlow1 * fRec14[0]) - (fSlow92 * fRec11[1]));
			float fTemp190 = ((0.760313988f * fRec23[1]) + (0.649555743f * fTemp155));
			fVec52[(IOTA & 16383)] = fTemp190;
			float fTemp191 = (fSlow42 * fRec15[0]);
			float fTemp192 = (fSlow4 + (fTemp191 + 3.50000501f));
			int iTemp193 = int(fTemp192);
			float fTemp194 = std::floor(fTemp192);
			float fTemp195 = (fSlow4 + (fTemp191 + (4.0f - fTemp194)));
			float fTemp196 = (fSlow4 + (fTemp191 + (3.0f - fTemp194)));
			float fTemp197 = (fSlow4 + (fTemp191 + (2.0f - fTemp194)));
			float fTemp198 = (fSlow4 + (fTemp191 + (1.0f - fTemp194)));
			float fTemp199 = (fTemp195 * fTemp196);
			fVec53[(IOTA & 16383)] = (((((fVec52[((IOTA - std::min<int>(8192, std::max<int>(0, iTemp193))) & 16383)] * (0.0f - fTemp195)) * (0.0f - (0.5f * fTemp196))) * (0.0f - (0.333333343f * fTemp197))) * (0.0f - (0.25f * fTemp198))) + ((fSlow4 + (fTemp191 + (5.0f - fTemp194))) * ((((((fVec52[((IOTA - std::min<int>(8192, std::max<int>(0, (iTemp193 + 1)))) & 16383)] * (0.0f - fTemp196)) * (0.0f - (0.5f * fTemp197))) * (0.0f - (0.333333343f * fTemp198))) + (0.5f * (((fTemp195 * fVec52[((IOTA - std::min<int>(8192, std::max<int>(0, (iTemp193 + 2)))) & 16383)]) * (0.0f - fTemp197)) * (0.0f - (0.5f * fTemp198))))) + (0.166666672f * ((fTemp199 * fVec52[((IOTA - std::min<int>(8192, std::max<int>(0, (iTemp193 + 3)))) & 16383)]) * (0.0f - fTemp198)))) + (0.0416666679f * ((fTemp199 * fTemp197) * fVec52[((IOTA - std::min<int>(8192, std::max<int>(0, (iTemp193 + 4)))) & 16383)])))));
			fRec102[0] = (fSlow94 + (0.995000005f * (fRec102[1] + float((iSlow93 * iTemp0)))));
			float fTemp200 = (fRec102[0] + -1.49998999f);
			float fTemp201 = fVec53[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp200)))) & 16383)];
			fVec54[0] = fTemp201;
			float fTemp202 = std::floor(fTemp200);
			fRec101[0] = (fVec54[1] - (((fTemp202 + (2.0f - fRec102[0])) * (fRec101[1] - fTemp201)) / (fRec102[0] - fTemp202)));
			fRec100[0] = ((fSlow19 * fRec101[1]) - (fSlow67 * ((fSlow68 * fRec100[1]) - (fSlow12 * fRec101[0]))));
			fRec99[0] = (fRec100[0] - (fSlow17 * ((fSlow69 * fRec99[2]) + (fSlow70 * fRec99[1]))));
			fRec98[0] = ((fSlow17 * (((fSlow16 * fRec99[0]) + (fSlow71 * fRec99[1])) + (fSlow16 * fRec99[2]))) - (fSlow14 * ((fSlow72 * fRec98[2]) + (fSlow70 * fRec98[1]))));
			float fTemp203 = (fSlow79 * fRec97[1]);
			fRec97[0] = ((fSlow14 * (((fSlow16 * fRec98[0]) + (fSlow71 * fRec98[1])) + (fSlow16 * fRec98[2]))) - (fSlow75 * ((fSlow76 * fRec97[2]) + fTemp203)));
			fRec108[0] = (0.0f - (fSlow67 * ((fSlow68 * fRec108[1]) - (fRec101[0] + fRec101[1]))));
			fRec107[0] = (fRec108[0] - (fSlow17 * ((fSlow69 * fRec107[2]) + (fSlow70 * fRec107[1]))));
			fRec106[0] = ((fSlow17 * (fRec107[2] + (fRec107[0] + (2.0f * fRec107[1])))) - (fSlow14 * ((fSlow72 * fRec106[2]) + (fSlow70 * fRec106[1]))));
			float fTemp204 = (fRec106[2] + (fRec106[0] + (2.0f * fRec106[1])));
			float fTemp205 = (fSlow14 * fTemp204);
			fVec55[0] = fTemp205;
			fRec105[0] = ((fSlow84 * fVec55[1]) - (fSlow85 * ((fSlow86 * fRec105[1]) - (fSlow87 * fTemp204))));
			fRec104[0] = (fRec105[0] - (fSlow82 * ((fSlow88 * fRec104[2]) + (fSlow79 * fRec104[1]))));
			fRec103[0] = ((fSlow82 * (((fSlow78 * fRec104[0]) + (fSlow89 * fRec104[1])) + (fSlow78 * fRec104[2]))) - (fSlow80 * ((fSlow90 * fRec103[2]) + (fSlow79 * fRec103[1]))));
			fRec111[0] = (0.0f - (fSlow85 * ((fSlow86 * fRec111[1]) - (fTemp205 + fVec55[1]))));
			fRec110[0] = (fRec111[0] - (fSlow82 * ((fSlow88 * fRec110[2]) + (fSlow79 * fRec110[1]))));
			fRec109[0] = ((fSlow82 * (fRec110[2] + (fRec110[0] + (2.0f * fRec110[1])))) - (fSlow80 * ((fSlow90 * fRec109[2]) + (fSlow79 * fRec109[1]))));
			float fTemp206 = (float(input1[i0]) + (fSlow9 * ((fSlow10 * (fRec97[2] + (fSlow75 * (fTemp203 + (fSlow76 * fRec97[0]))))) + (fSlow80 * ((fSlow81 * (((fSlow78 * fRec103[0]) + (fSlow89 * fRec103[1])) + (fSlow78 * fRec103[2]))) + (fSlow91 * (fRec109[2] + (fRec109[0] + (2.0f * fRec109[1])))))))));
			fVec56[(IOTA & 1023)] = fTemp206;
			fRec96[0] = ((fSlow2 * fRec96[1]) + (fSlow3 * (((((fTemp67 * fTemp69) * fTemp71) * fTemp73) * fVec56[((IOTA - iTemp64) & 1023)]) + (fTemp74 * ((((((fTemp76 * fTemp77) * fTemp78) * fVec56[((IOTA - iTemp75) & 1023)]) + (0.5f * (((fTemp66 * fTemp80) * fTemp81) * fVec56[((IOTA - iTemp79) & 1023)]))) + (0.166666672f * ((fTemp82 * fTemp84) * fVec56[((IOTA - iTemp83) & 1023)]))) + (0.0416666679f * (fTemp85 * fVec56[((IOTA - iTemp86) & 1023)])))))));
			float fTemp207 = ((fSlow1 * fRec96[0]) - (fSlow92 * fRec12[1]));
			fVec57[(IOTA & 16383)] = ((0.707106769f * fTemp189) - (0.707106769f * fTemp207));
			float fTemp208 = fVec57[((IOTA - iTemp119) & 16383)];
			fVec58[0] = fTemp208;
			fRec13[0] = (fVec58[1] - ((fTemp122 * (fRec13[1] - fTemp208)) / fTemp123));
			fRec11[0] = fRec13[0];
			fVec59[(IOTA & 16383)] = ((0.707106769f * fTemp189) + (0.707106769f * fTemp207));
			fRec113[0] = (fSlow96 + (0.999899983f * (fRec113[1] + float((iSlow95 * iTemp0)))));
			float fTemp209 = (fRec113[0] + -1.49998999f);
			float fTemp210 = fVec59[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp209)))) & 16383)];
			fVec60[0] = fTemp210;
			float fTemp211 = std::floor(fTemp209);
			fRec112[0] = (fVec60[1] - (((fTemp211 + (2.0f - fRec113[0])) * (fRec112[1] - fTemp210)) / (fRec113[0] - fTemp211)));
			fRec12[0] = fRec112[0];
			float fTemp212 = ((fSlow1 * fRec11[1]) + (fSlow92 * fRec14[0]));
			float fTemp213 = ((fSlow1 * fTemp212) - (fSlow92 * fRec8[1]));
			float fTemp214 = ((fSlow1 * fRec12[1]) + (fSlow92 * fRec96[0]));
			float fTemp215 = ((fSlow1 * fTemp214) - (fSlow92 * fRec9[1]));
			fVec61[(IOTA & 16383)] = ((0.707106769f * fTemp213) - (0.707106769f * fTemp215));
			float fTemp216 = fVec61[((IOTA - iTemp142) & 16383)];
			fVec62[0] = fTemp216;
			fRec10[0] = (fVec62[1] - ((fTemp145 * (fRec10[1] - fTemp216)) / fTemp146));
			fRec8[0] = fRec10[0];
			fVec63[(IOTA & 16383)] = ((0.707106769f * fTemp213) + (0.707106769f * fTemp215));
			float fTemp217 = fVec63[((IOTA - iTemp132) & 16383)];
			fVec64[0] = fTemp217;
			fRec114[0] = (fVec64[1] - ((fTemp135 * (fRec114[1] - fTemp217)) / fTemp136));
			fRec9[0] = fRec114[0];
			float fTemp218 = ((fSlow1 * fRec8[1]) + (fSlow92 * fTemp212));
			float fTemp219 = ((fSlow1 * fTemp218) - (fSlow92 * fRec5[1]));
			float fTemp220 = ((fSlow1 * fRec9[1]) + (fSlow92 * fTemp214));
			float fTemp221 = ((fSlow1 * fTemp220) - (fSlow92 * fRec6[1]));
			fVec65[(IOTA & 16383)] = ((0.707106769f * fTemp219) - (0.707106769f * fTemp221));
			float fTemp222 = fVec65[((IOTA - iTemp148) & 16383)];
			fVec66[0] = fTemp222;
			fRec7[0] = (fVec66[1] - ((fTemp151 * (fRec7[1] - fTemp222)) / fTemp152));
			fRec5[0] = fRec7[0];
			fVec67[(IOTA & 16383)] = ((0.707106769f * fTemp219) + (0.707106769f * fTemp221));
			fRec116[0] = (fSlow98 + (0.999899983f * (fRec116[1] + float((iSlow97 * iTemp0)))));
			float fTemp223 = (fRec116[0] + -1.49998999f);
			float fTemp224 = fVec67[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp223)))) & 16383)];
			fVec68[0] = fTemp224;
			float fTemp225 = std::floor(fTemp223);
			fRec115[0] = (fVec68[1] - (((fTemp225 + (2.0f - fRec116[0])) * (fRec115[1] - fTemp224)) / (fRec116[0] - fTemp225)));
			fRec6[0] = fRec115[0];
			float fTemp226 = ((fSlow1 * fRec5[1]) + (fSlow92 * fTemp218));
			float fTemp227 = ((fSlow1 * fTemp226) - (fSlow92 * fRec2[1]));
			float fTemp228 = ((fSlow1 * fRec6[1]) + (fSlow92 * fTemp220));
			float fTemp229 = ((fSlow1 * fTemp228) - (fSlow92 * fRec3[1]));
			fVec69[(IOTA & 16383)] = ((0.707106769f * fTemp227) - (0.707106769f * fTemp229));
			fRec117[0] = (fSlow100 + (0.999899983f * (fRec117[1] + float((iSlow99 * iTemp0)))));
			float fTemp230 = (fRec117[0] + -1.49998999f);
			float fTemp231 = fVec69[((IOTA - std::min<int>(8192, std::max<int>(0, int(fTemp230)))) & 16383)];
			fVec70[0] = fTemp231;
			float fTemp232 = std::floor(fTemp230);
			fRec4[0] = (fVec70[1] - (((fTemp232 + (2.0f - fRec117[0])) * (fRec4[1] - fTemp231)) / (fRec117[0] - fTemp232)));
			fRec2[0] = fRec4[0];
			fVec71[(IOTA & 16383)] = ((0.707106769f * fTemp227) + (0.707106769f * fTemp229));
			float fTemp233 = fVec71[((IOTA - iTemp161) & 16383)];
			fVec72[0] = fTemp233;
			fRec118[0] = (fVec72[1] - ((fTemp164 * (fRec118[1] - fTemp233)) / fTemp165));
			fRec3[0] = fRec118[0];
			fRec0[0] = ((fSlow1 * fRec2[1]) + (fSlow92 * fTemp226));
			fRec1[0] = ((fSlow1 * fRec3[1]) + (fSlow92 * fTemp228));
			output0[i0] = FAUSTFLOAT(fRec0[0]);
			output1[i0] = FAUSTFLOAT(fRec1[0]);
			iVec0[1] = iVec0[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			IOTA = (IOTA + 1);
			fRec53[1] = fRec53[0];
			fVec2[1] = fVec2[0];
			fRec52[1] = fRec52[0];
			fRec50[1] = fRec50[0];
			fRec55[1] = fRec55[0];
			fVec4[1] = fVec4[0];
			fRec54[1] = fRec54[0];
			fRec51[1] = fRec51[0];
			fRec56[1] = fRec56[0];
			fVec6[1] = fVec6[0];
			fRec49[1] = fRec49[0];
			fRec47[1] = fRec47[0];
			fRec58[1] = fRec58[0];
			fVec8[1] = fVec8[0];
			fRec57[1] = fRec57[0];
			fRec48[1] = fRec48[0];
			fRec59[1] = fRec59[0];
			fVec10[1] = fVec10[0];
			fRec46[1] = fRec46[0];
			fRec44[1] = fRec44[0];
			fRec61[1] = fRec61[0];
			fVec12[1] = fVec12[0];
			fRec60[1] = fRec60[0];
			fRec45[1] = fRec45[0];
			fRec62[1] = fRec62[0];
			fVec14[1] = fVec14[0];
			fRec43[1] = fRec43[0];
			fRec41[1] = fRec41[0];
			fRec64[1] = fRec64[0];
			fVec16[1] = fVec16[0];
			fRec63[1] = fRec63[0];
			fRec42[1] = fRec42[0];
			fRec65[1] = fRec65[0];
			fVec18[1] = fVec18[0];
			fRec40[1] = fRec40[0];
			fRec38[1] = fRec38[0];
			fRec67[1] = fRec67[0];
			fVec20[1] = fVec20[0];
			fRec66[1] = fRec66[0];
			fRec39[1] = fRec39[0];
			fRec68[1] = fRec68[0];
			fVec23[1] = fVec23[0];
			fRec37[1] = fRec37[0];
			fRec70[1] = fRec70[0];
			fVec26[1] = fVec26[0];
			fRec69[1] = fRec69[0];
			fRec71[1] = fRec71[0];
			fVec28[1] = fVec28[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec73[1] = fRec73[0];
			fVec30[1] = fVec30[0];
			fRec72[1] = fRec72[0];
			fRec35[1] = fRec35[0];
			fRec74[1] = fRec74[0];
			fVec32[1] = fVec32[0];
			fRec33[1] = fRec33[0];
			fRec31[1] = fRec31[0];
			fRec76[1] = fRec76[0];
			fVec34[1] = fVec34[0];
			fRec75[1] = fRec75[0];
			fRec32[1] = fRec32[0];
			fRec77[1] = fRec77[0];
			fVec36[1] = fVec36[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec79[1] = fRec79[0];
			fVec38[1] = fVec38[0];
			fRec78[1] = fRec78[0];
			fRec29[1] = fRec29[0];
			fRec80[1] = fRec80[0];
			fVec40[1] = fVec40[0];
			fRec27[1] = fRec27[0];
			fRec25[1] = fRec25[0];
			fRec82[1] = fRec82[0];
			fVec42[1] = fVec42[0];
			fRec81[1] = fRec81[0];
			fRec26[1] = fRec26[0];
			fRec83[1] = fRec83[0];
			fVec44[1] = fVec44[0];
			fRec24[1] = fRec24[0];
			fRec22[1] = fRec22[0];
			fRec85[1] = fRec85[0];
			fVec46[1] = fVec46[0];
			fRec84[1] = fRec84[0];
			fRec23[1] = fRec23[0];
			fRec86[1] = fRec86[0];
			fVec49[1] = fVec49[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec92[1] = fRec92[0];
			fRec91[2] = fRec91[1];
			fRec91[1] = fRec91[0];
			fRec90[2] = fRec90[1];
			fRec90[1] = fRec90[0];
			fVec50[1] = fVec50[0];
			fRec89[1] = fRec89[0];
			fRec88[2] = fRec88[1];
			fRec88[1] = fRec88[0];
			fRec87[2] = fRec87[1];
			fRec87[1] = fRec87[0];
			fRec95[1] = fRec95[0];
			fRec94[2] = fRec94[1];
			fRec94[1] = fRec94[0];
			fRec93[2] = fRec93[1];
			fRec93[1] = fRec93[0];
			fRec14[1] = fRec14[0];
			fRec102[1] = fRec102[0];
			fVec54[1] = fVec54[0];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fRec99[2] = fRec99[1];
			fRec99[1] = fRec99[0];
			fRec98[2] = fRec98[1];
			fRec98[1] = fRec98[0];
			fRec97[2] = fRec97[1];
			fRec97[1] = fRec97[0];
			fRec108[1] = fRec108[0];
			fRec107[2] = fRec107[1];
			fRec107[1] = fRec107[0];
			fRec106[2] = fRec106[1];
			fRec106[1] = fRec106[0];
			fVec55[1] = fVec55[0];
			fRec105[1] = fRec105[0];
			fRec104[2] = fRec104[1];
			fRec104[1] = fRec104[0];
			fRec103[2] = fRec103[1];
			fRec103[1] = fRec103[0];
			fRec111[1] = fRec111[0];
			fRec110[2] = fRec110[1];
			fRec110[1] = fRec110[0];
			fRec109[2] = fRec109[1];
			fRec109[1] = fRec109[0];
			fRec96[1] = fRec96[0];
			fVec58[1] = fVec58[0];
			fRec13[1] = fRec13[0];
			fRec11[1] = fRec11[0];
			fRec113[1] = fRec113[0];
			fVec60[1] = fVec60[0];
			fRec112[1] = fRec112[0];
			fRec12[1] = fRec12[0];
			fVec62[1] = fVec62[0];
			fRec10[1] = fRec10[0];
			fRec8[1] = fRec8[0];
			fVec64[1] = fVec64[0];
			fRec114[1] = fRec114[0];
			fRec9[1] = fRec9[0];
			fVec66[1] = fVec66[0];
			fRec7[1] = fRec7[0];
			fRec5[1] = fRec5[0];
			fRec116[1] = fRec116[0];
			fVec68[1] = fVec68[0];
			fRec115[1] = fRec115[0];
			fRec6[1] = fRec6[0];
			fRec117[1] = fRec117[0];
			fVec70[1] = fVec70[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fVec72[1] = fVec72[0];
			fRec118[1] = fRec118[0];
			fRec3[1] = fRec3[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
		}
	}

};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

#ifdef POLY
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.

 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.

 ************************************************************************
 ************************************************************************/

#ifndef __poly_dsp__
#define __poly_dsp__

#include <stdio.h>
#include <string>
#include <math.h>
#include <float.h>
#include <algorithm>
#include <ostream>
#include <sstream>
#include <vector>
#include <limits.h>

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <vector>
#include <map>
#include <string>


/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        FAUSTFLOAT getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return FAUSTFLOAT(0);
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return fPathZoneMap.size(); }
        
        std::string getParamAddress(int index)
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
};

#endif // FAUST_MAPUI_H
/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/

#ifndef __proxy_dsp__
#define __proxy_dsp__

#include <vector>
#include <map>

/************************************************************************
 ************************************************************************
 FAUST compiler
 Copyright (C) 2003-2015 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 ************************************************************************
 ************************************************************************/

#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H

// ---------------------------------------------------------------------
//                          Simple Parser
// A parser returns true if it was able to parse what it is
// supposed to parse and advance the pointer. Otherwise it returns false
// and the pointer is not advanced so that another parser can be tried.
// ---------------------------------------------------------------------

#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>

using namespace std;

struct itemInfo {
    std::string type;
    std::string label;
    std::string address;
    std::string init;
    std::string min;
    std::string max;
    std::string step;
    std::vector<std::pair<std::string, std::string> > meta;
};

bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values);
bool parseMenuItem(const char*& p, string& name, double& value);

void skipBlank(const char*& p);
bool parseChar(const char*& p, char x);
bool parseWord(const char*& p, const char* w);
bool parseString(const char*& p, char quote, string& s);
bool parseSQString(const char*& p, string& s);
bool parseDQString(const char*& p, string& s);
bool parseDouble(const char*& p, double& x);

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
inline bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values)
{
    vector<string> tmpnames;
    vector<double> tmpvalues;

    const char* saved = p;

    if (parseChar(p, '{')) {
        do {
            string n;
            double v;
            if (parseMenuItem(p, n, v)) {
                tmpnames.push_back(n);
                tmpvalues.push_back(v);
            } else {
                p = saved;
                return false;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            values = tmpvalues;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
inline bool parseMenuItem(const char*& p, string& name, double& value)
{
    const char* saved = p;
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    std::cerr << "Parse error : " << errmsg << " here : " << p << std::endl;
    return true;
}

// Parse character x, but don't report error if fails
static bool tryChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
inline void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
inline bool parseChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseWord : parse a specific string w
 * @param p the string to parse, then the remaining string
 * @param w the string to recognize
 * @return true if string w was found at the begin of p
 */
inline bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;
    while ((*w == *p) && (*w)) {++w; ++p;}
    if (*w) {
        p = saved;
        return false;
    } else {
        return true;
    }
}

/**
 * @brief parseDouble : parse number [s]dddd[.dddd] and store the result in x
 * @param p the string to parse, then the remaining string
 * @param x the float number found if any
 * @return true if a float number was found at the begin of p
 */
inline bool parseDouble(const char*& p, double& x)
{
    double sign = +1.0;    // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part

    bool valid = false;   // true if the number contains at least one digit
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail

    if (parseChar(p, '+')) {
        sign = 1.0;
    } else if (parseChar(p, '-')) {
        sign = -1.0;
    }
    while (isdigit(*p)) {
        valid = true;
        ipart = ipart*10 + (*p - '0');
        p++;
    }
    if (parseChar(p, '.')) {
        while (isdigit(*p)) {
            valid = true;
            dpart = dpart*10 + (*p - '0');
            dcoef *= 10.0;
            p++;
        }
    }
    if (valid)  {
        x = sign*(ipart + dpart/dcoef);
    } else {
        p = saved;
    }
    return valid;
}

/**
 * @brief parseString, parse an arbitrary quoted string q...q and store the result in s
 * @param p the string to parse, then the remaining string
 * @param quote the character used to quote the string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseString(const char*& p, char quote, string& s)
{
    string str;
    skipBlank(p);
 
    const char* saved = p;
    if (*p++ == quote) {
        while ((*p != 0) && (*p != quote)) {
            str += *p++;
        }
        if (*p++ == quote) {
            s = str;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseSQString, parse a single quoted string '...' and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseSQString(const char*& p, string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseDQString(const char*& p, string& s)
{
    return parseString(p, '"', s);
}

static bool parseMetaData(const char*& p, std::map<std::string, std::string>& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas[metaKey] = metaValue;
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

static bool parseItemMetaData(const char*& p, std::vector<std::pair<std::string, std::string> >& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas.push_back(std::make_pair(metaKey, metaValue));
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse metadatas of the interface:
// "name" : "...", "inputs" : "...", "outputs" : "...", ...
// and store the result as key/value
//
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, std::map<std::string, std::string>& metadatas)
{
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && parseDQString(p, value);
        }
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
//
static bool parseUI(const char*& p, std::vector<itemInfo*>& uiItems, int& numItems)
{
    if (parseChar(p, '{')) {
        
        std::string label;
        std::string value;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo* item = new itemInfo;
                        item->type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->label = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->address = value;
                    }
                }
                
                else if (label == "meta") {
                    itemInfo* item = uiItems[numItems];
                    if (!parseItemMetaData(p, item->meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->init = value;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->min = value;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->max = value;
                    }
                }
                
                else if (label == "step"){
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->step = value;
                    }
                }
                
                else if (label == "items") {
                    if (parseChar(p, ':') && parseChar(p, '[')) {
                        do { 
                            if (!parseUI(p, uiItems, numItems)) {
                                return false;
                            }
                        } while (tryChar(p, ','));
                        if (parseChar(p, ']')) {
                            itemInfo* item = new itemInfo;
                            item->type = "close";
                            uiItems.push_back(item);
                            numItems++;
                        }
                    }
                }
            } else {
                return false;
            }
            
        } while (tryChar(p, ','));
        
        return parseChar(p, '}');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse full JSON record describing a JSON/Faust interface :
// {"metadatas": "...", "ui": [{ "type": "...", "label": "...", "items": [...], "address": "...","init": "...", "min": "...", "max": "...","step": "..."}]}
//
// and store the result in map Metadatas and vector containing the items of the interface. Returns true if parsing was successfull.
//

inline bool parseJson(const char*& p, std::map<std::string, std::string>& metadatas, std::vector<itemInfo*>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        if (parseGlobalMetaData(p, key, value, metadatas)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                metadatas[key] = value;
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H

#ifdef _WIN32
#include <windows.h>
#define snprintf _snprintf
#endif

inline FAUSTFLOAT STR2REAL(const std::string& s) { return (strtod(s.c_str(), NULL)); }

//-------------------------------------------------------------------
//  Decode a dsp JSON description and implement 'buildUserInterface'
//-------------------------------------------------------------------

struct JSONUIDecoder {

    std::string fName;
    
    std::map<std::string, std::string> fMetadatas; 
    std::vector<itemInfo*> fUiItems;     
    
    FAUSTFLOAT* fInControl;
    FAUSTFLOAT* fOutControl;
    
    std::string fJSON;
    
    int fNumInputs, fNumOutputs; 
    int fInputItems, fOutputItems; 

    JSONUIDecoder(const std::string& json) 
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        parseJson(p, fMetadatas, fUiItems);
        
        // fMetadatas will contain the "meta" section as well as <name : val>, <inputs : val>, <ouputs : val> pairs
        if (fMetadatas.find("name") != fMetadatas.end()) {
            fName = fMetadatas["name"];
            fMetadatas.erase("name");
        } else {
            fName = "";
        }
         
        if (fMetadatas.find("inputs") != fMetadatas.end()) {
            fNumInputs = atoi(fMetadatas["inputs"].c_str());
            fMetadatas.erase("inputs");
        } else {
            fNumInputs = -1;
        }
        
        if (fMetadatas.find("outputs") != fMetadatas.end()) {
            fNumOutputs = atoi(fMetadatas["outputs"].c_str());
            fMetadatas.erase("outputs");
        } else {
            fNumOutputs = -1;
        }
        
        vector<itemInfo*>::iterator it;
        fInputItems = 0;
        fOutputItems = 0;
        
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            string type = (*it)->type;
            if (type == "vslider" || type == "hslider" || type == "nentry" || type == "button") {
                fInputItems++;
            } else if (type == "hbargraph" || type == "vbargraph") {
                fOutputItems++;          
            }
        }
        
        fInControl = new FAUSTFLOAT[fInputItems];
        fOutControl = new FAUSTFLOAT[fOutputItems];
    }
    
    virtual ~JSONUIDecoder() 
    {
        vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            delete(*it);
        }
        delete [] fInControl;
        delete [] fOutControl;
    }
    
    void metadata(Meta* m)
    {
        std::map<std::string, std::string>::iterator it;
        for (it = fMetadatas.begin(); it != fMetadatas.end(); it++) {
            m->declare((*it).first.c_str(), (*it).second.c_str());
        }
    }
   
    void buildUserInterface(UI* ui)
    {
        // To be sure the floats are correctly encoded
        char* tmp_local = setlocale(LC_ALL, NULL);
        setlocale(LC_ALL, "C");

        int counterIn = 0;
        int counterOut = 0;
        vector<itemInfo*>::iterator it;
        
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            
            bool isInItem = false;
            bool isOutItem = false;
            string type = (*it)->type;
            
            FAUSTFLOAT init = STR2REAL((*it)->init);
            FAUSTFLOAT min = STR2REAL((*it)->min);
            FAUSTFLOAT max = STR2REAL((*it)->max);
            FAUSTFLOAT step = STR2REAL((*it)->step);
            
            if (type == "vslider" || type == "hslider" || type == "nentry" || type == "button") {
                isInItem = true;
            } else if (type == "hbargraph" || type == "vbargraph") {
                isOutItem = true;        
            }
            
            // Meta data declaration for input items
            if ((*it)->type.find("group") == string::npos && (*it)->type.find("bargraph") == string::npos && (*it)->type != "close") {
                fInControl[counterIn] = init;
                for (int i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fInControl[counterIn], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if ((*it)->type.find("bargraph") != string::npos) {
                fOutControl[counterOut] = init;
                for (int i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fOutControl[counterOut], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (int i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(0, (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui->openHorizontalBox((*it)->label.c_str());
            } else if (type == "vgroup") { 
                ui->openVerticalBox((*it)->label.c_str());
            } else if (type == "tgroup") {
                ui->openTabBox((*it)->label.c_str());
            } else if (type == "vslider") {
                ui->addVerticalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "hslider") {
                ui->addHorizontalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);            
            } else if (type == "checkbox") {
                ui->addCheckButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "hbargraph") {
                ui->addHorizontalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "vbargraph") {
                ui->addVerticalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "nentry") {
                ui->addNumEntry((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "button") {
                ui->addButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "close") {
                ui->closeBox();
            }
                
            if (isInItem) {
                counterIn++;
            }
                
            if (isOutItem) {
                counterOut++;
            }
        }
        
        setlocale(LC_ALL, tmp_local);
    }
    
};

//----------------------------------------------------------------
//  Proxy dsp definition created from the DSP JSON description
//  This class allows a 'proxy' dsp to control a real dsp 
//  possibly running somewhere else.
//----------------------------------------------------------------

class proxy_dsp : public dsp {

    private:
    
        int fSamplingFreq;
        JSONUIDecoder* fDecoder;
        
    public:
    
        proxy_dsp(const string& json)
        {
            fDecoder = new JSONUIDecoder(json);
            fSamplingFreq = -1;
        }
          
        proxy_dsp(dsp* dsp)
        {
            JSONUI builder(dsp->getNumInputs(), dsp->getNumOutputs());
            dsp->metadata(&builder);
            dsp->buildUserInterface(&builder);
            fSamplingFreq = dsp->getSampleRate();
            fDecoder = new JSONUIDecoder(builder.JSON());
        }
      
        virtual ~proxy_dsp()
        {
            delete fDecoder;
        }
       
        virtual int getNumInputs() 	{ return fDecoder->fNumInputs; }
        virtual int getNumOutputs() { return fDecoder->fNumOutputs; }
        
        virtual void buildUserInterface(UI* ui) { fDecoder->buildUserInterface(ui); }
        
        // To possibly implement in a concrete proxy dsp 
        virtual void init(int samplingRate) { fSamplingFreq = samplingRate; }
        virtual void instanceInit(int samplingRate) {}
        virtual void instanceConstants(int samplingRate) {}
        virtual void instanceResetUserInterface() {}
        virtual void instanceClear() {}
    
        virtual int getSampleRate() { return fSamplingFreq; }
    
        virtual proxy_dsp* clone() { return new proxy_dsp(fDecoder->fJSON); }
        virtual void metadata(Meta* m) { fDecoder->metadata(m); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif

#define kActiveVoice      0
#define kFreeVoice        -1
#define kReleaseVoice     -2
#define kNoVoice          -3

#define VOICE_STOP_LEVEL  0.001
#define MIX_BUFFER_SIZE   16384

#define FLOAT_MAX(a, b) (((a) < (b)) ? (b) : (a))

// endsWith(<str>,<end>) : returns true if <str> ends with <end>

static inline bool endsWith(std::string const& str, std::string const& end)
{
    size_t l1 = str.length();
    size_t l2 = end.length();
    return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
}

static inline double midiToFreq(double note)
{
    return 440.0 * pow(2.0, (note-69.0)/12.0);
}

static inline unsigned int isPowerOfTwo(unsigned int n)
{
    return !(n & (n - 1));
}

/**
 * Allows to control zones in a grouped manner.
 */

class GroupUI : public GUI, public PathBuilder
{

    private:

        std::map<std::string, uiGroupItem*> fLabelZoneMap;

        void insertMap(std::string label, FAUSTFLOAT* zone)
        {
            if (!endsWith(label, "/gate")
                && !endsWith(label, "/freq")
                && !endsWith(label, "/gain")) {

                // Groups all controller except 'freq', 'gate', and 'gain'
                if (fLabelZoneMap.find(label) != fLabelZoneMap.end()) {
                    fLabelZoneMap[label]->addZone(zone);
                } else {
                    fLabelZoneMap[label] = new uiGroupItem(this, zone);
                }
            }
        }

        uiCallbackItem* fPanic;

    public:

        GroupUI(FAUSTFLOAT* zone, uiCallback cb, void* arg)
        {
            fPanic = new uiCallbackItem(this, zone, cb, arg);
        };
        virtual ~GroupUI()
        {
            // 'fPanic' is kept and deleted in GUI, so do not delete here
        };

        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }

        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }

        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }

};

/**
 * One voice of polyphony.
 */

struct dsp_voice : public MapUI, public decorator_dsp {

    int fNote;              // Playing note actual pitch
    int fDate;              // KeyOn date
    bool fTrigger;          // True if stolen note and need for envelop trigger
    FAUSTFLOAT fLevel;      // Last audio block level
    std::string fGatePath;  // Path of 'gate' control
    std::string fGainPath;  // Path of 'gain' control
    std::string fFreqPath;  // Path of 'freq' control

    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        dsp->buildUserInterface(this);
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        fTrigger = false;
        extractPaths(fGatePath, fFreqPath, fGainPath);
    }

    void extractPaths(std::string& gate, std::string& freq, std::string& gain)
    {
        // Keep gain, freq and gate labels
        std::map<std::string, FAUSTFLOAT*>::iterator it;
        for (it = getMap().begin(); it != getMap().end(); it++) {
            std::string path = (*it).first;
            if (endsWith(path, "/gate")) {
                gate = path;
            } else if (endsWith(path, "/freq")) {
                freq = path;
            } else if (endsWith(path, "/gain")) {
                gain = path;
            }
        }
    }

    // MIDI velocity [0..127]
    void keyOn(int pitch, int velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, float(velocity)/127.f);
        fNote = pitch;
        fTrigger = true; // so that envelop is always re-initialized
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, float velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, velocity);
        fNote = pitch;
        fTrigger = true; // so that envelop is always re-initialized
    }

    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        setParamValue(fGatePath, FAUSTFLOAT(0));
        if (hard) {
            // Stop immediately
            fNote = kFreeVoice;
            fTrigger = false;
        } else {
            // Release voice
            fNote = kReleaseVoice;
        }
    }

    void play(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (fTrigger) {
            // New note, so trigger it
            trigger(count, inputs, outputs);
        } else {
            // Compute the voice
            compute(count, inputs, outputs);
        }
    }

    void trigger(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        setParamValue(fGatePath, FAUSTFLOAT(0));
        computeSlice(0, 1, inputs, outputs);
        setParamValue(fGatePath, FAUSTFLOAT(1));
        computeSlice(1, count - 1, inputs, outputs);
        fTrigger = false;
    }

    void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (slice > 0) {
            FAUSTFLOAT** inputs_slice = (FAUSTFLOAT**)alloca(getNumInputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < getNumInputs(); chan++) {
                inputs_slice[chan] = &(inputs[chan][offset]);
            }

            FAUSTFLOAT** outputs_slice = (FAUSTFLOAT**)alloca(getNumOutputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                outputs_slice[chan] = &(outputs[chan][offset]);
            }

            compute(slice, inputs_slice, outputs_slice);
        }
    }

};

/**
 * A group of voices.
 */

struct dsp_voice_group {

    GroupUI fGroups;

    std::vector<dsp_voice*> fVoiceTable; // Individual voices
    dsp* fVoiceGroup;                    // Voices group to be used for GUI grouped control

    FAUSTFLOAT fPanic;

    bool fVoiceControl;
    bool fGroupControl;

    dsp_voice_group(uiCallback cb, void* arg, bool control, bool group)
        :fGroups(&fPanic, cb, arg),
        fVoiceGroup(0), fPanic(FAUSTFLOAT(0)),
        fVoiceControl(control), fGroupControl(group)
    {}

    virtual ~dsp_voice_group()
    {
        for (int i = 0; i < fVoiceTable.size(); i++) {
            delete fVoiceTable[i];
        }
        delete fVoiceGroup;
    }

    void addVoice(dsp_voice* voice)
    {
        fVoiceTable.push_back(voice);
    }

    void clearVoices()
    {
        fVoiceTable.clear();
    }

    void init()
    {
        // Groups all uiItem for a given path
        fVoiceGroup = new proxy_dsp(fVoiceTable[0]);
        fVoiceGroup->buildUserInterface(&fGroups);
        for (int i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->buildUserInterface(&fGroups);
        }
    }

    void buildUserInterface(UI* ui_interface)
    {
        if (fVoiceTable.size() > 1) {
            ui_interface->openTabBox("Polyphonic");

            // Grouped voices UI
            ui_interface->openVerticalBox("Voices");
            ui_interface->addButton("Panic", &fPanic);
            fVoiceGroup->buildUserInterface(ui_interface);
            ui_interface->closeBox();

            // In not group, also add individual voices UI
            if (!fGroupControl) {
                for (int i = 0; i < fVoiceTable.size(); i++) {
                    char buffer[32];
                    snprintf(buffer, 31, ((fVoiceTable.size() < 8) ? "Voice%d" : "V%d"), i+1);
                    ui_interface->openHorizontalBox(buffer);
                    fVoiceTable[i]->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                }
            }

            ui_interface->closeBox();
        } else {
            fVoiceTable[0]->buildUserInterface(ui_interface);
        }
    }

};

/**
 * Polyphonic DSP : group a set of DSP to be played together or triggered by MIDI.
 */

class mydsp_poly : public decorator_dsp, public dsp_voice_group, public midi {

    private:

        FAUSTFLOAT** fMixBuffer;
        int fDate;

        inline FAUSTFLOAT mixVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < getNumOutputs(); i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    level = FLOAT_MAX(level, (FAUSTFLOAT)fabs(outChannel[j]));
                    mixChannel[j] += outChannel[j];
                }
            }
            return level;
        }

        inline void clearOutput(int count, FAUSTFLOAT** mixBuffer)
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                memset(mixBuffer[i], 0, count * sizeof(FAUSTFLOAT));
            }
        }

        inline int getVoice(int note, bool steal = false)
        {
            for (int i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == note) {
                    if (steal) {
                        fVoiceTable[i]->fDate = fDate++;
                    }
                    return i;
                }
            }

            if (steal) {
                int voice_release = kNoVoice;
                int voice_playing = kNoVoice;
                int oldest_date_release = INT_MAX;
                int oldest_date_playing = INT_MAX;

                // Scan all voices
                for (int i = 0; i < fVoiceTable.size(); i++) {
                    if (fVoiceTable[i]->fNote == kReleaseVoice) {
                        // Keeps oldest release voice
                        if (fVoiceTable[i]->fDate < oldest_date_release) {
                            oldest_date_release = fVoiceTable[i]->fDate;
                            voice_release = i;
                        }
                    } else {
                        // Otherwise keeps oldest playing voice
                        if (fVoiceTable[i]->fDate < oldest_date_playing) {
                            oldest_date_playing = fVoiceTable[i]->fDate;
                            voice_playing = i;
                        }
                    }
                }

                // Then decide which one to steal
                if (oldest_date_release != INT_MAX) {
                    std::cout << "Steal release voice : voice_date " << fVoiceTable[voice_release]->fDate << " cur_date = " << fDate << " voice = " << voice_release << std::endl;
                    fVoiceTable[voice_release]->fDate = fDate++;
                    fVoiceTable[voice_release]->fTrigger = true;
                    return voice_release;
                } else if (oldest_date_playing != INT_MAX) {
                    std::cout << "Steal playing voice : voice_date " << fVoiceTable[voice_playing]->fDate << " cur_date = " << fDate << " voice = " << voice_playing << std::endl;
                    fVoiceTable[voice_playing]->fDate = fDate++;
                    fVoiceTable[voice_playing]->fTrigger = true;
                    return voice_playing;
                } else {
                    assert(false);
                    return kNoVoice;
                }

            } else {
                return kNoVoice;
            }
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff(true);
            }
        }

        inline bool checkPolyphony()
        {
            if (fVoiceTable.size() > 0) {
                return true;
            } else {
                std::cout << "DSP is not polyphonic...\n";
                return false;
            }
        }

        // Always returns a voice
        int newVoiceAux()
        {
            int voice = getVoice(kFreeVoice, true);
            assert(voice != kNoVoice);
            fVoiceTable[voice]->fNote = kActiveVoice;
            return voice;
        }

    public:

        /**
         * Constructor.
         *
         * @param dsp - the dsp to be used for one voice. Beware: mydsp_poly will use and finally delete the pointer.
         * @param nvoices - number of polyphony voices
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *
         */
        mydsp_poly(dsp* dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true):decorator_dsp(dsp), dsp_voice_group(panic, this, control, group)
        {
            fDate = 0;

            // Create voices
            for (int i = 0; i < nvoices; i++) {
                addVoice(new dsp_voice(dsp->clone()));
            }

            // Init audio output buffers
            fMixBuffer = new FAUSTFLOAT*[getNumOutputs()];
            for (int i = 0; i < getNumOutputs(); i++) {
                fMixBuffer[i] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
            }

            dsp_voice_group::init();
        }

        virtual ~mydsp_poly()
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                delete[] fMixBuffer[i];
            }
            delete[] fMixBuffer;
        }

        // DSP API
    
        void buildUserInterface(UI* ui_interface)
        {
            dsp_voice_group::buildUserInterface(ui_interface);
        }

        void init(int samplingRate)
        {
            // Init voices
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(samplingRate);
            }
        }

        void instanceInit(int samplingRate)
        {
            // Init voices
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceInit(samplingRate);
            }
        }

        void instanceConstants(int samplingRate)
        {
            // Init voices
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(samplingRate);
            }
        }

        void instanceResetUserInterface()
        {
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceResetUserInterface();
            }
        }

        void instanceClear()
        {
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceClear();
            }
        }

        virtual mydsp_poly* clone()
        {
            return new mydsp_poly(fDSP->clone(), fVoiceTable.size(), fVoiceControl, fGroupControl);
        }

        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count < MIX_BUFFER_SIZE);

            // First clear the outputs
            clearOutput(count, outputs);

            if (fVoiceControl) {
                // Mix all playing voices
                for (int i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fNote != kFreeVoice) {
                        voice->play(count, inputs, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixVoice(count, fMixBuffer, outputs);
                        // Check the level to possibly set the voice in kFreeVoice again
                        if ((voice->fLevel < VOICE_STOP_LEVEL) && (voice->fNote == kReleaseVoice)) {
                            voice->fNote = kFreeVoice;
                        }
                    }
                }
            } else {
                // Mix all voices
                for (int i = 0; i < fVoiceTable.size(); i++) {
                    fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                    mixVoice(count, fMixBuffer, outputs);
                }
            }
        }

        void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(count, inputs, outputs);
        }

        // Additional polyphonic API
        MapUI* newVoice()
        {
            return fVoiceTable[newVoiceAux()];
        }

        void deleteVoice(MapUI* voice)
        {
            std::vector<dsp_voice*>::iterator it = find(fVoiceTable.begin(), fVoiceTable.end(), reinterpret_cast<dsp_voice*>(voice));
            if (it != fVoiceTable.end()) {
                (*it)->keyOff();
            } else {
                std::cout << "Voice not found\n";
            }
        }

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = newVoiceAux();
                fVoiceTable[voice]->keyOn(pitch, velocity);
                return fVoiceTable[voice];
            } else {
                return 0;
            }
        }

        void keyOff(int channel, int pitch, int velocity = 127)
        {
            if (checkPolyphony()) {
                int voice = getVoice(pitch);
                if (voice != kNoVoice) {
                    fVoiceTable[voice]->keyOff();
                } else {
                    std::cout << "Playing pitch = " << pitch << " not found\n";
                }
            }
        }

        void pitchWheel(int channel, int wheel)
        {}

        void ctrlChange(int channel, int ctrl, int value)
        {
            if (ctrl == ALL_NOTES_OFF || ctrl == ALL_SOUND_OFF) {
                allNotesOff();
            }
        }

        void progChange(int channel, int pgm)
        {}

        void keyPress(int channel, int pitch, int press)
        {}

        void chanPress(int channel, int press)
        {}

        void ctrlChange14bits(int channel, int ctrl, int value)
        {}

        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
        }

};

#endif // __poly_dsp__
#endif

#ifdef PATCH
static daisy::DaisyPatch hw;
#else
static daisy::DaisySeed hw;
#endif

static DaisyControlUI* control_UI = nullptr;
static dsp* DSP = nullptr;

#ifdef MIDICTRL
list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;
#endif

static void AudioCallback(daisy::AudioHandle::InputBuffer in, daisy::AudioHandle::OutputBuffer out, size_t count)
{
    // Update controllers
    control_UI->update();
    
    // DSP processing
    DSP->compute(count, static_cast<float**>(in), out);
}

int main(void)
{
    // initialize seed hardware and daisysp modules
#ifndef PATCH
    hw.Configure();
#endif
    hw.Init();
    
    // allocate DSP
#ifdef POLY
    int nvoices = 0;
    bool midi_sync = false;
    DSP = new mydsp();
    MidiMeta::analyse(DSP, midi_sync, nvoices);
    DSP = new mydsp_poly(DSP, nvoices, true, true);
#else
    DSP = new mydsp();
#endif
    
    // set buffer-size
    hw.SetAudioBlockSize(MY_BUFFER_SIZE);
    
    // init Faust DSP
    DSP->init(MY_SAMPLE_RATE);
    
    // setup controllers
#ifdef PATCH
    control_UI = new DaisyControlUI(&hw.seed, MY_SAMPLE_RATE/MY_BUFFER_SIZE);
#else
    control_UI = new DaisyControlUI(&hw, MY_SAMPLE_RATE/MY_BUFFER_SIZE);
#endif
    DSP->buildUserInterface(control_UI);
    
    // start ADC
    hw.adc.Start();
    
    // define and start callback
    hw.StartAudio(AudioCallback);
    
#ifdef MIDICTRL
    daisy_midi midi_handler;
    MidiUI midi_interface(&midi_handler);
    DSP->buildUserInterface(&midi_interface);
    midi_handler.startMidi();
#endif
    
    // MIDI handling loop
    while(1) {
    #ifdef MIDICTRL
        midi_handler.processMidi();
    #endif
    }
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/

#endif
