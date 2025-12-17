#include "headers/Server.hpp"
#include <iostream>


void Server::printInfo() const {
    std::cout << "Network device of type: Server" << std::endl;
    NetworkDevice::printInfo();
    std::cout << "CPU Cores: " << cpuCores << std::endl;
}

void Server::ping() const {
    NetworkDevice::ping();
}

