#ifndef RACER_H
#define RACER_H

//#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Racer
{
public:
    Racer();
    ~Racer();
    void set_steering_percent(float steering);
    void set_throttle_percent(float throttle);
    uint32_t getBatttery();

private:
    PyObject *pModule, *pClass, *pInstance;
    PyObject *pVoltage;
    double voltage;
    uint32_t voltage_level;
};

#endif //Racer_H
