#include "headers/NetworkDevice.hpp"
#include <iostream>


void NetworkDevice::ping() const {
    std::cout << "Hostname: " << getHostname() << ", IP Address: " << getIpAddress() << std::endl;
}

void NetworkDevice::printInfo() const {

    // delegating printing Network device of type ... in the child classes

    std::cout << "Hostname : " << getHostname() << "\n";
    std::cout << "IP address : " << getIpAddress() << "\n";
    std::cout << "Location : " << getLocation() << "\n";
    std::cout << "Vendor : " << getVendor() << "\n";
    std::cout << "OS Version : " << getOsVersion() << "\n";
    std::cout << "Installed in : " << getYear() << "\n";

    if (getIsCritical()) {
        std::cout << "This device is critical\n";
    } else {
        std::cout << "This device is not critical\n";
    }

    std::cout << "Power Consumption : " << getPowerConsumption() << " W\n";

}