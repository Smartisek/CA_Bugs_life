//
// Created by domal on 26/03/2024.
//

#include "Bug.h"

Bug::Bug(int id, int x, int y, Direction direction, int size) : id(id), position(x,y), direction(direction), size(size), alive(true){}; //constructor

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
    if(size >15){
        this->size = 15;
    } else {
        this->size = size;
    }

}

//list<pair<int,int>> Bug::getPathTaken() const{
//    return path;
//}

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
    Direction currentDirection = getDirection();
    int boardSize =10;
// check for edges, if any of these is true then return true meaning bug is on the edge cant go further, even if bug is going southwest and is on the west edge it needs to change direction
    if((currentPosition.first == 0 && (currentDirection == Direction::WEST || currentDirection == Direction::NORTHWEST || currentDirection == Direction::SOUTHWEST)) ||
    (currentPosition.first == boardSize - 1 && (currentDirection == Direction::EAST || currentDirection == Direction::NORTHEAST || currentDirection == Direction::SOUTHEAST)) ||
       (currentPosition.second == 0 && (currentDirection == Direction::NORTH || currentDirection == Direction::NORTHWEST || currentDirection == Direction::NORTHEAST)) ||
       (currentPosition.second == boardSize - 1 && (currentDirection == Direction::SOUTH || currentDirection == Direction::SOUTHEAST || currentDirection == Direction::SOUTHWEST))){
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
        case Direction::NORTHEAST: return "NorthEast";
        case Direction::NORTHWEST: return "NorthWest";
        case Direction::SOUTHEAST: return "SouthEast";
        case Direction::SOUTHWEST: return "SouthWest";
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
        bool erased = false; //helps to prevent unnecessary comparisons by skipping already erased bugs because in my code I do not remove eaten bugs from vector, rather I change their status to dead
//        nested for loop for comparing bugs against each other
        for(int j=0;j<bugs.size() && !erased;j++){
            if(i!=j && areInSameCell(*bugs[i], *bugs[j])){ //when bugs aren't the same and are in the same cell do below
                if(bugs[i]->getSize() > bugs[j]->getSize()){ //bug i is bigger then bug j
                    bugs[i]->setSize(bugs[i]->getSize() + bugs[j]->getSize()); //increase bug i size by the size of eaten bug
                    bugs[j]->setStatus(false); //weaker bug is eaten so we set status to false meaning it is dead
                    bugs[j]->isEatenBy = bugs[i]->getId(); //inside bugs constructor we have int for isEatenBy so we push id of stronger bug into eaten bugs variable
                    erased = true; //set erased to true so the program does only one task instead of many more
                } else if(bugs[j]->getSize() > bugs[i]->getSize()){
                    bugs[j]->setSize(bugs[j]->getSize() + bugs[i]->getSize());
                    bugs[i]->setStatus(false);
                    bugs[i]->isEatenBy = bugs[j]->getId();
                    erased = true;
                } else if(bugs[i]->getSize() == bugs[j]->getSize()){ //in case the bugs are the same size, pick randomly who wins
                    int randomNum = rand()%2; //get random number between 0 and 1 and then same logic as above
                    switch (randomNum) {
                        case 0:
                            bugs[i]->setSize(bugs[i]->getSize() + bugs[j]->getSize());
                            bugs[j]->setStatus(false);
                            bugs[j]->isEatenBy = bugs[i]->getId();
                            erased = true;
                            break;
                        case 1:
                            bugs[j]->setSize(bugs[j]->getSize() + bugs[i]->getSize());
                            bugs[i]->setStatus(false);
                            bugs[i]->isEatenBy = bugs[j]->getId();
                            erased = true;
                    }
                }
            }
        }
    }
}







