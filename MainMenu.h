//
// Created by domal on 22/04/2024.
//

#ifndef CA_BUGS_LIFE_MAINMENU_H
#define CA_BUGS_LIFE_MAINMENU_H
#include <SFML/Graphics.hpp>
#include "Bug.h"

#define MAX_NUMBER_OF_ITEMS 3 // 3 options for menu

using namespace sf;

class MainMenu {
private:
    int selectedIndex;
    Font font;
    Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

public:
    MainMenu(float width, float heigth);
    void MenuDraw(RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem();
    void drawAboutPage(RenderWindow &window);
    void finalPage(RenderWindow &window, vector<Bug *>& bugs);
};


#endif //CA_BUGS_LIFE_MAINMENU_H
