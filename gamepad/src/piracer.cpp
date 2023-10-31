#include "piracer.h"
#include <iostream>

Piracer::Piracer() {
    //Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);
}

Piracer::~Piracer() {
    std::cout << "piracer remove start" << std::endl;
    Py_XDECREF(pInstance);
    Py_XDECREF(pClass);
    Py_XDECREF(pModule);
    std::cout << "piracer remove finish" << std::endl;
    //Py_FinalizeEx();
}

double Piracer::getVoltage() {
    pVoltage = PyObject_CallMethod(pInstance, "get_battery_voltage", NULL);
    voltage = PyFloat_AsDouble(pVoltage);
    return voltage;
}

void Piracer::set_steering_percent(float steering) {
    PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", steering);
}

void Piracer::set_throttle_percent(float throttle) {
    PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", throttle);
}
