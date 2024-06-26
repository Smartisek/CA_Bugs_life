//
// Created by domal on 26/03/2024.
//

#include "Crawler.h"
Crawler::Crawler(int id, int x, int y, Direction direction, int size) : Bug(id, x, y, direction, size){};

string Crawler::getType() const{
return "Crawler";
}

void Crawler::move() {
    pair<int, int> newPosition = getPosition();

    while(isWayBlocked())
    {
        int randomNumber = rand() % 4;
//            switch for each direction with number
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
}
