//#include "piracer.h"
//#include "PythonManager.h"
#include "BatteryServer.hpp"
#include <unistd.h>
#include <iostream>

int main() {
    //PythonManager pythonManager;
    //Piracer racer;

    BatteryServer batteryserver;
    int batteryVoltage = 0;
    
    //double batteryVoltage = racer.getVoltage();
    
    while (true) {
        batteryserver.run(batteryVoltage);
        std::cout << "Battery Voltage: " << batteryVoltage << " V" << std::endl;
        batteryVoltage += 1;
        sleep(1);
    }


    return 0;
}
