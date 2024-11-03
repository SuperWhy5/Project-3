#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main() {

  cout << "Welcome to TigerGame!\nThe deck was shuffled and each player has drawn 6 cards.\n\n";

  // 1. Create a deck of cards and shuffle it.
  Deck deckOfCards;
  deckOfCards.shuffle();

  // 2. Create two players, each one with 6 cards in their hand.
  Player human(deckOfCards,6);
  Player computer(deckOfCards,6);
  // 3. Play five rounds. In each round:
  for(int i = 1; i < 6; i++){
    cout << "Round "; cout << i; cout << "\n-------\n";
    //    - Have computer deal a card from their hand.
    Card computerCard = computer.hand.dealCard(1);
    cout << "The computer plays: " << computerCard.strCard() << endl;
  
    //    - Show human their hand of cards so that they can make a selection.
    cout << "Your hand: " << human.hand.strHand() << endl;
    cout << "Which card do you want to play? ";
    //    - Have human deal their card.
    int choice;
    cin >> choice;
    Card humanCard = human.hand.dealCard(choice);
    cout << "You played: " << humanCard.strCard() << endl;
    //    - Determine who won the round and update points accordingly.
    if(humanCard.getValue() > computerCard.getValue()){
      cout << "You win this round!\n\n";
      human.score += humanCard.getValue() + computerCard.getValue();
    }
    else if(humanCard.getValue() < computerCard.getValue()){
      cout << "The computer wins this round!\n\n";
      computer.score += humanCard.getValue() + computerCard.getValue();
    }
    else{
      cout << "Tie!\n\n";
    }
    //    - Print results for current round.
    cout << "Current Score: \n" <<"Human: " << human.score << "\nComputer: " << computer.score << "\n\n";
    // 4. Print final game results.
    if(i == 5){
        cout << "FINAL SCORE: \n" <<"Human: " << human.score << "\nComputer: " << computer.score;
      if(humanCard.getValue() > computerCard.getValue()){
        cout << "\n\nYou have won!";
      }
      else{
        cout << "\n\nComputer has won!";
      }
    }
  }

  return 0;
}
