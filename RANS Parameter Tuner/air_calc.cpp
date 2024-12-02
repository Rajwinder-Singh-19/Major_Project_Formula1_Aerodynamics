#include <air_constants_isa.h>
#include <air_calc.h>
#include <math.h>
double calcAirTemperature(double altitude_ft)
{
    if (int(altitude_ft) == 0)
    {
        return TEMPERATURE_AIR_SI;
    }

    double altitude_SI = altitude_ft * 3.048e-4;
    double temperature = TEMPERATURE_AIR_SI + TEMPERATURE_LAPSE_RATE_AIR_SI * altitude_SI;
    return temperature;
}
double calcAirPressure(double altitude_ft)
{
    if (int(altitude_ft) == 0)
    {
        return PRESSURE_AIR_SI;
    }

    double altitude_SI = altitude_ft * 3.048e-4;
    double pressure = PRESSURE_AIR_SI + PRESSURE_LAPSE_RATE_AIR_SI * altitude_SI;
    return pressure;
}
double calcAirRho(double altitude_ft)
{
    if (int(altitude_ft) == 0)
    {
        return RHO_AIR_SI;
    }

    return calcAirPressure(altitude_ft) / (GAS_CONSTANT_AIR_SI * calcAirTemperature(altitude_ft));
}

double calcAirVisc(double altitude_ft)
{
    if (int(altitude_ft) == 0)
    {
        return DY_VISC_AIR_SI/RHO_AIR_SI;
    }
    return (sqrt(calcAirTemperature(altitude_ft)) * 1.044e-6)/calcAirRho(altitude_ft);
}


