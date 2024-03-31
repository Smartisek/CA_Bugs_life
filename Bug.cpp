//
// Created by domal on 26/03/2024.
//

#include "Bug.h"

int Bug::getId() const{
    return id;
}

pair<int,int> Bug::getPosition() const{
    return position;
}


int Bug::getSize() const {
    return size;
}

string Bug::getStatus() {
    if(alive == 1){
        return "Alive";
    } else {
        return "Dead";
    }
}

string Bug::positionToString(pair<int,int> position){
    return "(" + to_string(position.first) + "," + to_string(position.second) + ")";
}

Direction Bug::getDirection() const{
    return direction;
}

string Bug::printBug(){
    return to_string(getId()) + " " + getType() + " " + positionToString(getPosition()) + " " + to_string(getSize()) +
    " " + directionToString(getDirection()) + " " + getStatus();
}

pair<int,int> Bug::setPosition(pair<int, int> positionNew){
    this -> position = positionNew;
}

string Bug::directionToString(Direction direction){
//    https://stackoverflow.com/questions/5093460/how-to-convert-an-enum-type-variable-to-a-string
    switch (direction) {
        case Direction::NORTH: return "North";
        case Direction::EAST: return "East";
        case Direction::SOUTH: return "South";
        case Direction::WEST: return "West";
        default: return "Unknown";
    }
}







