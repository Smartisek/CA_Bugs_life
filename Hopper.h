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
        return "Hopper";
    }
    void move() override{
        pair<int,int> newPosition = getPosition();
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
                    setDirection(Direction::WEST);
                    break;
            }
        }
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
        }
        setPosition(newPosition);
    }
};


#endif //SFML_002_HOPPER_H
