#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>
#include <sstream>

class Hand{
    private: 
        vector<Card> hand;

    public: 
        Hand();

        Hand(Deck deck, int N);

        std::string strHand();

        Card dealCArd(int num);

        int getHandSize();
};

#endif // HAND_H_
