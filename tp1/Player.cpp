// Player.cpp
#include "Player.h"
#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include <iostream>
#include <algorithm>

Player::Player(const std::string& playerName)
    : playerName_(playerName)
{
}

Player::~Player() {
    // Clean up owned cards
    for (Card* c : benchCards_) {
        delete c;
    }
    for (PokemonCard* p : actionCards_) {
        delete p;
    }
}

const std::string& Player::getPlayerName() const {
    return playerName_;
}

const std::vector<Card*>& Player::getBenchCards() const {
    return benchCards_;
}

const std::vector<PokemonCard*>& Player::getActionCards() const {
    return actionCards_;
}

void Player::setPlayerName(const std::string& name) {
    playerName_ = name;
}

void Player::addCardToBench(Card* card) {
    if (card) {
        benchCards_.push_back(card);
    }
}

void Player::activatePokemonCard(size_t benchIndex) {
    if (benchIndex >= benchCards_.size()) {
        std::cout << "Invalid bench index!\n";
        return;
    }
    
    // Check if it's a PokemonCard using dynamic_cast
    PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards_[benchIndex]);
    if (!pokemon) {
        std::cout << "Card at index " << benchIndex << " is not a PokemonCard!\n";
        return;
    }
    
    // Remove from bench and add to action
    benchCards_.erase(benchCards_.begin() + benchIndex);
    actionCards_.push_back(pokemon);
    std::cout << playerName_ << " is activating a Pokemon Card: " << pokemon->getPokemonName() << "\n";
}

void Player::attachEnergyCard(size_t energyIndex, size_t pokemonIndex) {
    if (energyIndex >= benchCards_.size()) {
        std::cout << "Invalid energy card index!\n";
        return;
    }
    if (pokemonIndex >= actionCards_.size()) {
        std::cout << "Invalid pokemon index!\n";
        return;
    }
    
    // Check if it's an EnergyCard
    EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards_[energyIndex]);
    if (!energy) {
        std::cout << "Card at index " << energyIndex << " is not an EnergyCard!\n";
        return;
    }
    
    PokemonCard* pokemon = actionCards_[pokemonIndex];
    
    std::cout << playerName_ << " is attaching Energy Card of type " 
              << energy->getEnergyType() << " to the Pokemon " 
              << pokemon->getPokemonName() << "\n";
    
    // Add energy to all attacks
    auto& attacks = pokemon->getAttacksMutable();
    for (size_t i = 0; i < attacks.size(); ++i) {
        int& current = std::get<1>(attacks[i]);
        current++;
    }
    
    // Remove energy card from bench and delete it
    benchCards_.erase(benchCards_.begin() + energyIndex);
    delete energy;
}

void Player::displayBench() const {
    std::cout << "Bench cards for Player " << playerName_ << ":\n";
    if (benchCards_.empty()) {
        std::cout << "(empty)\n";
        return;
    }
    for (size_t i = 0; i < benchCards_.size(); ++i) {
        benchCards_[i]->displayInfo();
    }
}

void Player::displayAction() const {
    std::cout << "Action cards for Player " << playerName_ << ":\n";
    if (actionCards_.empty()) {
        std::cout << "(none)\n";
        return;
    }
    for (size_t i = 0; i < actionCards_.size(); ++i) {
        actionCards_[i]->displayInfo();
    }
}

void Player::attack(size_t myPokemonIndex, size_t attackIndex, Player& opponent, size_t opponentPokemonIndex) {
    if (myPokemonIndex >= actionCards_.size()) {
        std::cout << "Invalid attacker index!\n";
        return;
    }
    if (opponentPokemonIndex >= opponent.actionCards_.size()) {
        std::cout << "Invalid target index!\n";
        return;
    }
    
    PokemonCard* attacker = actionCards_[myPokemonIndex];
    PokemonCard* target = opponent.actionCards_[opponentPokemonIndex];
    
    const auto& attacks = attacker->getAttacks();
    if (attackIndex >= attacks.size()) {
        std::cout << "Only " << attacks.size() << " attacks exist.\n";
        return;
    }
    
    int damage = attacker->performAttack(attackIndex);
    if (damage > 0) {
        const std::string& attackName = std::get<2>(attacks[attackIndex]);
        
        std::cout << playerName_ << " attacking " << opponent.getPlayerName() 
                  << "'s Pokemon " << target->getPokemonName() 
                  << " with the Pokemon " << attacker->getPokemonName()
                  << " with its attack: " << attackName << "\n";
        std::cout << "Reducing " << damage << " from " << opponent.getPlayerName() 
                  << "'s Pokemon's HP\n";
        
        int newHP = target->getHP() - damage;
        target->setHP(newHP);
        
        if (target->getHP() <= 0) {
            std::cout << "Pokemon " << target->getPokemonName() << " fainted!\n";
        } else {
            std::cout << "Pokemon " << target->getPokemonName() << " is still alive\n";
        }
    } else {
        std::cout << attacker->getPokemonName() << " doesn't have enough energy for that attack!\n";
    }
}

void Player::useTrainer(size_t benchIndex) {
    if (benchIndex >= benchCards_.size()) {
        std::cout << "Invalid bench index!\n";
        return;
    }
    
    TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards_[benchIndex]);
    if (!trainer) {
        std::cout << "Card at index " << benchIndex << " is not a TrainerCard!\n";
        return;
    }
    
    std::cout << playerName_ << " is using the Trainer Card to \"" 
              << trainer->getTrainerEffect() << "\"\n";
    
    // Apply the effect: heal all action pokemon
    trainer->applyEffect(actionCards_);
    
    // Remove trainer card from bench and delete it
    benchCards_.erase(benchCards_.begin() + benchIndex);
    delete trainer;
}
