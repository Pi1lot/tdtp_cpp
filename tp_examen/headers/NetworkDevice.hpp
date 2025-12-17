#ifndef NETWORKDEVICE_HPP
#define NETWORKDEVICE_HPP

#include <string>


class NetworkDevice {
public:

    // Fonction ping that return the self ipadress and self hostname
    virtual void ping() const = 0;
    
    //Destructor
    virtual ~NetworkDevice() = default;
    
    // constructor
    NetworkDevice(const std::string& hostname, const std::string& ipAddress, const std::string& location,
                  const std::string& vendor, const std::string& osVersion, int year,
                  double powerConsumption, bool isCritical)
        : hostname(hostname), ipAddress(ipAddress), location(location),
          vendor(vendor), osVersion(osVersion), year(year),
          powerConsumption(powerConsumption), isCritical(isCritical) {}

    // constructor par defaut
    NetworkDevice() : hostname(""), ipAddress(""), location(""),
                      vendor(""), osVersion(""), year(0),
                      powerConsumption(0.0), isCritical(false) {}

    // constructor de copie
    NetworkDevice(const NetworkDevice& other)
        : hostname(other.hostname), ipAddress(other.ipAddress), location(other.location),
          vendor(other.vendor), osVersion(other.osVersion), year(other.year),
          powerConsumption(other.powerConsumption), isCritical(other.isCritical) {}

    // printInfo
    virtual void printInfo() const = 0;

    // Getters
    std::string getHostname() const { return hostname; }
    std::string getIpAddress() const { return ipAddress; }
    std::string getLocation() const { return location; }
    std::string getVendor() const { return vendor; }
    std::string getOsVersion() const { return osVersion; }
    int getYear() const { return year; }
    double getPowerConsumption() const { return powerConsumption; }
    bool getIsCritical() const { return isCritical; }

    // Setters
    void setHostname(const std::string& hn) { hostname = hn; }
    void setIpAddress(const std::string& ip) { ipAddress = ip; }
    void setLocation(const std::string& loc) { location = loc; }
    void setVendor(const std::string& ven) { vendor = ven; }
    void setOsVersion(const std::string& os) { osVersion = os; }
    void setYear(int yr) { year = yr; }
    void setPowerConsumption(double pc) { powerConsumption = pc; }
    void setIsCritical(bool ic) { isCritical = ic; }

private:
    std::string hostname;
    std::string ipAddress;
    std::string location;
    std::string vendor;
    std::string osVersion;
    int year;
    double powerConsumption;
    bool isCritical;

};

#endif