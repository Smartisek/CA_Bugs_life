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
    Bug(int id, int x, int y, Direction direction, int size);

    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;

public:

};


#endif //SFML_002_BUG_H
