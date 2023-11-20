#ifndef RACER_H
#define RACER_H

#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Racer
{
public:
    Racer();
    ~Racer();

    void setSteering(float steering);
    void setThrottle(float throttle);
    void setGear(uint8_t gear);
    void setLight(bool light);

    float getSteering() const;
    float getThrottle() const;
    uint8_t getGear() const;
    bool getLight() const;

    void set_steering_percent();
    void set_throttle_percent();

private:
    PyObject *pModule, *pClass, *pInstance;
   
    //original resource
    float steeringStatus = 0.0;
    float throttleStatus = 0.0;
    uint8_t gearStatus = 0; 
    bool lightStatus = false; 
};

#endif //Racer_H
