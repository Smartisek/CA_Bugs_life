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


class Bug {
private:

    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;

public:
    Bug(int id, int x, int y, Direction direction, int size);
    int getId() const;
    pair<int,int> getPosition() const;
    Direction getDirection() const;
    virtual void move () = 0;
};


#endif //SFML_002_BUG_H
