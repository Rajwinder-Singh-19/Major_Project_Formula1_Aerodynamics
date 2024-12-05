# High-Performance Aerodynamic Design of a Formula 1 Vehicle: A CFD-Based Approach Adhering To The 2026 FIA Regulations
| ![Streamlines over Pressure 1](https://github.com/user-attachments/assets/c47a8cdd-3003-4411-9ca2-6b7f634a20ad) |
|:-:|
| *Surface LIC of velocity field streamlines superimposed over the coloured pressure field* |


This repository contains the OpenFOAM CFD case for the **Final Year Project** focused on the **Aerodynamic Design of an F1 Car** based on the 2026 Formula 1 regulations. The project uses incompressible, turbulent flow CFD simulations to optimize the aerodynamic performance of a Formula 1 car.

| ![XP](https://github.com/user-attachments/assets/52672c4c-479c-466b-932d-ffbb8b58ac24) |
|:--:| 
| *Velocity profile around the car in X-Plane* |

| ![YP](https://github.com/user-attachments/assets/1d3e3177-a29e-434d-8340-1d38efbad623) |
|:--:| 
| *Velocity profile around the car in Y-Plane* |

| ![YP](https://![ZP](https://github.com/user-attachments/assets/a7f485d4-d915-4161-b107-6fda22d9a9b6) |
|:--:| 
| *Velocity profile around the car in Z-Plane* |

## Overview  

The primary goal of this project is to design, analyze, and optimize the aerodynamics of an F1 car in compliance with the 2026 regulations. Using the **Red Bull Racing RB9** model as the baseline, we performed extensive CFD simulations to gather all the relevant data reqired to optimize the car design.  

## Software and Tools  

- **CAD Software:** Autodesk Fusion 360  
- **CFD Tools:** OpenFOAM v2406.  
- **Post-Processing:** Kitware Paraview 5.13

## Tasks Done So Far  

- **Baseline Model:** Modeled the **Red Bull RB9** in CAD as a starting point.
- **Developed A Software for RANS Calculation:** Developed a software using C++ and Qt framework to calculate RANS parameters for boundary and initial conditions, along with mesh refinement parameters
- **CFD Simulations:** Used OpenFOAM for meshing and CFD simulation of incompressible, turbulen flow around the created model using SIMPLE algorithm with k-omega SST model for turbulence  
- **Solver Validation:** Validated the CFD solver using the **Ahmed Body**, a standard benchmark in automotive aerodynamics. 

## Results and Visulizations
The following images were captured by visualizing the data in paraview. All the relevant value scales for variables are provided in each image.

| ![Pressure Contours Iso](https://github.com/user-attachments/assets/4453661a-3595-451d-82c3-3442003376d7) |
|:--:| 
| *Pressure contours* |

| ![Velocity Field](https://github.com/user-attachments/assets/7f3dc432-cde3-4f13-9514-5333e085dc00) |
|:--:| 
| *Wake captured* |

| ![Vortices over U](https://github.com/user-attachments/assets/8727bd1f-0646-4fe5-b7da-0cb5a694073f) |
|:--:| 
| *Q-Criterion Plot for observing vortex structures* |

| ![Drag Distribution](https://github.com/user-attachments/assets/b6b512ff-8a7d-4d22-82b6-4fa0a24d15df) |
|:--:| 
| *Drag Distribution on the surface* |

| ![Downforce Distribution](https://github.com/user-attachments/assets/ce56513f-f1cc-468e-8395-e3e70d2e4be3) |
|:--:| 
| *Downforce Distribution on the surface* |

![Screenshot from 2024-12-02 12-19-27](https://github.com/user-attachments/assets/c687adab-3eed-4da8-a485-de5403ec9060)
|:--:| 
| *RANS Parameter Tuning Software* |

## How to Use  

1. Clone the repository:  
   ```bash  
   git clone https://github.com/Rajwinder-Singh-19/Major_Project_Formula1_Aerodynamics.git

## Contributors

| Name | Email |
| :---: | :---: |
| Bhavtegh Singh Gill | bhavteghsinghgill.bt21aero@pec.edu.in |
| Aniket | aniket.bt21aero@pec.edu.in |
