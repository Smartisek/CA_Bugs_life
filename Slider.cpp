//
// Created by domal on 17/04/2024.
//

#include "Slider.h"
Slider::Slider(int id, int x, int y, Direction direction, int size) : Bug(id, x, y, direction, size){};

string Slider::getType() const {
    return "Slider";
}

void Slider::move() {
            pair<int, int> newPosition = getPosition();
//        when way is blocked meaning bug is on the edge, randomly select new direction
            while(isWayBlocked()){
                int randomNumber = rand()%4;
                switch (randomNumber) {
                    case 0:
                        setDirection(Direction::NORTHEAST);
                        break;
                    case 1:
                        setDirection(Direction::NORTHWEST);
                        break;
                    case 2:
                        setDirection(Direction::SOUTHWEST);
                        break;
                    case 3:
                        setDirection(Direction::SOUTHEAST);
                        break;
                }
            }
            switch (getDirection()) {
                case Direction::NORTHEAST:
                    setPosition(make_pair(newPosition.first+1, newPosition.second-1)); //make bug go up and right
                break;
                case Direction::NORTHWEST:
                    setPosition(make_pair(newPosition.first-1, newPosition.second-1)); // go up left
                break;
                case Direction::SOUTHEAST:
                    setPosition(make_pair(newPosition.first+1, newPosition.second+1)); // down right
                break;
                case Direction::SOUTHWEST:
                    setPosition(make_pair(newPosition.first-1, newPosition.second+1)); // down left
                break;
            }
    }