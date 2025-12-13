#include "EnergyCard.h"
#include <iostream>

EnergyCard::EnergyCard(const std::string& energyType)
    : Card("Energy"), energyType_(energyType) {
}

const std::string& EnergyCard::getEnergyType() const {
    return energyType_;
}

void EnergyCard::setEnergyType(const std::string& energyType) {
    energyType_ = energyType;
}

void EnergyCard::displayInfo() const {
    std::cout << "Energy Card - Type: " << energyType_ << "\n";
}
