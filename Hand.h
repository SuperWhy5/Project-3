#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>
#include <sstream>
#include "Card.h"
#include "Deck.h"

class Hand{
    private: 
        std::vector<Card> hand;

    public: 
        Hand();

        Hand(Deck& deck, int N);

        std::string strHand();

        Card dealCard(int num);

        int getHandSize();
};

#endif // HAND_H_
