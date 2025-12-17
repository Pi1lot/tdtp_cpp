#ifndef SERVER_H
#define SERVER_H

#include "NetworkDevice.hpp"

#include <stdio.h>
#include <string>

class Server : public NetworkDevice {
public:
    Server (const std::string& hostname, const std::string& ipAddress, const std::string& location,
           const std::string& vendor, const std::string& osVersion, int year,
           double powerConsumption, bool isCritical, int cpuCores)
        : NetworkDevice(hostname, ipAddress, location, vendor, osVersion, year,
        powerConsumption, isCritical),
          cpuCores(cpuCores) {}

    // Override printInfo to add CPU cores information
    void printInfo() const override;
    
    // Override ping
    void ping() const override;
    


private:

    int cpuCores; // nombre de coeurs CPU

};

#endif