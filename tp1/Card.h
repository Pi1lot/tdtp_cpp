#ifndef TD3_EX2_CARD_H
#define TD3_EX2_CARD_H

#include <string>

class Card {
public:
    std::string cardName;

    explicit Card(const std::string& name) : cardName(name) {}

    virtual ~Card() = default;
    // implementation for the display method
    virtual void displayInfo() const = 0;
};

#endif
