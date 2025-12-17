#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "NetworkDevice.hpp"

#include <stdio.h>
#include <string>

class Switch : public NetworkDevice {
public:
    Switch (const std::string& hostname, const std::string& ipAddress, const std::string& location,
           const std::string& vendor, const std::string& osVersion, int year,
           double powerConsumption, bool isCritical, int portCount)
        : NetworkDevice(hostname, ipAddress, location, vendor, osVersion, year,
        powerConsumption, isCritical),
          portCount(portCount) {}

    // Override printInfo to add port count
    void printInfo() const override;
    
    // Override ping
    void ping() const override;
    


private:

    int portCount; // nombre de ports

};

#endif