#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "NetworkDevice.hpp"

#include <stdio.h>
#include <string>

class Router : public NetworkDevice {
public:
    Router (const std::string& hostname, const std::string& ipAddress, const std::string& location,
           const std::string& vendor, const std::string& osVersion, int year,
           double powerConsumption, bool isCritical, int routingTableSize)
        : NetworkDevice(hostname, ipAddress, location, vendor, osVersion, year,
        powerConsumption, isCritical),
          routingTableSize(routingTableSize) {}

    // Override printInfo to add routing table size
    void printInfo() const override;
    
    // Override ping
    void ping() const override;
    


private:

    int routingTableSize; // nombre de routes

};

#endif