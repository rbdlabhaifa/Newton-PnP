# Newton-PnP
**Authors:** [Ibrahim Jubran](https://scholar.google.com/citations?hl=en&user=6OOalGkAAAAJ), [Fares Fares](https://scholar.google.com/citations?user=Wm4eHwgAAAAJ&hl=en&oi=ao), [Yuval Alfassi](https://dblp.org/pid/295/6748.html), [Firas Ayoub](http://doriangalvez.com/) and [Dan Feldman](https://scholar.google.com/citations?user=67QZN0gAAAAJ&hl=en).

The Perspective-n-Point problem aims to estimate the relative pose between a calibrated monocular camera and a known 3D model, by aligning pairs of 2D captured image points to their corresponding 3D points in the model. We suggest an algorithm that runs on weak IoT devices in real-time but still provides provable theoretical guarantees for both running time and correctness. Existing solvers provide only one of these requirements.

<a href="https://www.youtube.com/watch?v=AT-H0GUlZDo&list=PLf8k2yOlhVk8Xd-RWIBchSH4mU7RboIk6&index=8&ab_channel=FaresFares" target="_blank"><img src="https://drive.google.com/file/d/10szUMHISe7EcEzlCT3bAhQ0feXZQCR3a/view?usp=sharing" alt="Newton-PnP" width="240" height="180" border="10" /></a>

### Related Publications:

Ibrahim Jubran, Fares Fares, Yuval Alfassi, Firas Ayoub and Dan Feldman. **Newton-PnP:
Real-time Visual Navigation for Autonomous Toy-Drones**. *The 2022 IEEE/RSJ International Conference on Intelligent Robotics and Systems (IROS'22) **[PDF](https://arxiv.org/pdf/2203.02686.pdf)**.

# 1. License

Newton-PnP is released under a MIT License.

For a list of all code/library dependencies (and associated licenses), please see [Dependencies.md](https://github.com/rbdlabhaifa/Neton-PnP/Dependencies.md).

For a closed-source version of Newton-PnP for commercial purposes, please contact the author: ibrahim.jub@gmail.com.

If you use Newton-PnP in an academic work, please cite:
```
  @misc{https://doi.org/10.48550/arxiv.2203.02686,
  
  doi = {10.48550/ARXIV.2203.02686},
  
  url = {https://arxiv.org/abs/2203.02686},
  
  author = {Jubran, Ibrahim and Fares, Fares and Alfassi, Yuval and Ayoub, Firas and Feldman, Dan},
  
  keywords = {Computer Vision and Pattern Recognition (cs.CV), Robotics (cs.RO), FOS: Computer and information sciences, FOS: Computer and information sciences},
 
  title = {Newton-PnP: Real-time Visual Navigation for Autonomous Toy-Drones},
  
  publisher = {arXiv},
  
  year = {2022},
  
  copyright = {arXiv.org perpetual, non-exclusive license}
  }
```
# 2. Prerequisites
We have tested the library in **Ubuntu 20.04**, and **Raspberry Pi OS** but it should be easy to compile in other platforms.

## C++11 or C++0x Compiler
We use the new thread and chrono functionalities of C++11.

## OpenCV
We use [OpenCV](http://opencv.org) to manipulate images and features. Dowload and install instructions can be found at: http://opencv.org. **Required at leat 2.4.3. Tested with OpenCV 2.4.11 and OpenCV 3.2**.

## Eigen3
Required by g2o (see below). Download and install instructions can be found at: http://eigen.tuxfamily.org. **Required at least 3.1.0**.

# 3. Building ORB-SLAM2 library and examples

Clone the repository:
```
git clone https://github.com/raulmur/ORB_SLAM2.git ORB_SLAM2
```

We provide a script `build.sh` to build the *Thirdparty* libraries and *ORB-SLAM2*. Please make sure you have installed all required dependencies (see section 2). Execute:
```
cd ORB_SLAM2
chmod +x build.sh
./build.sh
```

This will create **libORB_SLAM2.so**  at *lib* folder and the executables **mono_tum**, **mono_kitti**, **rgbd_tum**, **stereo_kitti**, **mono_euroc** and **stereo_euroc** in *Examples* folder.

# 4. Monocular Examples
