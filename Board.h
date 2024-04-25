//
// Created by domal on 16/04/2024.
//

#ifndef CA_BUGS_LIFE_BOARD_H
#define CA_BUGS_LIFE_BOARD_H
#include <SFML/Graphics.hpp>
#include "vector"
#include "Bug.h"

class Board {
    sf::Texture crawlerTexture; //textures for drawing bugs
    sf::Texture hopperTexture;
    sf::Texture sliderTexture;
    sf::Texture superBugTexture;
private:
    int size = 10;
    std::vector<sf::RectangleShape> background;

public:
    Board();
    void drawBoard(sf::RenderWindow &window);
    void drawBugs(const vector<Bug*>& bugs, sf::RenderWindow &window);
    void eat(vector<Bug*> &bugs, bool &messagePrinted);
    void printFileLifePath(vector<Bug*> &bugs);
    void searchForBug(vector<Bug*> &bugs);
    vector<Bug*> loadBugsFromFile();
    void printCells(vector<Bug*> &bugs);

};




#endif //CA_BUGS_LIFE_BOARD_H
