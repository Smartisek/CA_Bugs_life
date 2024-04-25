//
// Created by domal on 26/03/2024.
//

#ifndef SFML_002_HOPPER_H
#define SFML_002_HOPPER_H
#include "Bug.h"


class Hopper : public Bug {

public:
    Hopper(int id, int x, int y, Direction direction, int size, int hop);

    int getHopLength() const;
    string getType() const override;

private:
    int hopLength;
    void move() override;
};


#endif //SFML_002_HOPPER_H
