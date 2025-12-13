#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

// Forward declarations
class Card;
class PokemonCard;
class EnergyCard;
class TrainerCard;

class Player {
public:
    explicit Player(const std::string& playerName = "");
    ~Player();

    // Getters
    const std::string& getPlayerName() const;
    const std::vector<Card*>& getBenchCards() const;
    const std::vector<PokemonCard*>& getActionCards() const;

    // Setters
    void setPlayerName(const std::string& name);    

    void addCardToBench(Card* card);
    
    void activatePokemonCard(size_t benchIndex);

    void attachEnergyCard(size_t energyIndex, size_t pokemonIndex);
    
    void displayBench() const;
    
    void displayAction() const;
    
    void attack(size_t myPokemonIndex, size_t attackIndex, Player& opponent, size_t opponentPokemonIndex);
    
    void useTrainer(size_t benchIndex);

private:
    std::string playerName_;
    std::vector<Card*> benchCards_;
    std::vector<PokemonCard*> actionCards_;
};

#endif
