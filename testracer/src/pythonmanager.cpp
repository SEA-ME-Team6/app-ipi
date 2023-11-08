#include "pythonmanager.h"
#include <iostream>

PythonManager::PythonManager() {
    std::cout << "Python initialize" << std::endl;
    Py_Initialize();
}

PythonManager::~PythonManager() {
    Py_FinalizeEx();
    std::cout << "Python finalize" << std::endl;
}