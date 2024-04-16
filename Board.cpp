//
// Created by domal on 16/04/2024.
//

#include "Board.h"
void Board::drawBoard(sf::RenderWindow &window) {
    for(sf::RectangleShape &r : background){
        window.draw(r);
    }
}