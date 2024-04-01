//
// Created by domal on 26/03/2024.
//

#ifndef SFML_002_CRAWLER_H
#define SFML_002_CRAWLER_H
#include "Bug.h"


class Crawler : public Bug{

public:
Crawler(int id, int x, int y, Direction direction, int size) : Bug(id, x, y, direction, size){}
string getType() const override{
    return "Crawler";
}

void move() override{
    pair<int,int> newPosition = getPosition();
    int randomDirection = rand() % 4;
    if(!isWayBlocked()){
        switch(getDirection()){
            case Direction::NORTH:
                setPosition(make_pair(newPosition.first, newPosition.second -1)); //up
                break;
            case Direction::SOUTH:
                setPosition(make_pair(newPosition.first, newPosition.second+1)); //down
                break;
            case Direction::EAST:
                setPosition(make_pair(newPosition.first+1, newPosition.second)); //right
                break;
            case Direction::WEST:
                setPosition(make_pair(newPosition.first-1, newPosition.second)); //left
        }
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


#endif //SFML_002_CRAWLER_H
