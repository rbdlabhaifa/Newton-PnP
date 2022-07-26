/**
 * This program takes a set of corresponding 2D and 3D points and finds the transformation matrix 
 * that best brings the 3D points to their corresponding 2D points.
 */

#include "NewtonPnP/NewtonPnP.h"
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

    double x,y;

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

    double x,y,z;

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

    cv::Mat distCoeffs(4,1,cv::DataType<double>::type);
    distCoeffs.at<double>(0) = 0;
    distCoeffs.at<double>(1) = 0;
    distCoeffs.at<double>(2) = 0;
    distCoeffs.at<double>(3) = 0;
    distCoeffs.at<double>(4) = 0;

    cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3) << 640, 0, 480, 0, 640, 480, 0, 0, 1);
    FramePose frame_pose;

    // -----------------------------------------
    // Newton PnP:
    // -----------------------------------------
    NewtonPnP NewtonPnP(cameraMatrix, distCoeffs);
    bool success_optimal = NewtonPnP.newton_pnp(imagePoints, objectPoints, frame_pose);

    std::cout << "R: " << std::endl << frame_pose.R << std::endl << std::endl;
    std::cout << "t: " << std::endl << frame_pose.t << std::endl;

    // -----------------------------------------

    return 0;
}
