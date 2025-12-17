#include "headers/Router.hpp"
#include <iostream>


void Router::printInfo() const {
     std::cout << "Network device of type: Router" << std::endl;
    NetworkDevice::printInfo();
    std::cout << "Routes stored: " << routingTableSize << std::endl;
}

void Router::ping() const {
    NetworkDevice::ping();
}

