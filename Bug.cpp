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


int Bug::getSize() const {
    return size;
}

string Bug::getStatus() const {
    if(alive == 1){
        return "Alive";
    } else {
        return "Dead";
    }
}


string Bug::positionToString(pair<int,int> position){
    return "(" + to_string(position.first) + "," + to_string(position.second) + ")";
}

Direction Bug::getDirection() const{
    return direction;
}

string Bug::printBug(){
    return to_string(getId()) + " " + getType() + " " + positionToString(getPosition()) + " " + to_string(getSize()) +
    " " + directionToString(getDirection()) + " " + getStatus();
}

void Bug::setPosition(pair<int, int> positionNew){
    this -> position = positionNew;
    path.push_back(positionNew); // everytime bug moves, push a new position into our path list
}

void Bug::setStatus(bool status){
    this->alive =status;
}

void Bug::setSize(int size){
    if(size >10){
        this->size = 10;
    } else {
        this->size = size;
    }

}

list<pair<int,int>> Bug::getPathTaken() const{
    return path;
}

string Bug::printPath(){
//    create a string that will get id of the bug, his type and then loop through it's path that is being added inside setPosition();
    string result = to_string(getId()) + " " + getType() + " Path: ";
//    a for each loop, const makes sure that the position does not get change inside the loop, decides the type by itself and then
//    we use reference to the element inside of path with & and loop through, {for each &pos(element) inside(:) path}
    for(const auto &pos : path){
        result += positionToString(pos) + ",";
    }
//    if isEatenBy has an ID inside then print message eaten by this id bug
    if(isEatenBy !=-1){
        result += " Eaten by " + to_string(isEatenBy) +"\n";
    } else{
        result += getStatus() + "!" + "\n";
    }
    return result;
}

void Bug::setDirection(Direction directionNew) {
    this -> direction = directionNew;
}


bool Bug::isWayBlocked() const{
//    instances with current position and direction
    pair<int,int> currentPosition = getPosition();
    Direction currentDirrection = getDirection();
    int boardSize =10;
// check for edges, if any of these is true then return true meaning bug is on the edge cant go further
    if((currentPosition.first == 0 && currentDirrection == Direction::WEST) || (currentPosition.first == boardSize-1 && currentDirrection ==Direction::EAST) ||
            (currentPosition.second == 0 && currentDirrection == Direction::NORTH) || (currentPosition.second == boardSize-1 && currentDirrection == Direction::SOUTH)){
        return true;
    } else {
//        if any of above condition is not met return false, nothing is blocking bug
    return false;
    }
}

string Bug::directionToString(Direction direction){
//    https://stackoverflow.com/questions/5093460/how-to-convert-an-enum-type-variable-to-a-string
    switch (direction) {
        case Direction::NORTH: return "North";
        case Direction::EAST: return "East";
        case Direction::SOUTH: return "South";
        case Direction::WEST: return "West";
        default: return "Unknown";
    }
}
// boolean check function if more bugs are in the same cell
bool Bug::areInSameCell(const Bug& bug1,const Bug& bug2){
//    if their position is the same return true
    return bug1.getPosition() == bug2.getPosition() && bug1.getStatus() == "Alive" && bug2.getStatus() == "Alive";
}

void Bug::eat(vector<Bug*> &bugs){
    for(int i=0; i<bugs.size();i++){
        bool erased = false;
        for(int j=0;j<bugs.size() && !erased;j++){
            if(i!=j && areInSameCell(*bugs[i], *bugs[j])){
                if(bugs[i]->getSize() > bugs[j]->getSize()){
//                    cout << "Size before: " << bugs[i]->getSize() << endl;
//                   cout << "Eat " << bugs[j]->getId() << "size: " << bugs[j]->getSize() << " , " << bugs[i]->getId() << " is bigger:" << bugs[i]->getSize() <<endl;
                    bugs[i]->setSize(bugs[i]->getSize() + bugs[j]->getSize());
//                   cout << "Size after: " << bugs[i]->getSize() << endl;
                    bugs[j]->setStatus(false);
                    bugs[j]->isEatenBy = bugs[i]->getId();
                    erased = true;
                } else if(bugs[j]->getSize() > bugs[i]->getSize()){
//                    cout << "Size before: " << bugs[j]->getSize() << endl;
//                    cout << "Eat " << bugs[i]->getId() << "size: " << bugs[i]->getSize() << " , " << bugs[j]->getId() << " is bigger:" << bugs[j]->getSize() <<endl;
                    bugs[j]->setSize(bugs[j]->getSize() + bugs[i]->getSize());
//                    cout << "Size after: " << bugs[i]->getSize() << endl;
                    bugs[i]->setStatus(false);
                    bugs[i]->isEatenBy = bugs[j]->getId();
                    erased = true;
                }
            }
        }
    }
}







