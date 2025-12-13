// PokemonCard.cpp
#include "PokemonCard.h"
#include <iostream>

// Constructor with two attacks inline
PokemonCard::PokemonCard(const std::string& pokemonName,
                         const std::string& pokemonType,
                         const std::string& familyName,
                         int evolutionLevel,
                         int maxHP,
                         int attack1EnergyCost,
                         const std::string& attack1Desc,
                         int attack1Damage,
                         int attack2EnergyCost,
                         const std::string& attack2Desc,
                         int attack2Damage)
    : Card(pokemonName),
      pokemonType_(pokemonType),
      familyName_(familyName),
      evolutionLevel_(evolutionLevel),
      maxHP_(maxHP),
      hp_(maxHP) {
        
    attacks_.push_back(std::make_tuple(attack1EnergyCost, 0, attack1Desc, attack1Damage));
    attacks_.push_back(std::make_tuple(attack2EnergyCost, 0, attack2Desc, attack2Damage));
}

// Simple constructor
PokemonCard::PokemonCard(const std::string& pokemonName,
                         const std::string& pokemonType,
                         const std::string& familyName,
                         int evolutionLevel,
                         int maxHP)
    : Card(pokemonName),
      pokemonType_(pokemonType),
      familyName_(familyName),
      evolutionLevel_(evolutionLevel),
      maxHP_(maxHP),
      hp_(maxHP) {
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

std::vector<PokemonCard::Attack>& PokemonCard::getAttacksMutable() {
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

void PokemonCard::addEnergyToAttack(size_t attackIndex) {
    if (attackIndex < attacks_.size()) {
        int& currentEnergy = std::get<1>(attacks_[attackIndex]);
        currentEnergy++;
    }
}

int PokemonCard::performAttack(size_t attackIndex) {
    if (attackIndex >= attacks_.size()) return 0;
    
    int energyCost = std::get<0>(attacks_[attackIndex]);
    int currentEnergy = std::get<1>(attacks_[attackIndex]);
    int damage = std::get<3>(attacks_[attackIndex]);
    
    if (currentEnergy >= energyCost) {
        return damage;
    }
    return 0;
}

void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card - Name: " << cardName 
              << ", Type: " << pokemonType_
              << ", Evolution Level: " << evolutionLevel_
              << " of the family \"" << familyName_ << "\""
              << ", HP: " << hp_ << "\n";
    std::cout << "\nAttacks:\n";
    for (size_t i = 0; i < attacks_.size(); ++i) {
        const Attack& a = attacks_[i];
        int energyCost = std::get<0>(a);
        int currentEnergy = std::get<1>(a);
        const std::string& desc = std::get<2>(a);
        int damage = std::get<3>(a);
        std::cout << "Attack #" << i << ":\n";
        std::cout << "Attack cost: " << energyCost << "\n";
        std::cout << "Attack current energy storage: " << currentEnergy << "\n";
        std::cout << "Attack description: " << desc << "\n";
        std::cout << "Attack damage: " << damage << "\n";
        if (i + 1 < attacks_.size()) {
            std::cout << "\n";
        }
    }
}
