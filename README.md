# High-Performance Aerodynamic Design of a Formula 1 Vehicle: A CFD-Based Approach Adhering To The 2026 FIA Regulations
| ![Streamlines over Pressure 1](https://github.com/user-attachments/assets/c47a8cdd-3003-4411-9ca2-6b7f634a20ad) |
|:-:|
| *Surface LIC of velocity field streamlines superimposed over the coloured pressure field* |


This repository contains the OpenFOAM CFD case for the **Final Year Project** focused on the **Aerodynamic Design of an F1 Car** based on the 2026 Formula 1 regulations. The project uses incompressible, turbulent flow CFD simulations to optimize the aerodynamic performance of a Formula 1 car.

| ![](https://github.com/user-attachments/assets/2b26a115-239d-4f33-b0b4-28a034808eab) |
|:--:| 
| *Velocity profile around the car in X-Plane* |

## Overview  

The primary goal of this project is to design, analyze, and optimize the aerodynamics of an F1 car in compliance with the 2026 regulations. Using the **Red Bull Racing RB9** model as the baseline, we performed extensive CFD simulations to gather all the relevant data reqired to optimize the car design.  

## Software and Tools  

- **CAD Software:** Autodesk Fusion 360  
- **CFD Tools:** OpenFOAM v2406.  
- **Post-Processing:** Kitware Paraview 5.13

## Tasks Done So Far  

- **Baseline Model:** Modeled the **Red Bull RB9** in CAD as a starting point.  
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

## How to Use  

1. Clone the repository:  
   ```bash  
   git clone https://github.com/Rajwinder-Singh-19/Major_Project_Formula1_Aerodynamics.git

## Contributors

| Name | Email |
| :---: | :---: |
| Bhavtegh Singh Gill | bhavteghsinghgill.bt21aero@pec.edu.in |
| Aniket | aniket.bt21aero@pec.edu.in |
