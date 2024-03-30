//
// Created by domal on 26/03/2024.
//

#ifndef SFML_002_BUG_H
#define SFML_002_BUG_H

#include <utility>
#include "iostream"
#include "list"
using namespace std;

enum class Direction{
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4
};

//string directionToString(Direction direction){
//    switch (direction) {
//        case Direction::NORTH: return "North";
//        case Direction::EAST: return "East";
//        case Direction::SOUTH: return "South";
//        case Direction::WEST: return "West";
//        default: return "Unknown";
//    }
//}

class Bug {
private:
    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;

public:
    Bug(int id, int x, int y, Direction direction, int size)
            : id(id), position(x,y), direction(direction), size(size), alive(true){
    }
    int getId() const;
    pair<int,int> getPosition() const;
    Direction getDirection() const;
    string directionToString(Direction direction);

//    virtual void move () = 0;
};

#endif //SFML_002_BUG_H
