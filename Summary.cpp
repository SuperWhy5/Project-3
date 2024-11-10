#include "Summary.h"
#include <sstream>

int summaryCollect::human_total;

int summaryCollect::computer_total;

int summaryCollect::human_won = 0;

int summaryCollect::computer_won = 0;

int summaryCollect::rounds = 0;

std::string summaryCollect::endGameMessage;

summaryCollect::summaryCollect() {}

summaryCollect::summaryCollect(int rounds, int human_won, int computer_won, int human_points, int computer_points)
    : human_points(0), computer_points(0) {
    
    this->rounds += rounds;
    this->human_won += human_won;
    this->computer_won += computer_won;
    this->human_points = human_points;
    this->computer_points = computer_points;
    human_total += human_points;
    computer_total += computer_points;
}


std::string summaryCollect::roundSummary(){
    std::stringstream ss;

    ss << "Total Rounds: "<< rounds <<
    "\n\nComputer Won: " << computer_won <<" rounds!" <<
    "\n\nHuman Won: " << human_won << " rounds!\n\n";

    return ss.str();
}