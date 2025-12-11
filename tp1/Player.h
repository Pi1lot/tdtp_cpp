#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
public:

    const std::string& getEnergyType() const;
    void setEnergyType(const std::string& energyType);

    // override displayInfo -> same as pokemonCard
    void displayInfo() const override;

private:
    std::string energyType_;
};

#endif