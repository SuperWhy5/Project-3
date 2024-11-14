/*Name: Ja'Vien Elmore
  My Class: CPSC 1021
  Date: 11/3/2024
  Desc: This is a card game. You are give a hand of cards from a shuffled deck. Pick the 
  higer number card than the computer too score. By playing your cards right, the person 
  with the highest final score wins.
  Extra Credit (all three extra credits): 
  - User decides how many cards to draw which determines the amount of rounds.
  - At the conclusion of the game a summary is displayed: How many rounds each player won
    how pany points each player recieved in each round, and the total points earned 
    through all round.
  - The special Tiger card ends the round immediately and the player who plays the card 
    recieves exactly 50 points.
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

  //This loop will run for as long as the user agree's to keep playing.
  while(run){

    //This will determine how many rounds are played.
    cout << "Settings - How many cards should each player draw from the deck (15 max): ";
    
    int rounds;
    
    cin >> rounds;
    //This is input validation.
    while(rounds > 15){
      cout << "Players cannot draw more than 15 cards each, try again: ";

      cin >> rounds;
    }

    //This keeps track of the total rounds and is displayed further in the code (not just the rounds selected for the first playthrough).
    sumCountRounds += rounds;

    //Welcoming
    cout << "Welcome to TigerGame!\nThe deck was shuffled and each player has drawn " << rounds << " cards.\n\n";

    // 1. Create a deck of cards and shuffle it.
    Deck deckOfCards;
    
    //Shuffle the deck.
    deckOfCards.shuffle();

    // 2. Create two players, each one with 6 cards in their hand.
    Player human(deckOfCards,rounds);

    Player computer(deckOfCards,rounds);

    // 3.This for loop is used to run the game for how ever many "rounds" / cards the player selected (EXTRA CREDIT).
    for(int i = 1; i <= rounds; i++){

      //First we display what round it is.
      cout << "Round "; cout << i; cout << "\n-------\n";

      //Have computer deal a card from their hand.
      Card computerCard = computer.hand.dealCard(1);

      //Display what the computer selected.
      cout << "The computer plays: " << computerCard.strCard() << endl;

      /*The purpose of this (IF statement) is to determine if the special Tiger card was played
        if it was played then it utilized the "continue" key word to continue on to the next
        round and update the score accordingly (EXTRA CREDIT).
        */
      if(computerCard.getColor() == computerCard.winner){

        computer.score += 50;    

        summaryCollect round(1,0,1,0,50);

        Summary.push_back(round);

        cout << "The computer wins this round!\n\n";

        cout << "Current Score: \n" <<"Human: " << human.score << "\nComputer: " << computer.score << "\n\n";
        continue;
        }

      //    - Show human their hand of cards so that they can make a selection.
      cout << "Your hand: " << human.hand.strHand() << endl;

      cout << "Which card do you want to play? ";

      //    - Have human deal their card.
      int choice;

      cin >> choice;

      //This is input validation that ensures the user can only pick from the cards remaining from their hand.
      while(choice > human.hand.getHandSize()){

        cout << "You must pick a card in your deck, try again: ";

        cin >> choice;
      }

      //Once the user has picked a valid card in their hand, they can now deal that card here.
      Card humanCard = human.hand.dealCard(choice);

      //Display what card they played.
      cout << "\nYou played: " << humanCard.strCard() << endl;

      //Determine who won the round and update points accordingly.
      //Specifically this first if statement is for the special Tiger card (EXTRA CREDIT).
      if(humanCard.getColor() == humanCard.winner){

        human.score += 50;    

        summaryCollect round(1,1,0,50,0);

        Summary.push_back(round);

        cout << "You win this round!\n\n";

        cout << "Current Score: \n" <<"Human: " << human.score << "\nComputer: " << computer.score << "\n\n";
        continue;
      }
      else if(humanCard.getValue() > computerCard.getValue()){

        //Tell the user they won.
        cout << "You win this round!\n\n";

        //Here we are updating the users score as an accumulation of both playes cards.
        human.score += humanCard.getValue() + computerCard.getValue();

        /*The "summaryCollect" is a class init that uses a constructor to collect the total game
          summary that will be shown later (EXTRA CREDIT)*/
        summaryCollect round(1,1,0,humanCard.getValue() + computerCard.getValue(),0);

        //Here we push the round object we just created into a vector that will be looped throug at the end (EXTRA CREDIT)
        Summary.push_back(round);
      }
      //same thing applies for the next else if and else statments, however some data is changed.
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

    //used to collect user input to play again.
    string playAgain;

    //Now we are asking if they would like to play again.
    cout << "\n\nWould you like to play again (yes/no): ";

    cin >> playAgain;

    //This is input validation to ensure the user only says yes or no.
    while(playAgain != "yes" && playAgain != "no"){

      cout << "you can only eneter yes or no, try again: ";

      cin >> playAgain;
    }

    /*If the user says no we first print the first round from the vector Summary. Then for the rest of the 
      rounds we pushed into the Summary vector we will display the information utilizing the roundsSummary
      member function.*/
    if(playAgain == "no"){

      cout << Summary[1].roundSummary();

      int summaryRounds = 0;

      for(summaryCollect& round : Summary){
        
        summaryRounds++;

        cout << "Round: " << summaryRounds << "\n\n" <<
        "Computer points recieved: " << round.computer_points << "\n" <<
        "Human points recieved: " << round.human_points << "\n\n";

        /*Once all the rounds have been displayed this if statement will show the total points 
        each played recieved through out the entirety of the game an accumulation of every 
        single round.*/
        if(summaryRounds == sumCountRounds){

          cout << "\n\nTOTALS: \n\n" << "COMPUTER: " << round.human_total <<
          "\n\nHUMAN: " <<round.computer_total;
        }
      }

      //Setting run to false will stop the loop and permanently end the game.
      run = false;

    }

    //This else statment keeps the game live.
    else{

      cout << "\n\n";

    }
  }

  return 0;
}
