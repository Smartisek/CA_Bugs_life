//
// Created by domal on 26/03/2024.
//

#include "Bug.h"
Bug::Bug(int id, int x, int y, Direction direction, int size)
    : id(id), position(x,y), direction(direction), size(size), alive(true){
}

