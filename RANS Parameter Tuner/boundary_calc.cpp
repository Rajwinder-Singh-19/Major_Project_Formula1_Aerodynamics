#include <boundary_calc.h>
#include <math.h>
double calcSkinFriction(double reynolds){
    return pow((2*log10(reynolds) - 0.65),-2.3);
}
double calcShearStress(double rho, double velocity, double skinFriction){
    return 0.5*rho*velocity*velocity*skinFriction;
}
double calcFricVelocity(double shearStress, double rho){
    return sqrt(shearStress/rho);
}
double calcYPlus(double visc, double cellHeight, double fricVelocity){
    return (cellHeight*fricVelocity)/visc;
}
double calcCellHeight(double visc, double yPlus, double fricVelocity){
    return (2*yPlus*visc)/fricVelocity;
}
double calcLayerThickness(double reynolds, double charLen){
    return 0.38*charLen/pow(reynolds,0.2);
}
