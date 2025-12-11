#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "Card.h"
#include <string>

class EnergyCard : public Card {
public:
    explicit EnergyCard(const std::string& energyType = "");

    const std::string& getEnergyType() const;
    void setEnergyType(const std::string& energyType);

    // override displayInfo -> same as pokemonCard
    void displayInfo() const override;

private:
    std::string energyType_;
};

#endif