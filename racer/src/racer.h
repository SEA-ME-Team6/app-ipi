#ifndef RACER_H
#define RACER_H

#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Racer
{
public:
    Racer();
    ~Racer();

    void setGear(uint8_t gear);
    void setLight(bool light);

    uint8_t getGear() const;
    bool getLight() const;

    void set_steering_percent(float currentsteering);
    void set_throttle_percent(float currentthrottle);

private:
    PyObject *pModule, *pClass, *pInstance;
   
    //original resource
    uint8_t gearStatus = 0; 
    bool lightStatus = false; 
};

#endif //Racer_H
