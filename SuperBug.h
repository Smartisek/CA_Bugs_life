//
// Created by domal on 25/04/2024.
//

#ifndef CA_BUGS_LIFE_SUPERBUG_H
#define CA_BUGS_LIFE_SUPERBUG_H
#include "Crawler.h"
#include <SFML/Graphics.hpp>

class SuperBug : public Crawler {
    public:
    SuperBug(int id, int x, int y, Direction direction, int size);
    string getType() const override;
    void move(){};
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
};




#endif //CA_BUGS_LIFE_SUPERBUG_H
