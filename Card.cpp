#include <sstream>
#include "Card.h"

Card::Card() {}

Card::Card(int rank, Color color){
    this->rank = rank;
    this->color = color;
    if(color == purple){
        value = rank;
    }
    if(color == orange){
        value = rank * 2;
    }
    if(color == black){
        value = rank * 3;
    }
    if(color == tiger){
        value = rank;
    }
}

std::string Card::strCard(){
    std::stringstream ss;
    ss << color << ":" << rank;
    return ss.str();
}

int Card::getRank(){
    return rank;
}

Card::Color Card::getColor(){
    return color;
}

int Card::getValue(){
    return value;
}

std::ostream& operator<<(std::ostream& os, Card::Color color) {
    switch (color) {
        case Card::Color::purple: os << "purple"; break;
        case Card::Color::orange: os << "orange"; break;
        case Card::Color::black:  os << "black";  break;
        case Card::Color::tiger:  os << "tiger";  break;
    }
    return os;
}