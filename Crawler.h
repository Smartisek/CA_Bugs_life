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
    switch(getDirection()){
        case Direction::NORTH:newPosition.second+1;
        break;
        case Direction::SOUTH:newPosition.second-1;
        break;
        case Direction::EAST:newPosition.first+1;
        break;
        case Direction::WEST:newPosition.first-1;
    }
}

};


#endif //SFML_002_CRAWLER_H
