//
// Created by domal on 26/03/2024.
//

#ifndef SFML_002_CRAWLER_H
#define SFML_002_CRAWLER_H
#include "Bug.h"
#include "list"


class Crawler : public Bug{

public:
Crawler(int id, int x, int y, Direction direction, int size);
string getType() const override;

private:
void move() override;
};


#endif //SFML_002_CRAWLER_H
