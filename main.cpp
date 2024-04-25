#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bug.h"
#include "vector"
#include "Board.h"
#include "MainMenu.h"
#include "SuperBug.h"
using namespace std;
using namespace sf;

////Resources at the end of main


int main() {
    Board board; //instance of a board class
    vector<Bug*> bugs = Board::loadBugsFromFile(); //creating a vector with reference of type pointer to Bug, meaning it can point to any derived class like hopper and crawler
    auto* superBug = new SuperBug(110, 5, 5, Direction::NORTH, 3); //initialize super bug and push it into vector
    bugs.push_back(superBug);


    bool messagePrinted = false; // for stopping printing ton of messages a second when collision
    bool gameStarted = false; //boolean for starting the game
    bool aboutPressed = false;  //boolean for option menu
    bool superBugMove = false; //boolean for moving superBug


    int aliveBugs; //int to keep track of how many bugs are alive, to be able to check when there is only one left
////         functionality for searching for bug inside of board
//        board.searchForBug(bugs);
    board.printCells(bugs);

////  GameState
    RenderWindow window(VideoMode(1000.00, 1000.00), "Bugs Life!"); //create the window
    window.setKeyRepeatEnabled(false);
    MainMenu menu(window.getSize().x, window.getSize().y); //create main menu instance
    Clock clock; //this will start clock
    Time timeSinceLastUpdate = Time::Zero; // variable for keeping track of how much time passed, when created zero
    Time TimePerFrame = seconds(1.f); // set one second between each update

    while (window.isOpen()){
        Time elapsedTime = clock.restart(); // restart the clock
        timeSinceLastUpdate += elapsedTime; // adding elapsed time since restart
        while(timeSinceLastUpdate > TimePerFrame){ //if time elapsed is > timeperframe means enough time passed to call move
            timeSinceLastUpdate -=TimePerFrame;
            aliveBugs = 0; //reset to zero at start of a frame
            for(Bug* bug : bugs){ //move each bug
                if(bug->getStatus() == "Alive"){
                    aliveBugs++; //keep count of alive bugs
                    bug->move();
                }
            }
//      reset messagePrinted variable to false when clicked so the areInTheSameCell() check is possible again, this variable makes sure
//      the message is not printed constantly until they move out
            messagePrinted = false;
//      set the boolean for super bug true meaning now it can move, so every one second, if we did not have this check, the bug would jump many times at once when arrow pressed
//      this just gives us the control over it and jump together with other bugs at the same time
            superBugMove = true;
        }


        Event menuEvent{}; //create an event for menu state
        while(window.pollEvent(menuEvent)){
            if(menuEvent.type == Event::Closed){
                Board::printFileLifePath(bugs); //when window is closed, print all the bugs path taken during window open time
                window.close();
            }
            if(!gameStarted){ //if game has not started yet, be able to go through menu
                switch (menuEvent.type) {
                    case Event::KeyReleased:
                        switch (menuEvent.key.code) {
                            case sf::Keyboard::Up:   //if we press arrow up, go up
                                menu.MoveUp();
                                break;
                            case sf::Keyboard::Down: // if we press arrow down, go down
                                menu.MoveDown();
                                break;

                            case sf::Keyboard::Return: //if one of three options selected inside the main menu
                                switch (menu.GetPressedItem()) {
                                    case 0:
                                        cout << "Start button pressed" << endl;
                                        gameStarted = true; //make variable true and this starts drawing the game, if statement below
                                        break;
                                    case 1:
                                        cout << "About button pressed" << endl;
                                        aboutPressed = true;
                                        break;
                                    case 2:
                                        window.close();
                                        break;
                                }
                                break;
                            case sf::Keyboard::Escape: // if we are inside about page and press esc, go back to main menu
                                if(aboutPressed){ //if boolean is true and we click esc, set it to false which brings us back to main menu
                                    aboutPressed = false;
                                }
                        }
                        break;
                }
            }
        }
//  whenever game starts, super bug is alive and can move, check for if the arrow is pressed, I am using these if statements because when I used the event type with window poll event as above, the arrow had to be pressed
//  at exact time, the check for when it is pressed was not precise and it took many pressed till the bugged moved, this way any time the arrow is pressed the code knows right away
        if(gameStarted && superBugMove && superBug->getStatus() == "Alive"){
            if(Keyboard::isKeyPressed(Keyboard::Up)){
                cout << "MOVED UP" << endl;
                superBug->moveUp();
                superBugMove = false;
            } else if(Keyboard::isKeyPressed(Keyboard::Down)){
                cout << "MOVED DOWN" << endl;
                superBug->moveDown();
                superBugMove = false;
            } else if(Keyboard::isKeyPressed(Keyboard::Left)){
                cout << "MOVED LEFT" << endl;
                superBug->moveLeft();
                superBugMove = false;
            } else if(Keyboard::isKeyPressed(Keyboard::Right)){
                cout << "MOVED RIGHT" << endl;
                superBug->moveRight();
                superBugMove = false;
            }
        }

        window.clear();
        if(!gameStarted && !aboutPressed){ //when game has not started yet draw the menu
            menu.MenuDraw(window);
        } else if(gameStarted){ //if boolean game started true then draw the game, draw board and bugs and call eat functionality
            board.drawBoard(window);
            board.drawBugs(bugs, window);
            board.eat(bugs, messagePrinted);
        } else { //else go to about menu
            menu.drawAboutPage(window);
        }
        if(aliveBugs == 1){ //when there is only one alive bring final page with last standing bug information
            menu.finalPage(window, bugs);
        }

        window.display(); //display all

    }
// since in the beginning we are creating new bugs (NEW) allocating on the HEAP then we need to clear afterward and delete existing pointers
    for(Bug* bug : bugs){
        delete bug;
    }
    bugs.clear();

    return 0;
}

/**
 * ***** REFERENCES *****
 *
CU Boulder Data Structures CSCI 2270 (2018), Data Structures Tutorial - 14 - How to Read in a Comma Seperated .txt File in c++, [source code]: https://www.youtube.com/watch?v=_IzYGiuX8QM
 *
Mister Vriesinga (2023), C++ SFML Clocks and Time, [source code]: https://www.youtube.com/watch?v=TR82JAtFLYI
 *
cplusplus.com, std::map, [source code]: https://cplusplus.com/reference/map/map/
 *
Geek projects (2022), Main Menu in C++ using SFML library, [source code]: https://www.youtube.com/watch?v=bOG8667yePY
 *
font used in this project: MATRICODE.ttf from: https://www.1001freefonts.com/index.php
 *
 all graphics created by myself using png sketcher: https://sketch.io/sketchpad/
 *
 en.sfml-dev.org, detecting key pressed, [source code]: https://en.sfml-dev.org/forums/index.php?topic=20802.0
 */

