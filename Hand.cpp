#include "Hand.h"


Hand::Hand() : hand() {}

Hand::Hand(Deck& deck, int N) {
    for(int i = 1; i < N+1; i++){
        hand.push_back(deck.drawCard());
    }
}

std::string Hand::strHand() {
    std::stringstream ss;
    int pos = 0;
    
    for(Card& card : hand){
        pos++;
        ss << "[" << pos << "] " << card.strCard() <<" ";
    }

    return ss.str();
}
    
Card Hand::dealCard(int num) {
    Card dealt = hand[num-1];
    hand.erase(hand.begin());
    return dealt; 

}

int Hand::getHandSize() {
    return sizeof(hand);
}
