//
// Created by domal on 26/03/2024.
//

#ifndef SFML_002_CRAWLER_H
#define SFML_002_CRAWLER_H
#include "Bug.h"


class Crawler : public Bug{

public:
Crawler(int id, int x, int y, Direction direction, int size) : Bug(id, x, y, direction, size){}
string getType() const override{
    return "Crawler";
}

};


#endif //SFML_002_CRAWLER_H
