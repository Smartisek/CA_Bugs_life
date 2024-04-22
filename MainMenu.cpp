//
// Created by domal on 22/04/2024.
//

#include "MainMenu.h"
using namespace std;


MainMenu::MainMenu(float width, float heigth) {
    font.loadFromFile("fonts/MATRICODE.ttf");
    backgroundTexture.loadFromFile("Background.png");
    backgroundSprite.setTexture(backgroundTexture);


    menu[0].setFont(font);
    menu[0].setFillColor(Color::White);
    menu[0].setString("START");
    FloatRect length1 = menu[0].getLocalBounds(); //get box of the text so i know length
    menu[0].setPosition(width/2 - (length1.left + length1.width/2.0f), heigth/2);

    menu[1].setFont(font);
    menu[1].setFillColor(Color::White);
    menu[1].setString("ABOUT");
    FloatRect length2 = menu[1].getLocalBounds();
    menu[1].setPosition(width/2-(length2.left + length2.width/2.0f), heigth/2+100);

    menu[2].setFont(font);
    menu[2].setFillColor(Color::White);
    menu[2].setString("EXIT");
    FloatRect length3 = menu[2].getLocalBounds();
    menu[2].setPosition(width/2- (length3.left + length3.width/2.0f), heigth/2+200);

    selectedIndex =0;
}

int MainMenu::GetPressedItem() {
    return selectedIndex;
}

void MainMenu::MenuDraw(sf::RenderWindow &window) {
    window.draw(backgroundSprite);
    for(int i=0; i< MAX_NUMBER_OF_ITEMS; i++){
        window.draw(menu[i]); //draw all the text
    }
}

void MainMenu::MoveUp() {
    if(selectedIndex - 1 >=0){
        menu[selectedIndex].setFillColor(Color::White); //color white first
        selectedIndex--; // go up
        menu[selectedIndex].setFillColor(Color::Black); // after going up color is transparent
    }
}

void MainMenu::MoveDown() {
    if(selectedIndex +1 < MAX_NUMBER_OF_ITEMS){
        menu[selectedIndex].setFillColor(Color::White);
        selectedIndex++;
        menu[selectedIndex].setFillColor(Color::Black);
    }
}

void MainMenu::drawAboutPage(sf::RenderWindow &window) {
    Text aboutText;
    Text goBack;
    aboutText.setFont(font);
    goBack.setFont(font);
    goBack.setString("Press ESC to go back to MAIN MENU.");
    aboutText.setString("When pressing start the simulation will start and \n bugs will start moving eating each other.");

    FloatRect aboutRect = aboutText.getLocalBounds();
    aboutText.setOrigin(aboutRect.left + aboutRect.width/2.0f, aboutRect.top + aboutRect.height/2.0f);
    aboutText.setPosition(sf::Vector2f(window.getSize().x/2.0f, window.getSize().y/2.0f+50));

    FloatRect goBackRect = goBack.getLocalBounds();
    goBack.setOrigin(goBackRect.left + aboutRect.width/2.0f, goBackRect.top + goBackRect.height/2.0f);
    goBack.setPosition(sf::Vector2f(window.getSize().x/2.0f, window.getSize().y/2.0f+150));

    window.draw(backgroundSprite);
    window.draw(goBack);
    window.draw(aboutText);
}

void MainMenu::finalPage(sf::RenderWindow &window, vector<Bug *> &bugs) {
    Text final;
    final.setFont(font);
    FloatRect finalRect = final.getLocalBounds(); // get size of the text
    final.setOrigin(finalRect.left + finalRect.width/2.0f, finalRect.top + finalRect.height/2.0f);
    final.setPosition(window.getSize().x/2 - finalRect.left + finalRect.width/2, window.getSize().y/2);
    Bug* lastAlive = nullptr; // initialize a pointer for last alive bug
    //iterate through bugs and find last one alive
    for(Bug* bug : bugs){
        if(bug->getStatus() == "Alive"){
            lastAlive = bug; //when last alive found put it into lastAlive pointer
        }
    }

    if(lastAlive != nullptr){
        final.setString("Last standing is " + to_string(lastAlive->getId()) + " " + lastAlive->getType());
    } else {
        final.setString("No alive bugs");
    }

    window.draw(backgroundSprite);
    window.draw(final);
}



// **** https://en.sfml-dev.org/forums/index.php?topic=28175.0