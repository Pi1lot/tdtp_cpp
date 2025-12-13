#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <string>
#include <vector>
#include <tuple>

class PokemonCard : public Card {
public:
    // Attack tuple: energyCost, currentEnergy, description, damage
    using Attack = std::tuple<int /*energyCost*/, int /*currentEnergy*/, std::string /*description*/, int /*damage*/>;

    // Constructor with two attacks inline (as used in battle.cpp)
    PokemonCard(const std::string& pokemonName,
                const std::string& pokemonType,
                const std::string& familyName,
                int evolutionLevel,
                int maxHP,
                int attack1EnergyCost,
                const std::string& attack1Desc,
                int attack1Damage,
                int attack2EnergyCost,
                const std::string& attack2Desc,
                int attack2Damage);

    // Simple constructor (for backward compatibility)
    explicit PokemonCard(const std::string& pokemonName,
                         const std::string& pokemonType = "",
                         const std::string& familyName = "",
                         int evolutionLevel = 0,
                         int maxHP = 0);

    const std::string& getPokemonName() const;
    const std::string& getPokemonType() const;
    const std::string& getFamilyName() const;
    int getEvolutionLevel() const;
    int getMaxHP() const;
    int getHP() const;
    const std::vector<Attack>& getAttacks() const;
    std::vector<Attack>& getAttacksMutable();

    void setPokemonName(const std::string& name);
    void setPokemonType(const std::string& type);
    void setFamilyName(const std::string& family);
    void setEvolutionLevel(int level);
    void setMaxHP(int mhp);
    void setHP(int newHP);

    bool addAttack(const Attack& atk);
    bool setAttack(size_t index, const Attack& atk);

    void addEnergyToAttack(size_t attackIndex);

    int performAttack(size_t attackIndex);

    void displayInfo() const override;

private:
    std::string pokemonType_;
    std::string familyName_;
    int evolutionLevel_;
    int maxHP_;
    int hp_;
    std::vector<Attack> attacks_;
};

#endif
