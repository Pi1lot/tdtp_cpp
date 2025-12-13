// TrainerCard.cpp
#include "TrainerCard.h"
#include "PokemonCard.h"
#include <iostream>

TrainerCard::TrainerCard(
        const std::string& trainerName,
        const std::string& trainerEffect)
    : Card(trainerName), trainerEffect_(trainerEffect)
{
}

const std::string& TrainerCard::getTrainerName() const {
    return cardName;
}

const std::string& TrainerCard::getTrainerEffect() const {
    return trainerEffect_;
}

void TrainerCard::setTrainerEffect(const std::string& effect) {
    trainerEffect_ = effect;
}

void TrainerCard::applyEffect(std::vector<PokemonCard*>& actionCards) {

    for (PokemonCard* pokemon : actionCards) {
        if (pokemon) {
            pokemon->setHP(pokemon->getMaxHP());
        }
    }
}

void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card - Name: " << cardName 
              << ", Effect: " << trainerEffect_ << "\n";
}
