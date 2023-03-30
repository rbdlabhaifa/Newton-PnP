# Newton-PnP
**Authors:** [Ibrahim Jubran](https://scholar.google.com/citations?hl=en&user=6OOalGkAAAAJ), [Fares Fares](https://scholar.google.com/citations?user=Wm4eHwgAAAAJ&hl=en&oi=ao), [Yuval Alfassi](https://dblp.org/pid/295/6748.html), [Firas Ayoub](http://doriangalvez.com/) and [Dan Feldman](https://scholar.google.com/citations?user=67QZN0gAAAAJ&hl=en) from the [Robotics & Big Data Labs](https://www.rbd-labs.com).

The Perspective-n-Point problem aims to estimate the relative pose between a calibrated monocular camera and a known 3D model, by aligning pairs of 2D captured image points to their corresponding 3D points in the model.
We suggest an algorithm that runs on weak IoT devices in real-time but still provides provable theoretical guarantees for both running time and correctness. Existing solvers provide only one of these requirements.
Our main motivation was to turn the popular DJI's Tello Drone (<90gr, <$100) into an autonomous drone that navigates in an indoor environment with no external human/laptop/sensor, by simply attaching a Raspberry PI Zero (<9gr, <$25) to it. This tiny micro-processor takes as input a real-time video from a tiny RGB camera, and runs our PnP solver on-board. Extensive experimental results, open source code, and a demonstration video are included.

This work was accepted to The **2022 IEEE/RSJ International Conference on Intelligent Robotics and Systems (IROS'22) [PDF](https://arxiv.org/pdf/2203.02686.pdf)**.

<a href="https://youtu.be/AT-H0GUlZDo" target="_blank"> <img src="http://img.youtube.com/vi/AT-H0GUlZDo/0.jpg" alt="Newton PnP" width="300" height="240" border="10"/></a>

# 1. License

If you use Newton-PnP in an academic work, please cite:
```
  @article{jubran2022newton,
  title={Newton-PnP: Real-time Visual Navigation for Autonomous Toy-Drones},
  author={Jubran, Ibrahim and Fares, Fares and Alfassi, Yuval and Ayoub, Firas and Feldman, Dan},
  journal={arXiv preprint arXiv:2203.02686},
  year={2022}
}
```
# 2. Prerequisites
We have tested the library in **Ubuntu 20.04**, and **Raspberry Pi OS** but it should be easy to compile in other platforms.

## C++17 or C++0x Compiler
Tested with C++17.

## OpenCV
We use [OpenCV](http://opencv.org) to manipulate images and features. Dowload and install instructions can be found at: http://opencv.org.
**Tested with OpenCV 3.4.16**.

## Eigen3
Download and install instructions can be found at: http://eigen.tuxfamily.org. **tested with Eigen 3.3.0**.

## Boost
Install Boost free peer-reviewed portable C++ source libraries: https://www.boost.org/. 
```
sudo apt-get install libboost-all-dev
```

# 3. Building Newton-PnP library and examples

Clone the repository:
```
git clone https://github.com/rbdlabhaifa/Newton-PnP.git
```

Please make sure you have installed all required dependencies (see section 2). Execute:
```
mkdir build
cd build
cmake ..
make
```

# 4. Examples
```
cd build
./NPnP
```
