//
// Created by domal on 26/03/2024.
//

#ifndef SFML_002_HOPPER_H
#define SFML_002_HOPPER_H
#include "Bug.h"


class Hopper : public Bug {
private:
    int hopLength;

public:
    Hopper(int id, int x, int y, Direction direction, int size, int hop) : Bug(id, x, y, direction, size){ hopLength = hop;} // constructor

    int getHopLength() const;
    string getType() const override{
        return "Hopper " + to_string(getHopLength());
    }
    void move() override{
        pair<int,int> newPosition = getPosition();
        if(!isWayBlocked()){
            switch(getDirection()){
                case Direction::NORTH:
                    newPosition.second -=getHopLength();
                    if(newPosition.second < 0){newPosition.second =0;}
                    break;
                case Direction::SOUTH:
                    newPosition.second += getHopLength();
                    if(newPosition.second > 9){newPosition.second=9;}
                    break;
                case Direction::EAST:
                    newPosition.first+=getHopLength();
                    if(newPosition.first < 0){newPosition.first=0;}
                    break;
                case Direction::WEST:
                    newPosition.first-=getHopLength();
                    if(newPosition.first >9){newPosition.first=9;}
            }
            setPosition(newPosition);
        } else {
            //        create a new instance of direction so we can assign it directions
            Direction newDirection;
            do {
//            random numbers between 0-3
                int randomNumber = rand() %4;
//            switch for each direction with number
                switch(randomNumber){
                    case 0:
                        newDirection = Direction::SOUTH;
                        break;
                    case 1:
                        newDirection = Direction::NORTH;
                        break;
                    case 2:
                        newDirection = Direction::WEST;
                        break;
                    case 3:
                        newDirection = Direction::EAST;
                        break;
                }
//            do this until newDirection and current direction is not the same
            } while (newDirection == getDirection());
//        when new direction chosen, set it to bugs direction
            setDirection(newDirection);
        }
    }
};


#endif //SFML_002_HOPPER_H
