#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"
#include <string>
#include <vector>

// Forward declaration for Player class usage
class PokemonCard;

class TrainerCard : public Card {
public:
    explicit TrainerCard(const std::string& trainerName = "Trainer",
                         const std::string& trainerEffect = "Heal all your action pokemon");

    const std::string& getTrainerEffect() const;
    const std::string& getTrainerName() const;
    void setTrainerEffect(const std::string& effect);

    void applyEffect(std::vector<PokemonCard*>& actionCards);

    void displayInfo() const override;

private:
    std::string trainerEffect_;
};


#endif