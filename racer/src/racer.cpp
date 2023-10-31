#include "racer.h"
#include <iostream>

Racer::Racer() {
    /*
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);
    */
}

Racer::~Racer() {
    /*
    std::cout << "piracer remove start" << std::endl;
    Py_XDECREF(pInstance);
    Py_XDECREF(pClass);
    Py_XDECREF(pModule);
    std::cout << "piracer remove finish" << std::endl;
    Py_FinalizeEx();
    */
}


void Racer::setGear(uint8_t gear){
    std::cout << "method set" << std::endl;
    gearStatus = gear;
}

uint32_t Racer::getBatttery() {
    /*
    pVoltage = PyObject_CallMethod(pInstance, "get_battery_voltage", NULL);
    voltage = PyFloat_AsDouble(pVoltage);
    batteryStatus = (uint32_t)((voltage/3-3.1)*100/1.1);
    return batteryStatus;
    */
}


uint8_t Racer::getGear() const{
    std::cout << "method get" << std::endl;
    return gearStatus;
}

