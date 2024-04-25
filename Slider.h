//
// Created by domal on 17/04/2024.
//

#ifndef CA_BUGS_LIFE_SLIDER_H
#define CA_BUGS_LIFE_SLIDER_H
#include "Bug.h"

class Slider : public Bug{

public:
    Slider(int id, int x, int y, Direction direction, int size);
    string getType() const override;

private:
    void move() override;
    };


#endif //CA_BUGS_LIFE_SLIDER_H
