#ifndef CARD_H_
#define CARD_H_

#include <string>

class Card{
    public: 
        enum Color {purple, orange, black};

        Card();

        Card(int rank, Color color);

        std::string strCard();

        int getRank();

        Color getColor();

        int getValue();

        friend std::ostream& operator<<(std::ostream& os, Color color);

    private: 
        int rank = 0;

        Color color = purple;
        
        int value = 0;
    
};
  

#endif
