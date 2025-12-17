#include "headers/NetworkInfrastructure.hpp"
#include <iostream>
#include <algorithm>

void NetworkInfrastructure::addDevice(NetworkDevice* device) {
    if (devices.size() >= MAX_DEVICES) {
        std::cout << "Maximum capacity reached. (" << MAX_DEVICES << ")" << std::endl;
        return;
    }

    // Don't add if already present in the vector
    for (const auto& dev : devices) {
        if (dev->getHostname() == device->getHostname()) {
            std::cout << "Device with hostname " << device->getHostname() << " already present." << std::endl;
            return;
        }
    }

    // Add the device if not already present
    devices.push_back(device);
    std::cout << "Device " << device->getHostname() << " added to " << name << std::endl;
}

void NetworkInfrastructure::listDevices() const {
    std::cout << "Current devices in infrastructure: " << name << std::endl;

    // Sort by hostname before listing
    std::vector<NetworkDevice*> sortedDevices = devices;
    std::sort(sortedDevices.begin(), sortedDevices.end(), [](NetworkDevice* a, NetworkDevice* b) {
        return a->getHostname() < b->getHostname();
    });

    for (const auto& device : sortedDevices) {
        device->printInfo();
        std::cout << "##################" << std::endl;
    }
}

void NetworkInfrastructure::searchDeviceByHostname(const std::string& hostname) const {
    auto it = std::find_if(devices.begin(), devices.end(), [&hostname](NetworkDevice* device) {
        return device->getHostname() == hostname;
    });

    if (it != devices.end()) {
        std::cout << "Device found:" << std::endl;
        (*it)->printInfo();
    } else {
        std::cout << "Device with hostname " << hostname << " unknown" << std::endl;
    }
}

void NetworkInfrastructure::removeDeviceByHostname(const std::string& hostname) {
    auto it = std::remove_if(devices.begin(), devices.end(), [&hostname](NetworkDevice* device) {
        return device->getHostname() == hostname;
    });

    if (it != devices.end()) {
        devices.erase(it, devices.end());
        std::cout << "Device with hostname " << hostname << " deleted." << std::endl;
    } else {
        std::cout << "Device with hostname " << hostname << " unknown" << std::endl;
    }
}

void NetworkInfrastructure::averagePowerConsumptionByType(const std::string& deviceType) const {
    double totalPower = 0.0;
    int count = 0;

    for (const auto& device : devices) {
        std::string typeName = typeid(*device).name();
        if (typeName.find(deviceType) != std::string::npos) {
            totalPower += device->getPowerConsumption();
            count++;
        }
    }

    if (count > 0) {
        double average = totalPower / count;
        std::cout << "Average power for type " << deviceType << " devices : " << average << " W" << std::endl;
    } else {
        std::cout << "Unknown device" << deviceType << std::endl;
    }
}


