#include "racer.h"
#include <iostream>

Racer::Racer() {
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);
}

Racer::~Racer() {
    Py_XDECREF(pInstance);
    Py_XDECREF(pClass);
    Py_XDECREF(pModule);
    Py_FinalizeEx();
}

void Racer::setSteering(float steering_) {
    steeringStatus = steering_;
}

void Racer::setThrottle(float throttle_) {
    throttleStatus = throttle_;
}

void Racer::setGear(uint8_t gear){
    gearStatus = gear;
}

void Racer::setLight(bool light){
    lightStatus = light;
}

float Racer::getSteering() const{
    return steeringStatus;
}

float Racer::getThrottle() const{
    return throttleStatus;
}

uint8_t Racer::getGear() const{
    return gearStatus;
}

bool Racer::getLight() const{
    return lightStatus;
}

void Racer::set_steering_percent(){
    float cureentsteering = getSteering();
    std::cout << "piracer set steering: " << cureentsteering << std::endl;
    PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", cureentsteering);
}

void Racer::set_throttle_percent(){
    float cureentthrottle = getThrottle();
    std::cout << "piracer set throttle: " << cureentthrottle << std::endl;
    PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", cureentthrottle);
    
    /*
    if (gearStatus == 1 || gearStatus == 3) {
        std::cout << "Throttle : " << throttle << std::endl;
        PyObject_CallMethod(tInstance, "set_throttle_percent", "(f)", throttle);
    }
    */
}
