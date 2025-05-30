# High-Performance Aerodynamic Design of a Formula 1 Vehicle: A CFD-Based Approach Adhering To The 2026 FIA Regulations
| ![Pressure Contours Iso](https://github.com/user-attachments/assets/4453661a-3595-451d-82c3-3442003376d7) |
|:--:| 
| *Pressure contours on the RedBull Racing RB9* |

This repository contains the record of the **Final Year Project** focused on the **Aerodynamic Design of an F1 Car** based on the 2026 Formula 1 regulations. The project uses turbulent, incompressible flow CFD simulations to optimize the aerodynamic performance of a Formula 1 car.

| ![XP](https://github.com/user-attachments/assets/c0aa6cdf-30f5-4788-b43e-fe9ceb61a508) |
|:--:| 
| *Velocity profile around the RB9 Car in X-Plane* |

| ![YP](https://github.com/user-attachments/assets/a0298fb4-2aa6-44dc-b190-6364938549d0) |
|:--:| 
| *Velocity profile around the RB9 Car in Y-Plane* |

| ![ZP](https://github.com/user-attachments/assets/8ee1e2d5-a836-429d-9421-aae6cfb572a4) |
|:--:| 
| *Velocity profile around the RB9 in Z-Plane* |

| ![U_Evo (1)](https://github.com/user-attachments/assets/6c8b25b0-a133-48c6-81b4-9129c372bf7e) |
|:--:|
| *Velocity profile around the RB9 frontwing in Y-Plane* |

| ![U_Evo](https://github.com/user-attachments/assets/da3dccfb-51b6-4e98-add3-9f8de8b9307f) |
|:--:| 
| *Velocity profile around the new frontwing in Y-Plane* |

## Overview  

The primary goal of this project is to design, analyze, and optimize the aerodynamics of an F1 car in compliance with the 2026 regulations. Using the **Red Bull Racing RB9** model as the baseline, we performed extensive CFD simulations to gather all the relevant data reqired to optimize the car design, which included pressure and velocity data, coefficients of drag and downforce.
## Software and Tools  

- **CAD Software:** Autodesk Fusion 360  
- **CFD Tools:** OpenFOAM v2406. SnappyHexMesh as the mesh generator. 
- **Post-Processing:** Kitware Paraview 5.11

## Progress of the Project So Far  

- **Baseline Model:** Modelled the **Red Bull RB9** in Autodesk Fusion as the baseline design.
- **Developing A Software for RANS Calculation:** Developed a software using C++ and Qt framework to calculate and tune RANS parameters for boundary and initial conditions, along with mesh refinement parameters.
- **CFD Simulations:** Used OpenFOAM for meshing (SnappyHexMesh) and CFD simulation of turbulent, incompressible flow around the RB9 model using SIMPLE algorithm with k-omega SST turbulence model   
- **Solver Validation:** Validated the CFD solver using the **Ahmed Body**, by recreating the results by Meile, Brenn, Reppenhagen and Lechner https://www.researchgate.net/publication/330383775_Experiments_and_numerical_simulations_on_the_aerodynamics_of_the_Ahmed_body
- **Frontwing Design:** Designed a new frontwing which showed 14% reduction in coefficient of drag and 38% increase in coefficient of downforce as compared to the RB9 frontwing.
  
| ![FwingFusion](https://github.com/user-attachments/assets/9813c0bd-6c30-44b8-a941-c464d3c54061) |
|:--:| 
| *Updated Frontwing Design* |

## How to Use  

### Prerequisites
- Linux (Debian/OpenSUSE/RedHat variants preferred)
- ESI OpenFOAM v2412 https://develop.openfoam.com/Development/openfoam/-/wikis/precompiled
- GNU Compiler Collection 
- Kitware Paraview 5.11 https://www.paraview.org/
- Qt Framework (open-source) https://www.qt.io/download-qt-installer-oss

1. Clone the repository:  
   ```bash  
   git clone https://github.com/Rajwinder-Singh-19/Major_Project_Formula1_Aerodynamics.git
   ```
2. Change the directory to 'Red Bull RB9 Base Model' and open terminal
3. Run the follwing bash script (copy/paste in the terminal)
   ```bash
   procs=8 (enter the number of processors available on your CPU)
   blockMesh | tee log.blockMesh
   surfaceFeatureExtract | tee log.surfaceFeatureExtract
   decomposePar | tee log.decomposePar1
   mpirun-np $procs snappyHexMesh -overwrite -parallel | tee log.snappyHexMesh
   reconstructParMesh -constant | tee log.reconstructParMesh
   rm -r proc*
   decomposePar | tee log.decomposePar2
   mpirun-np $procs potentialFoam -parallel -writep
   mpirun-np $procs simpleFoam -parallel | tee log.simpleFoam
   reconstructPar | tee log.reconstructParSolution
   simpleFoam -postProcess -func yPlus
   touch RB.foam
   paraview RB.foam &
   ```
4. Visualize the results in Paraview

## Results and Visulizations
The following images were captured by visualizing the data in paraview. All the relevant value scales for variables are provided in each image.

| ![Drag (1)](https://github.com/user-attachments/assets/8d4b443c-74c3-45a2-9ac1-44404ade8406) |
|:-:|
| *Drag Distribution over the RB9 frontwing* |

| ![Drag](https://github.com/user-attachments/assets/2c794d14-3e12-45a6-97f2-373b53b964dc) |
|:-:|
| *Drag Distribution over the updated frontwing* |

| ![Downforce (1)](https://github.com/user-attachments/assets/dd7c06df-fc20-40d1-955c-6d404045d859) |
|:-:|
| *Downforce Distribution over the RB9 frontwing* |

| ![Downforce](https://github.com/user-attachments/assets/9f75b204-8a93-44a5-860e-a5dfaff66ff1) |
|:-:|
| *Downforce Distribution over the updated frontwing* |

| ![Streamlines over Pressure 1](https://github.com/user-attachments/assets/c47a8cdd-3003-4411-9ca2-6b7f634a20ad) |
|:-:|
| *Surface LIC of velocity field streamlines superimposed over the coloured pressure field* |

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
| *Downforce Distribution on the surface (negative values indicate downforce, positive lift)* |

![Screenshot from 2024-12-02 12-19-27](https://github.com/user-attachments/assets/c687adab-3eed-4da8-a485-de5403ec9060)
|:--:| 
| *RANS Parameter Tuning Software* |

## Contributors

| Name | Email |
| :---: | :---: |
| Bhavtegh Singh Gill | bhavteghsinghgill.bt21aero@pec.edu.in |
| Aniket | aniket.bt21aero@pec.edu.in |
