[![Build Status](https://github.com/danielforever/ENPM808X_Midterm_Proposal/actions/workflows/build_and_coveralls.yml/badge.svg)](https://github.com/danielforever/ENPM808X_Midterm_Proposal/actions/workflows/build_and_coveralls.yml)
[![Coverage Status](https://coveralls.io/repos/github/danielforever/ENPM808X_Midterm_Proposal/badge.svg?branch=main)](https://coveralls.io/github/danielforever/ENPM808X_Midterm_Proposal?branch=main)
[![GitHub license](https://badgen.net/github/license/Naereen/Strapdown.js)](LICENSE.md)


# MID_TERM_PROPOSAL_PHASE_2
***
**Collaborators**
> - *Navigator*      **Aman Sharma** <ashrm007@umd.edu>
> - *Driver*         **Po-Yu Huang**  <phuang14@umd.edu>
> - *Design Keeper*  **Shantanu Parab**  <sparab@umd.edu>

### AIP Document 
[![Documentation Status](https://readthedocs.org/projects/ansicolortags/badge/?version=latest)](https://docs.google.com/spreadsheets/d/1YIb6e1S-9IIIN0XqMSaTiWy73bQwWlGtOVpeUz_p5m0/edit?usp=sharing)

## Sprint Planning Review Document
[![Documentation Status](https://readthedocs.org/projects/ansicolortags/badge/?version=latest)](https://docs.google.com/document/d/1yf7floh_fHxyug6Ytcp7xqqo3Nc4zX4OPCIcwfu8p-A/edit?usp=sharing)

**Course:** Software Development for Robotics  
**Code:** ENPM808X  
**Semester:** Fall 2022  
**School:** A. James Clark School of Engineering, University of Maryland  

***
### Brief Overview
This repository consists of the C++ implementation of Human Object Detection for a robot with monocular camera proposed for a fictional organization ACME Robotics.  
The focus of the project is to develope best practices for Software Develpoement using `Agile Iterative Process(AIP)` and `Test Driven Developemnet(TDD)`. This will be a 4 week project from design stage to delivery of the project tracked using different techniques like Sprints,Product Backlogs,Daily Meetings and Git.  
*Updates regarding the project will be put on Github*



**Human Obstacle Detection Software**  *(ACME Robotics)*  
**Algorithm:** `YOLO`  `Kalman Filter`  
**Libraries:** `OpenCV`  
**Programming Language:** `C++`  
**Memory Profiling:** `Valgrind`  
**Documentaton:** `Doxygen`  
### Results
![alt text](./assets/Results.gif?raw=true "Human Detector Result")

***
### Deliverables
1. [Project Proposal](submission/proposal/Proposal.pdf)

2. [Quad Chart](submission/quad_chart/Quad%20Chart.pdf)

3. [Class Diagram](submission/uml/Final%20Class.png)

4. [Activity Diagram](submission/uml/Activity%20Diagram.pdf)

5.  [Video Phase 0](https://youtu.be/RBK_uPH3j8g)

6. [Video Phase 1](https://youtu.be/Oaej38F-kNk)

7. [Video Phase 2](https://youtu.be/DrEf_KXivNQ)

***
## Run cppcheck and cpplint
Run cppcheck: Results are stored in `./results/cppcheck_process.txt`, `./results/cppcheck_result.txt` 

`sh cppcheck.sh`


Run cpplint: Results are stored in `./results/cpplint_result.txt`

`sh cpplint.sh`


No cpp-lint and cpp-check issues were found.

***

### Running the human detection app


git clone --recursive https://github.com/danielforever/ENPM808X_Midterm_Proposal.git  
`cd ENPM808X_Midterm_Proposal`  
`mkdir build`  
`cd build`  
`cmake ..`  
`make`  
Run tests: `./test/cpp-test`  
Run the main human detection pipeline: `./app/shell-app`  



***
# Doxygen Generation  
`cd doxygen`  
`doxygen Doxyfile`

