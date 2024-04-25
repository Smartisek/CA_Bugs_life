//
// Created by domal on 25/04/2024.
//

#include "SuperBug.h"


string SuperBug::getType() const {
    return "Crawler";
}

void SuperBug::moveUp() {
    pair<int, int> newPosition = getPosition();
    setPosition(make_pair(newPosition.first, newPosition.second -1));
    if(newPosition.second <= 0){newPosition.second =0;}
}

void SuperBug::moveDown() {
    pair<int, int> newPosition = getPosition();
    setPosition(make_pair(newPosition.first, newPosition.second +1));
    if(newPosition.second >= 9){newPosition.second =9;}
}

void SuperBug::moveLeft() {
    pair<int, int> newPosition = getPosition();
    setPosition(make_pair(newPosition.first-1, newPosition.second));
    if(newPosition.first <= 0){newPosition.first=0;}
}

void SuperBug::moveRight() {
    pair<int, int> newPosition = getPosition();
    setPosition(make_pair(newPosition.first+1, newPosition.second));
    if(newPosition.first >= 9){newPosition.first=9;}
}