#ifndef NETWORKINFRASTRUCTURE_HPP
#define NETWORKINFRASTRUCTURE_HPP

#include "NetworkDevice.hpp"

#include <string>
#include <vector>

class NetworkInfrastructure {

public:
    // Constructor
    NetworkInfrastructure(const std::string& name) : name(name) {}

    void addDevice(NetworkDevice* device);

    void listDevices() const;

    void searchDeviceByHostname(const std::string& hostname) const;

    void removeDeviceByHostname(const std::string& hostname);

    void averagePowerConsumptionByType(const std::string& deviceType) const;

    // Get infra name
    std::string getName() const { return name; }

private:
    std::string name;
    static const int MAX_DEVICES = 64;
    std::vector<NetworkDevice*> devices;

};

#endif