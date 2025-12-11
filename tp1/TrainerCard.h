#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"
#include <string>
#include <vector>
#include <tuple>

class TrainerCard : public Card {
    public:
        explicit TrainerCard(const std::string& trainerEffect = "Heal all your action pokemon",
                            const std::string& trainerName = "Energy");
        

        const std::string& getTrainerEffect() const;
        const std::string& getTrainerName() const;

        // override displayInfo -> same as pokemonCard
        void displayInfo() const override;

    private:
        std::string trainerEffect_;
};


#endif