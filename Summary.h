#ifndef SUMMARY_H
#define SUMMARY_H

#include <iostream>

class summaryCollect{
    public:
        static int human_total;

        static int computer_total;

        static int human_won;

        static int computer_won;

        int human_points;

        int computer_points;

        static int rounds;

        static std::string endGameMessage;

        summaryCollect();

        summaryCollect(int rounds, int human_won, int computer_won, int human_points, int computer_points);

        std::string roundSummary();

};

#endif