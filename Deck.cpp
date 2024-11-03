#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <sstream>

Deck::Deck(){
    for (int i = 1; i < 16; i++){
        Card card(i,Card::purple);
        deck.push_back(card);
    }
    for (int k = 1; k < 11; k++){
        Card card(k,Card::orange);
        deck.push_back(card);
    }
    for (int j = 6; j < 11; j++){
        Card card(j,Card::black);
        deck.push_back(card);
    }


}

void Deck::shuffle() {
    srand(unsigned(time(0)));
    random_shuffle(deck.begin(), deck.end());
}

Card Deck::drawCard() {
    Card selected = deck[0];
    deck.erase(deck.begin());
    return selected;
}

int Deck::getDeckSize() {

    return sizeof(deck);
}

std::string Deck::revealDeck(){
    std::stringstream ss;
    for (Card& card : deck){
        ss << card.strCard();
    }
    return ss.str();
}




