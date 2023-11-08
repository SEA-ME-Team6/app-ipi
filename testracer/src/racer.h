#ifndef RACER_H
#define RACER_H

//#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Racer
{
public:
    Racer();
    ~Racer();

private:
    PyObject *pModule, *pClass, *pInstance;
    PyObject *pVoltage;
    double voltage, voltage_level;
};

#endif //Racer_H
