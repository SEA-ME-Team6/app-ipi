#ifndef RACER_H
#define RACER_H

//#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Racer
{
public:
    Racer();
    ~Racer();

    void setGear(uint8_t gear);
    void set_steering_percent(float steering);
    void set_throttle_percent(float throttle);

    uint32_t getBatttery();
    uint8_t getGear() const;

private:
    /*
    PyObject *pModule, *pClass, *pInstance;
    PyObject *pVoltage;
    double voltage;
    */

    uint32_t batteryStatus;    //original resource
    uint8_t gearStatus; //original resource
};

#endif //Racer_H
