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
        switch(getDirection()){
            case Direction::NORTH:newPosition.second+=1;
                break;
            case Direction::SOUTH:newPosition.second-=1;
                break;
            case Direction::EAST:newPosition.first+=1;
                break;
            case Direction::WEST:newPosition.first-=1;
        }
        setPosition(newPosition);
    }
};


#endif //SFML_002_HOPPER_H
