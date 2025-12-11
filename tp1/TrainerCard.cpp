// PokemonCard.cpp
#include "TrainerCard.h"
#include <iostream>

TrainerCard::TrainerCard(
        const std::string& trainerName,
        const std::string& trainerEffect)
    : Card(trainerName)
    {
}

const std::string& TrainerCard::getTrainerName() const {
    return cardName;
}

// We display every available information about the Pokemon card
void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card: " << cardName << '\n';
    std::cout << " Trainer Effect: " << trainerEffect_ << '\n';

}

