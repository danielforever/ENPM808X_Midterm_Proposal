# MID_TERM_PROPOSAL_PHASE_0
*** 
![Logo](/assets/images/logo.png )
***
### Collaborators
> - *Navigator*      **Aman Sharma**    
> - *Driver*         **Po-Yu Huang**  <phuang14@umd.edu>
> - *Design Keeper*  **Shantanu Parab**  <sparab@umd.edu>


**Course:** Software Development for Robotics
**Code:** ENPM808X
**Semester:** Fall 2022
**School:** A. James Clark School of Engineering, University of Maryland

***
### Brief Overview
This repository consists of the C++ implementation of the Informed RRT* algorithm for autonomous navigation. Robotic vacuum cleaners are becoming a household thing in our modern world and has a huge market potential. One of the main components of the robotic vacuum cleaners is it's ability to plan a path from a given start to end point in an environment. This software is developed for a fictional cleaning robot Xoomba for ACME Robotics, a fictional organization.

Sampling-based algorithms represent the configuration space with a roadmap of sampled configurations. These algorithms work well for high-dimensional configuration spaces, because unlike combinatorial algorithms, their running time is not (explicitly) exponentially dependent on the dimension of configurations.

Rapidly-Exploring Random Trees (RRTs) is a planning technique for single-query problems which uses an incremental tree expansion from randomly drawn samples to grow towards previously unsearchable areas in the map space. Optimal RRTS (RRT*), an improvement on RRTs, extend the problem to finding the optimal solution in the planning space that is computed asymptotically. Informed RRT* improves the convergence speed of RRT* by introducing a heuristic, similar to the way in which A* improves upon Dijkstra’s algorithm.

**Human Obstacle Detection Software**  *(ACME Robotics)*  
 **Algorithm:** YOLO  
**Libraries:** OpenCV  
 **Programming Language:** C++


### File Structure  

>├───app  
>├───assets  
>│   └───images  
>├───cmake  
>├───include  
>├───submission  
>│   ├───proposal  
>│   ├───quad_chart  
>│   └───uml  
>├───test  
