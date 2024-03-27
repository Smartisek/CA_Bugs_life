//
// Created by domal on 26/03/2024.
//

#ifndef SFML_002_HOPPER_H
#define SFML_002_HOPPER_H
#include "Bug.h"


class Hopper : public Bug {
private:
    int hopLength;

public:
    Hopper(int id, int x, int y, Direction direction, int size, int hop) : Bug(id, x, y, direction, size){ hopLength = hop;} // constructor

    void move();
    int getHopLength() const;
};


#endif //SFML_002_HOPPER_H
