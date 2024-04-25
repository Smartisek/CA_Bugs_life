//
// Created by domal on 26/03/2024.
//

#include "Hopper.h"

Hopper::Hopper(int id, int x, int y, Direction direction, int size, int hop) : Bug(id, x, y, direction, size){ hopLength = hop;} // constructor

int Hopper::getHopLength() const{
    return hopLength;
};

string Hopper::getType() const {
            return "Hopper";
}

void Hopper::move() {
    pair<int,int> newPosition = getPosition();
//        when way is blocked meaning bug is on the edge, randomly select new direction
    while(isWayBlocked()){
        int randomNumber = rand()%4;
        switch (randomNumber) {
            case 0:
                setDirection(Direction::SOUTH);
                break;
            case 1:
                setDirection(Direction::NORTH);
                break;
            case 2:
                setDirection(Direction::WEST);
                break;
            case 3:
                setDirection(Direction::EAST);
                break;
        }
    }
//        if way is not block, move the hopper by its hop length and direction
    switch (getDirection()) {
        case Direction::NORTH:
            newPosition.second -=getHopLength();
            if(newPosition.second <= 0){newPosition.second =0;}
            break;
        case Direction::SOUTH:
            newPosition.second += getHopLength();
            if(newPosition.second >= 9){newPosition.second=9;}
            break;
        case Direction::EAST:
            newPosition.first+=getHopLength();
            if(newPosition.first >= 9){newPosition.first=9;}
            break;
        case Direction::WEST:
            newPosition.first-=getHopLength();
            if(newPosition.first <=0){newPosition.first=0;}
            break;
    }
//        set the new position
    setPosition(newPosition);
}
