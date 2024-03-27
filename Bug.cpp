//
// Created by domal on 26/03/2024.
//

#include "Bug.h"

int Bug::getId() const{
    return id;
}

pair<int,int> Bug::getPosition() const{
    return position;
}

Direction Bug::getDirection() const{
    return direction;
}


