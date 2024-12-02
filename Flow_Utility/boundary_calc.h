#pragma once
double calcSkinFriction(double reynolds);
double calcShearStress(double rho, double velocity, double skinFriction);
double calcFricVelocity(double shearStress, double rho);
double calcYPlus(double visc, double cellHeight, double fricVelocity);
double calcCellHeight(double visc, double yPlus, double fricVelocity);
double calcLayerThickness(double reynolds, double charLen);
