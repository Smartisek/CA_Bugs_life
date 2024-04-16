//
// Created by domal on 16/04/2024.
//

#ifndef CA_BUGS_LIFE_BOARD_H
#define CA_BUGS_LIFE_BOARD_H
#include <SFML/Graphics.hpp>
#include "vector"

class board {
    board();
private:
    int size = 10;
    std::vector<sf::RectangleShape> boardVector;

public:
    void displayBoard();
};




#endif //CA_BUGS_LIFE_BOARD_H
