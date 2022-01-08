# Project-Zeta
The goal of Project Zeta is to develop the world's first General Intelligence. Yes, a robot uprising is coming. We, at Project Zeta, are determined to develop a reliable platform to collect, process, and train data to develop a human-like intelligence. We will do this using a custom built, biomimetic, robot dog, with tons of sensors for environmental perception. This will be used to train a custom-built Z-Algorithm to develop the intelligence.

## Background
I am a robotics, hobbyist, enthusiast, and creator. I have been in this great hobby for the past 6 years and have experience in various fields of study. I have tremendous experience in Python, C, Tensorflow, ROS, as well as electronics, 3D Printing, and much more.

Any roboticist would know that a General Intelligence would be the ultimate project and I certainly believe so. 

## The Idea
The plan is to do what I call a "data dump reward strategy". The robot will collect LiDAR, RGBD, audio, tactile, and other sensory data. That will be fed into 2 Z-Algorithms. There will be a Kinetic and Cognitive Algorithm. 

The Kinetic's job is to do motion planning and dynamic obstacle avoidance using an intelligent action matrix. The reward and action matrix will feed into a simple transformer to relate the 4 dimensional data that we are feeding. 

The Cognitive will use a similar layer heiarchy but instead will look the largest change in pattern and will make a sensor priority matrix.

***Please note, these are simply plans and a due to change.***

## Setup and Assembly
All assembly instructions will be provided on the GitHub.io page. The ROS Stack currently requires the "ros-noetic-desktop-full" which have dependencies for ~200 packages. This will only currently work on multi-core PCs and not on Raspberry Pi. This will eventually be optimized to compile on ARM CPUs. 

## Open Source
The whole point of this is to make it as open source as possible. Obviously, all of my code is open source, the motors I used also provide their code and all the information to recreate them, and my 3D model of the dog will be on Thingiverse soon. 

Motors: Lewansoul LX-16A; https://www.hiwonder.com/store/learn/26.html; 
