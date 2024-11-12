/*Name: Ja'Vien Elmore
  My Class: CPSC 1021
  Date: 11/3/2024
  Desc: This is a card game. You are give a hand of cards from a shuffled deck. Pick the 
  higer number card than the computer too score. By playing your cards right, the person 
  with the highest final score wins.
  Extra Credit: User decides how many cards to draw which determines the amount of rounds.
  Time: 10 hors
*/

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Summary.h"
#include <iostream>
using namespace std;

int main() {

  vector<summaryCollect> Summary;
  int sumCountRounds = 0;
  bool run = true;
  while(run){
    cout << "Settings - How many cards should each player draw from the deck (15 max): ";
    int rounds;
    cin >> rounds;
    while(rounds > 15){
      cout << "Players cannot draw more than 15 cards each, try again: ";
      cin >> rounds;
    }
    sumCountRounds += rounds;
    cout << "Welcome to TigerGame!\nThe deck was shuffled and each player has drawn " << rounds << " cards.\n\n";

    // 1. Create a deck of cards and shuffle it.
    Deck deckOfCards;
    deckOfCards.shuffle();

    // 2. Create two players, each one with 6 cards in their hand.
    Player human(deckOfCards,rounds);
    Player computer(deckOfCards,rounds);
    // 3. Play five rounds. In each round:
    for(int i = 1; i <= rounds; i++){
      cout << "Round "; cout << i; cout << "\n-------\n";
      //    - Have computer deal a card from their hand.
      Card computerCard = computer.hand.dealCard(1);
      cout << "The computer plays: " << computerCard.strCard() << endl;
      if(computerCard.getColor() == computerCard.winner){
        computer.score += 50;    
        summaryCollect round(1,0,1,0,50);
        Summary.push_back(round);
        cout << "The computer wins this round!\n\n";
        cout << "Current Score: \n" <<"Human: " << human.score << "\nComputer: " << computer.score << "\n\n";
        continue;      }
      //    - Show human their hand of cards so that they can make a selection.
      cout << "Your hand: " << human.hand.strHand() << endl;
      cout << "Which card do you want to play? ";
      //    - Have human deal their card.
      int choice;
      cin >> choice;
      while(choice > human.hand.getHandSize()){
        cout << "You must pick a card in your deck, try again: ";
        cin >> choice;
      }
      Card humanCard = human.hand.dealCard(choice);
      cout << "\nYou played: " << humanCard.strCard() << endl;
      //    - Determine who won the round and update points accordingly.
      
      if(humanCard.getColor() == humanCard.winner){
        human.score += 50;    
        summaryCollect round(1,1,0,50,0);
        Summary.push_back(round);
        cout << "You win this round!\n\n";
        cout << "Current Score: \n" <<"Human: " << human.score << "\nComputer: " << computer.score << "\n\n";
        continue;
        // break; or continue;
      }
      if(humanCard.getValue() > computerCard.getValue()){
        cout << "You win this round!\n\n";
        human.score += humanCard.getValue() + computerCard.getValue();
        summaryCollect round(1,1,0,humanCard.getValue() + computerCard.getValue(),0);
        Summary.push_back(round);
      }
      else if(humanCard.getValue() < computerCard.getValue()){
        cout << "The computer wins this round!\n\n";
        computer.score += humanCard.getValue() + computerCard.getValue();
        summaryCollect round(1,0,1,0,humanCard.getValue() + computerCard.getValue());
        Summary.push_back(round);

      }
      else{
        cout << "Tie!\n\n";
        summaryCollect round(1,0,0,0,0);
        Summary.push_back(round);

      }
      //    - Print results for current round.
      cout << "Current Score: \n" <<"Human: " << human.score << "\nComputer: " << computer.score << "\n\n";
      // 4. Print final game results.
      if(i == rounds){
          cout << "FINAL SCORE: \n" <<"Human: " << human.score << "\nComputer: " << computer.score;
        if(humanCard.getValue() > computerCard.getValue()){
          cout << "\n\nYou have won!";
        }
        else{
          cout << "\n\nComputer has won!";
        }
      }
    }
    string playAgain;
    cout << "\n\nWould you like to play again (yes/no): ";
    cin >> playAgain;
    while(playAgain != "yes" && playAgain != "no"){
      cout << "you can only eneter yes or no, try again: ";
      cin >> playAgain;
    }
    if(playAgain == "no"){
      cout << Summary[1].roundSummary();
      int summaryRounds = 0;
      for(summaryCollect& round : Summary){
        summaryRounds++;
        cout << "Round: " << summaryRounds << "\n\n" <<
        "Computer points recieved: " << round.computer_points << "\n" <<
        "Human points recieved: " << round.human_points << "\n\n";
        if(summaryRounds == sumCountRounds){
          cout << "\n\nTOTALS: \n\n" << "COMPUTER: " << round.human_total <<
          "\n\nHUMAN: " <<round.computer_total;
        }
      }
      run = false;
    }
    else{
      cout << "\n\n";
    }
  }

  //Summary
  return 0;
}
