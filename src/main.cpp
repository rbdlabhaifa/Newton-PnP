/**
 * This program takes a set of corresponding 2D and 3D points and finds the transformation matrix 
 * that best brings the 3D points to their corresponding 2D points.
 */

#include "RansacOptimalPnP/RansacOptimalPnP.h"
#include "FramePose/FramePose.h"
#include <opencv2/imgproc.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>
#include <vector>

std::vector<cv::Point2d> Generate2DPoints();
std::vector<cv::Point3d> Generate3DPoints();

std::vector<cv::Point2d> Generate2DPoints(){
  std::vector<cv::Point2d> points;
 
  float x,y;
 
  x=282;y=274;
  points.push_back(cv::Point2d(x,y));
 
  x=397;y=227;
  points.push_back(cv::Point2d(x,y));
 
  x=577;y=271;
  points.push_back(cv::Point2d(x,y));
 
  x=462;y=318;
  points.push_back(cv::Point2d(x,y));
 
  x=270;y=479;
  points.push_back(cv::Point2d(x,y));
 
  x=450;y=523;
  points.push_back(cv::Point2d(x,y));
 
  x=566;y=475;
  points.push_back(cv::Point2d(x,y));
 
  return points;
}
 
 
std::vector<cv::Point3d> Generate3DPoints(){
  std::vector<cv::Point3d> points;
 
 
  float x,y,z;
 
  x=.5;y=.5;z=-.5;
  points.push_back(cv::Point3d(x,y,z));
 
  x=.5;y=.5;z=.5;
  points.push_back(cv::Point3d(x,y,z));
 
  x=-.5;y=.5;z=.5;
  points.push_back(cv::Point3d(x,y,z));
 
  x=-.5;y=.5;z=-.5;
  points.push_back(cv::Point3d(x,y,z));
 
  x=.5;y=-.5;z=-.5;
  points.push_back(cv::Point3d(x,y,z));
 
  x=-.5;y=-.5;z=-.5;
  points.push_back(cv::Point3d(x,y,z));
 
  x=-.5;y=-.5;z=.5;
  points.push_back(cv::Point3d(x,y,z));
 
  return points;
}


int main(){

    std::vector<cv::Point2d> imagePoints = Generate2DPoints();
    std::vector<cv::Point3d> objectPoints = Generate3DPoints();
 
    cv::Mat rvec(3,1,cv::DataType<double>::type);
    cv::Mat tvec(3,1,cv::DataType<double>::type);

    cv::Mat distCoeffs(4,1,cv::DataType<double>::type);
    distCoeffs.at<double>(0) = 0;
    distCoeffs.at<double>(1) = 0;
    distCoeffs.at<double>(2) = 0;
    distCoeffs.at<double>(3) = 0;
    distCoeffs.at<double>(4) = 0;

    cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3) << 647.81841563, 0, 335.8814632, 0, 645.9438274, 225.99776891, 0, 0, 1);
    int min_iterations = 10, max_iterations = 10, min_inliers = 8;
    double reprojection_err_th = 64.0;

    RansacOptimalPnP RansacPnPSolver(min_iterations, max_iterations, min_inliers, reprojection_err_th, cameraMatrix, distCoeffs);

    FramePose frame_pose;
    std::vector<cv::Point2d> scene;
    std::vector<cv::Point3d> obj;
    std::vector<bool> is_inliers;
    int inliers_cnt_result;
    std::vector<cv::Point2d> undist_scene;
    cv::undistortPoints(imagePoints, undist_scene, cameraMatrix, distCoeffs, cv::Mat(), cameraMatrix);

    bool success_optimal = RansacPnPSolver.newton_pnp(undist_scene, objectPoints, frame_pose);
    
    for (int i=0; i < 3; i++){
        std::cout  << frame_pose.R.at<float>(i,0) << "," << frame_pose.R.at<float>(i,1) << "," << frame_pose.R.at<float>(i,2) << std::endl;
    }

    std::cout << frame_pose.t << std::endl;

    return 0;
}
