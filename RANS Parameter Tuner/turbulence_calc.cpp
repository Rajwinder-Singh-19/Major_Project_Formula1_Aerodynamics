#include <turbulence_calc.h>
#include <math.h>
double calcKE(double intensity, double velocity){
    return (1.5)*(pow((intensity*velocity),2));
}
double calcOmega(double intensity, double velocity, double char_len){
    double k = calcKE(intensity, velocity);
    double w = pow(k,0.5)/(pow(C_MU,0.25)*0.07*char_len);
    return w;
}
double calcEpsilon(double intensity, double velocity, double char_len){
    double k = calcKE(intensity, velocity);
    double e = pow(C_MU,0.75)*pow(k, 1.5)/(0.07*char_len);
    return e;
}
