/* ----------------------------------------------------------------------------
 * Copyright 2018, Ross Hartley
 * All Rights Reserved
 * See LICENSE for the license information
 * -------------------------------------------------------------------------- */

/**
 *  @file   NoiseParams.h
 *  @author Ross Hartley
 *  @brief  Header file for Invariant EKF noise parameter class
 *  @date   September 25, 2018
 **/
#ifndef NOISEPARAMS_H
#define NOISEPARAMS_H 
#include <Eigen/Dense>
#include <iostream>

class NoiseParams {

    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        NoiseParams();

        void setGyroscopeNoise(double std);
        void setGyroscopeNoise(const Eigen::Vector3d& std);
        void setGyroscopeNoise(const Eigen::Matrix3d& cov);

        void setAccelerometerNoise(double std);
        void setAccelerometerNoise(const Eigen::Vector3d& std);
        void setAccelerometerNoise(const Eigen::Matrix3d& cov);

        void setIntegrationNoise(double std);
        void setIntegrationNoise(const Eigen::Vector3d& std);
        void setIntegrationNoise(const Eigen::Matrix3d& cov);  

        void setGyroscopeBiasNoise(double std);
        void setGyroscopeBiasNoise(const Eigen::Vector3d& std);
        void setGyroscopeBiasNoise(const Eigen::Matrix3d& cov);

        void setAccelerometerBiasNoise(double std);
        void setAccelerometerBiasNoise(const Eigen::Vector3d& std);
        void setAccelerometerBiasNoise(const Eigen::Matrix3d& cov);  

        void setLandmarkNoise(double std);
        void setLandmarkNoise(const Eigen::Vector3d& std);
        void setLandmarkNoise(const Eigen::Matrix3d& cov);

        void setGpsNoise(double std);
        void setGpsNoise(const Eigen::Vector3d& std);
        void setGpsNoise(const Eigen::Matrix3d& cov);

        void setAverageDeltaT(double dt);

        Eigen::Matrix3d getGyroscopeCov();
        Eigen::Matrix3d getAccelerometerCov();
        Eigen::Matrix3d getIntegrationCov();
        Eigen::Matrix3d getGyroscopeBiasCov();
        Eigen::Matrix3d getAccelerometerBiasCov();
        Eigen::Matrix3d getLandmarkCov();
        Eigen::Matrix3d getGpsCov();
        double getAverageDeltaT();

        friend std::ostream& operator<<(std::ostream& os, const NoiseParams& p);  

    private:
        Eigen::Matrix3d Qg_;
        Eigen::Matrix3d Qa_;
        Eigen::Matrix3d Qi_;
        Eigen::Matrix3d Qbg_;
        Eigen::Matrix3d Qba_;
        Eigen::Matrix3d Ql_;
        Eigen::Matrix3d Qgps_;
        double dt_;
};

#endif 