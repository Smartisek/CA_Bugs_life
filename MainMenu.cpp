//
// Created by domal on 22/04/2024.
//

#include "MainMenu.h"
using namespace std;


MainMenu::MainMenu(float width, float heigth) {
    font.loadFromFile("fonts/MATRICODE.ttf");

    menu[0].setFont(font);
    menu[0].setFillColor(Color::White);
    menu[0].setString("START");
    menu[0].setPosition(width/2, heigth/2);

    menu[1].setFont(font);
    menu[1].setFillColor(Color::White);
    menu[1].setString("ABOUT");
    menu[1].setPosition(width/2, heigth/2+100);

    menu[2].setFont(font);
    menu[2].setFillColor(Color::White);
    menu[2].setString("EXIT");
    menu[2].setPosition(width/2, heigth/2+200);

    selectedIndex =0;
}

int MainMenu::GetPressedItem() {
    return selectedIndex;
}

void MainMenu::MenuDraw(sf::RenderWindow &window) {
    for(int i=0; i< MAX_NUMBER_OF_ITEMS; i++){
        window.draw(menu[i]); //draw all the text
    }
}

void MainMenu::MoveUp() {
    if(selectedIndex - 1 >=0){
        menu[selectedIndex].setFillColor(Color::White); //color white first
        selectedIndex--; // go up
        menu[selectedIndex].setFillColor(Color::Transparent); // after going up color is transparent
    }
}

void MainMenu::MoveDown() {
    if(selectedIndex +1 < MAX_NUMBER_OF_ITEMS){
        menu[selectedIndex].setFillColor(Color::White);
        selectedIndex++;
        menu[selectedIndex].setFillColor(Color::Transparent);
    }
}

void MainMenu::drawAboutPage(sf::RenderWindow &window) {
    Text aboutText;
    aboutText.setFont(font);
    aboutText.setString("When pressing start, the simulation will start and bugs will start moving eating each other. + \n Press ESC to go to MAIN MENU.");
    aboutText.setPosition(window.getSize().x/2, window.getSize().y/2);
    window.draw(aboutText);
}



