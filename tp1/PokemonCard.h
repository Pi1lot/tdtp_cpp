#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <string>
#include <vector>
#include <tuple>

class PokemonCard : public Card {
public:
    using Attack = std::tuple<int /*energyCost*/, int /*currentEnergy*/, std::string /*description*/, int /*damage*/>;

    explicit PokemonCard(const std::string& pokemonName,
                         const std::string& pokemonType = "",
                         const std::string& familyName = "",
                         int evolutionLevel = 0,
                         int maxHP = 0,
                         int hp = 0);

    const std::string& getPokemonName() const;
    const std::string& getPokemonType() const;
    const std::string& getFamilyName() const;
    int getEvolutionLevel() const;
    int getMaxHP() const;
    int getHP() const;
    const std::vector<Attack>& getAttacks() const;

    void setPokemonName(const std::string& name);
    void setPokemonType(const std::string& type);
    void setFamilyName(const std::string& family);
    void setEvolutionLevel(int level);
    void setMaxHP(int mhp);
    void setHP(int newHP);

    bool addAttack(const Attack& atk);
    bool setAttack(size_t index, const Attack& atk);

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
