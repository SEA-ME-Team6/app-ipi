#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Battery
{
public:
    Battery();
    ~Battery();

    uint32_t getBatttery();

private:
    PyObject *pModule, *pClass, *pInstance;
    PyObject *pVoltage;
    double voltage;
   
    uint32_t batteryStatus; 
};