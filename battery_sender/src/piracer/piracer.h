#ifndef PIRACER_H
#define PIRACER_H

#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Piracer
{
public:
    Piracer();
    ~Piracer();
    double getVoltage();
    void set_steering_percent(float steering);
    void set_throttle_percent(float throttle);

private:
    PyObject *pModule, *pClass, *pInstance;
    PyObject *pVoltage;
    double voltage;
};

#endif //PIRACER_H
