#include "headers/Switch.hpp"
#include <iostream>


void Switch::printInfo() const {
    std::cout << "Network device of type: Switch" << std::endl;
    NetworkDevice::printInfo();
    std::cout << "Ports count: " << portCount << std::endl;
}

void Switch::ping() const {
    NetworkDevice::ping();
}

