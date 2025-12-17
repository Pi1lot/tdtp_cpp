#include "headers/Server.hpp"
#include "headers/Router.hpp"
#include "headers/Switch.hpp"
#include "headers/NetworkInfrastructure.hpp"
#include <iostream>

int main() {
    Server server("web-server-01", "192.168.1.100", "Paris Datacenter",
                  "Dell", "Ubuntu 22.04", 2023, 450.0, true, 16);
    
    Server server2("web-server-02", "192.168.1.101", "Paris Datacenter",
                "Dell", "Ubuntu 22.04", 2023, 363.0, true, 16);

    Router router("core-router-01", "192.168.1.1", "Paris Datacenter",
                  "Cisco", "IOS XE 17.3", 2022, 300.0, true, 256);
    
    Switch backboneSwitch("backbone-switch-01", "192.168.1.254", "Paris Datacenter",
                         "HP", "ArubaOS 10.5", 2021, 110.0, false, 48);

    Switch networkSwitch("access-switch-01", "192.168.1.2", "Paris Datacenter",
                         "HP", "ArubaOS 10.5", 2021, 150.0, false, 48);

    std::cout << "\r" << std::endl;
    
    // Test printInfo
    std::cout << "\n printInfo" << std::endl;
    std::cout << "\r" << std::endl;

    server.printInfo();
    std::cout << "\r" << std::endl;

    router.printInfo();
    std::cout << "\r" << std::endl;

    networkSwitch.printInfo();

    std::cout << "\r" << std::endl;
    std::cout << "\r" << std::endl;
    std::cout << "\r" << std::endl;

    
    // Test ping
    std::cout << "\nping" << std::endl;
    std::cout << "\r" << std::endl;

    server.ping();
    std::cout << "\r" << std::endl;

    router.ping();
    std::cout << "\r" << std::endl;

    networkSwitch.ping();
    std::cout << "\r" << std::endl;


    std::cout << "INFRASTRUCTURE DEMO :\n" << std::endl;

    std::cout << "\r" << std::endl;


    NetworkInfrastructure infra("Paris Datacenter");

    // Add devices to infrastructure
    std::cout << "Adding devices to the infrastructure" << std::endl;
    // I first add the switch with hostname access-switch-01 to see the sorting process
    infra.addDevice(&server);
    infra.addDevice(&backboneSwitch);
    infra.addDevice(&router);
    infra.addDevice(&server2);
    infra.addDevice(&networkSwitch);
    std::cout << "\r" << std::endl;

    std::cout << "Listing devices" << std::endl;
    infra.listDevices();
    std::cout << "\r" << std::endl;

    // Search device by hostname
    std::cout << "Searching by hostname" << std::endl;
    infra.searchDeviceByHostname("core-router-01");
    std::cout << std::endl;
    infra.searchDeviceByHostname("unknown-device");
    std::cout << "\r" << std::endl;

    // Average power consumption
    std::cout << "Average power comsumption by type" << std::endl;
    infra.averagePowerConsumptionByType("Server");
    infra.averagePowerConsumptionByType("Router");
    infra.averagePowerConsumptionByType("Switch");
    std::cout << "\r" << std::endl;

    std::cout << "Deleteing device by hostname" << std::endl;
    infra.removeDeviceByHostname("access-switch-01");
    std::cout << "\r" << std::endl;

    std::cout << "List after deletion" << std::endl;
    infra.listDevices();

    return 0;
}
