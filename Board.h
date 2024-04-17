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
private:
    int size = 10;
    std::vector<sf::RectangleShape> background;

public:
    Board(){
        for(int r=0; r<size;r++){
            for(int c =0; c<size;c++){
                sf::RectangleShape shape(sf::Vector2f(100,100));
                shape.setFillColor((r+c)%2==0?sf::Color::Black:sf::Color(0,120,20));
                shape.setPosition(c*100, r*100);
                background.push_back(shape);
            }
        }
        if(!crawlerTexture.loadFromFile("crawler.png")){cout << "Error loading image for Crawler" << endl; } //loading bugs image
        if(!hopperTexture.loadFromFile("hopper.png")){cout << "Error loading image for hopper" << endl;}
    }
    void drawBoard(sf::RenderWindow &window);
    void drawBugs(vector<Bug*> bugs, sf::RenderWindow &window);
    void eat(vector<Bug*> &bugs, bool &messagePrinted);
    void printFileLifePath(vector<Bug*> &bugs);
    void searchForBug(vector<Bug*> &bugs);
    vector<Bug*> loadBugsFromFile();
    void printCells(vector<Bug*> &bugs);
};




#endif //CA_BUGS_LIFE_BOARD_H
