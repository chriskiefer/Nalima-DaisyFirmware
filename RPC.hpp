#pragma once

#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <EigenRand>


struct RPC {

  static Eigen::MatrixXf createProjectionMatrix(size_t windowSize, size_t nDimensions) {
    Eigen::Rand::Vmt19937_64 urng{ 42 };
    Eigen::MatrixXf projectionMatrix = Eigen::Rand::normal<Eigen::MatrixXf>(nDimensions, windowSize, urng, 0, sqrt(1.0/nDimensions));
    return projectionMatrix;
  }

  static Eigen::MatrixXf calcProjection(const Eigen::MatrixXf &projectionMatrix, const Eigen::VectorXf &data, double hop=0.5) {
    size_t hopSize = std::max((size_t)1, static_cast<size_t>(projectionMatrix.cols() * hop));
    size_t nHops = static_cast<size_t>((data.size() - projectionMatrix.cols()) / hopSize) + 1;
    Eigen::MatrixXf projections(projectionMatrix.rows(), nHops);
    for(size_t i=0; i < nHops; i++) {
      // cout << "dw: " << i;
      // auto dataWindow = data(Eigen::seqN(i*hopSize, projectionMatrix.cols()));
      const auto dataWindow = data.segment(i*hopSize,projectionMatrix.cols());

      // cout << "\n" << dataWindow << endl;
      const auto projection = projectionMatrix * dataWindow;
      // cout << projection << endl;
      projections.col(i) = projection;
    }
    // cout << projections << endl; 
    return projections;
  }

  static inline size_t calcXdFlatArrayIndex(const Eigen::VectorXf &indexTuple, const size_t bound) {
    size_t index = indexTuple(0);
    for (size_t i =1; i < indexTuple.size(); i++) {
        index *= bound;
        index += indexTuple(i);
    }
    return index;
  }

  static float calculateProjectionArea(Eigen::MatrixXf &projections, const size_t resolution) {
    // cout << "area calc" << endl;
    size_t dims = projections.rows();
    // cout << projections << endl;
    //translate array to histogram bin indexes
    for(size_t row=0; row < projections.rows(); row++) {
      projections.row(row) = projections.row(row).array() - projections.row(row).minCoeff();
      // cout << "p:\n" << projections << endl;
      if (projections.row(row).maxCoeff() > 0) {
        projections.row(row) /=  (projections.row(row).maxCoeff() * 1.000001);
      }
      // cout << "p:\n" << projections << endl;
    }
    projections =  projections * resolution;
    // cout << "p:\n" << projections << endl;
    projections =  projections.array().floor();
    // cout << "p:\n" << projections << endl;

    //flat storage of multidimensional histogram, fill with zeros
    size_t histoSize = pow(resolution,dims);


    
    std::vector<size_t> indexes(projections.cols());
    for(size_t i=0; i < projections.cols(); i++) {
      Eigen::VectorXf indexTuple = projections.col(i);
      size_t index = RPC::calcXdFlatArrayIndex(indexTuple, resolution);
      indexes[i] = index;
    }
    std::sort(indexes.begin(), indexes.end());
    auto last = std::unique(indexes.begin(), indexes.end());
    indexes.erase(last, indexes.end());
    return static_cast<double>(indexes.size());


  }

  static float calc(const Eigen::MatrixXf &projectionMatrix, const Eigen::VectorXf &data, const size_t resolution, float hop=0.5) {
    double res = 0;
    auto projections = RPC::calcProjection(projectionMatrix, data, hop);
    res = calculateProjectionArea(projections, resolution);
    return res;
  }


};