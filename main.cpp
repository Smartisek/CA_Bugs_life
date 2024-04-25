#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bug.h"
#include "vector"
#include "Board.h"
#include "MainMenu.h"
#include "SuperBug.h"
using namespace std;
using namespace sf;


int main() {
    Board board; //instance of a board class
    vector<Bug*> bugs = board.loadBugsFromFile(); //creating a vector with reference of type pointer to Bug, meaning it can point to any derived class like hopper and crawler
    auto* superBug = new SuperBug(110, 5, 5, Direction::NORTH, 3);
    bugs.push_back(superBug);
    bool messagePrinted = false; // for stopping printing ton of messages a second when collision
    bool gameStarted = false; //boolean for starting the game
    bool aboutPressed = false;  //boolean for option menu
    bool superBugMove = false;
    int aliveBugs; //int to keep track of how many bugs are alive, to be able to check when there is only one left
////         functionality for searching for bug inside of board
//        board.searchForBug(bugs);
    board.printCells(bugs);

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
//                    reset messagePrinted variable to false when clicked so the areInTheSameCell() check is possible again, this variable makes sure
//                    the message is not printed constantly until they move out
            messagePrinted = false;
            superBugMove = true;
        }


        Event menuEvent;
        while(window.pollEvent(menuEvent)){
            if(menuEvent.type == Event::Closed){
                board.printFileLifePath(bugs); //when window is closed, print all the bugs path taken during window open time
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
                                if(aboutPressed){
                                    aboutPressed = false;
                                }
                        }
                        break;
                }
            }
        }

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

//        Event superInput;
//        while (window.pollEvent(superInput)){
//            if (superInput.type == sf::Event::KeyReleased) {
//                switch (superInput.key.code) {
//                    case sf::Keyboard::Up:
//                        cout << " UP MOVE" << endl;
//                        superBug->moveUp();
//                        break;
//                    case sf::Keyboard::Down:
//                        superBug->moveDown();
//                        break;
//                    case sf::Keyboard::Left:
//                        superBug->moveLeft();
//                        break;
//                    case sf::Keyboard::Right:
//                        superBug->moveRight();
//                        break;
//                    default:
//                        break;
//                }
//            }
//        }

        window.display(); //display all

    }
// since in the beginning we are creating new bugs (NEW) allocating on the HEAP then we need to clear afterwards and delete existing pointers
    for(Bug* bug : bugs){
        delete bug;
    }
    bugs.clear();

    return 0;
}

// ***** https://www.youtube.com/watch?v=_IzYGiuX8QM
// ***** https://www.youtube.com/watch?v=TR82JAtFLYI
// **** https://cplusplus.com/reference/map/map/
// **** https://sketch.io/sketchpad/
// **** https://www.youtube.com/watch?v=bOG8667yePY
// **** https://www.1001freefonts.com/