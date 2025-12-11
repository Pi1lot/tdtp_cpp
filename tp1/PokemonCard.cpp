// PokemonCard.cpp
#include "PokemonCard.h"
#include <iostream>

PokemonCard::PokemonCard(const std::string& pokemonName,
                         const std::string& pokemonType,
                         const std::string& familyName,
                         int evolutionLevel,
                         int maxHP,
                         int hp)
    : Card(pokemonName),
      pokemonType_(pokemonType),
      familyName_(familyName),
      evolutionLevel_(evolutionLevel),
      maxHP_(maxHP),
      hp_(hp) {
}

const std::string& PokemonCard::getPokemonName() const {
    return cardName;
}

const std::string& PokemonCard::getPokemonType() const {
    return pokemonType_;
}

const std::string& PokemonCard::getFamilyName() const {
    return familyName_;
}

int PokemonCard::getEvolutionLevel() const {
    return evolutionLevel_;
}

int PokemonCard::getMaxHP() const {
    return maxHP_;
}

int PokemonCard::getHP() const {
    return hp_;
}

const std::vector<PokemonCard::Attack>& PokemonCard::getAttacks() const {
    return attacks_;
}

void PokemonCard::setPokemonName(const std::string& name) {
    cardName = name;
}

void PokemonCard::setPokemonType(const std::string& type) {
    pokemonType_ = type;
}

void PokemonCard::setFamilyName(const std::string& family) {
    familyName_ = family;
}

void PokemonCard::setEvolutionLevel(int level) {
    evolutionLevel_ = level;
}

void PokemonCard::setMaxHP(int mhp) {
    maxHP_ = mhp;
    if (hp_ > maxHP_) hp_ = maxHP_;
}

void PokemonCard::setHP(int newHP) {
    if (newHP < 0) newHP = 0;
    if (maxHP_ > 0 && newHP > maxHP_) newHP = maxHP_;
    hp_ = newHP;
}

bool PokemonCard::addAttack(const Attack& atk) {
    if (attacks_.size() >= 2) return false;
    attacks_.push_back(atk);
    return true;
}

bool PokemonCard::setAttack(size_t index, const Attack& atk) {
    if (index >= attacks_.size()) return false;
    attacks_[index] = atk;
    return true;
}

// We display every available information about the Pokemon card
void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card: " << cardName << '\n';
    std::cout << " Type: " << pokemonType_ << '\n';
    std::cout << " Family: " << familyName_ << '\n';
    std::cout << " Evolution level: " << evolutionLevel_ << '\n';
    std::cout << " HP: " << hp_ << " / " << maxHP_ << '\n';
    std::cout << " Attacks: " << attacks_.size() << '\n';
    for (size_t i = 0; i < attacks_.size(); ++i) {
        const Attack& a = attacks_[i];
        int energyCost = std::get<0>(a);
        int currentEnergy = std::get<1>(a);
        const std::string& desc = std::get<2>(a);
        int damage = std::get<3>(a);
        std::cout << "  [" << i << "] cost=" << energyCost
                  << " cur=" << currentEnergy
                  << " dmg=" << damage
                  << " desc='" << desc << "'\n";
    }
}
