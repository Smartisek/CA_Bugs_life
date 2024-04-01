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
    if(!isWayBlocked()){
        switch(getDirection()){
            case Direction::NORTH:
                setPosition(make_pair(newPosition.first, newPosition.second -1));
                break;
            case Direction::SOUTH:
                setPosition(make_pair(newPosition.first, newPosition.second+1));
                break;
            case Direction::EAST:
                setPosition(make_pair(newPosition.first+1, newPosition.second));
                break;
            case Direction::WEST:
                setPosition(make_pair(newPosition.first-1, newPosition.second));
        }
    } else {
        switch(getDirection()){
            case Direction::NORTH:
                setDirection(Direction::SOUTH);
                break;
            case Direction::SOUTH:
                setDirection(Direction::NORTH);
                break;
            case Direction::EAST:
                setDirection(Direction::WEST);
                break;
            case Direction::WEST:
                setDirection(Direction::EAST);
                break;
        }
    }
}

};


#endif //SFML_002_CRAWLER_H
