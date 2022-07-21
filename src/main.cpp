#include "RansacOptimalPnP/RansacOptimalPnP.h"
#include "FramePose/FramePose.h"
#include <opencv2/imgproc.hpp>
#include <vector>


int main(){

    cv::Mat K = (cv::Mat_<double>(3, 3) << 647.81841563, 0, 335.8814632, 0, 645.9438274, 225.99776891, 0, 0, 1);
    cv::Mat dist_coeffs = (cv::Mat1d(1, 5) << 0.04132402, -0.18592372, -0.00099313, 0.00361491, 0.85217311);
    int min_iterations = 10, max_iterations = 10, min_inliers = 8;
    double reprojection_err_th = 64.0;

    RansacOptimalPnP RansacPnPSolver(min_iterations, max_iterations, min_inliers, reprojection_err_th, K, dist_coeffs);

    FramePose frame_pose;
    std::vector<cv::Point2d> scene;
    std::vector<cv::Point3d> obj;
    std::vector<bool> is_inliers;
    int inliers_cnt_result;
    std::vector<cv::Point2d> undist_scene;
    cv::undistortPoints(scene, undist_scene, K, dist_coeffs, cv::Mat(), K);

    bool success_optimal = RansacPnPSolver.ransac_solve_pnp(undist_scene, obj, is_inliers, inliers_cnt_result, frame_pose);

    return 0;
}