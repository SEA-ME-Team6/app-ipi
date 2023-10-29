#include "racer.h"
#include <iostream>

Racer::Racer() {
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);
}

Racer::~Racer() {
    std::cout << "piracer remove start" << std::endl;
    Py_XDECREF(pInstance);
    Py_XDECREF(pClass);
    Py_XDECREF(pModule);
    std::cout << "piracer remove finish" << std::endl;
    Py_FinalizeEx();
}

double Racer::getVoltage() {
    pVoltage = PyObject_CallMethod(pInstance, "get_battery_voltage", NULL);
    voltage = PyFloat_AsDouble(pVoltage);
    return voltage;
}
