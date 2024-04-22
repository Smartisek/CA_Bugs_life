#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bug.h"
#include "vector"
#include "Board.h"
#include "MainMenu.h"
using namespace std;
using namespace sf;


int main() {
    Board board; //instance of a board class
    vector<Bug*> bugs = board.loadBugsFromFile(); //creating a vector with reference of type pointer to Bug, meaning it can point to any derived class like hopper and crawler
    bool messagePrinted = false; // for stopping printing ton of messages a second when collision
    bool gameStarted = false;
    bool aboutPressed = false;
    int aliveBugs;
//          functionality for searching for bug inside of board
//        board.searchForBug(bugs);
        board.printCells(bugs);

    RenderWindow window(VideoMode(1000.00, 1000.00), "Bugs Life!");
    MainMenu menu(window.getSize().x, window.getSize().y);
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
                    aliveBugs++;
                    bug->move();
                }
            }
//                    reset messagePrinted variable to false when clicked so the areInTheSameCell() check is possible again, this variable makes sure
//                    the message is not printed constantly until they move out
            messagePrinted = false;
        }


        Event menuEvent;
        while(window.pollEvent(menuEvent)){
            if(menuEvent.type == Event::Closed){
                board.printFileLifePath(bugs);
                window.close();
            }
            if(!gameStarted){
                switch (menuEvent.type) {
                    case Event::KeyReleased:
                        switch (menuEvent.key.code) {
                            case sf::Keyboard::Up:   //if we press arrow up, go up
                                menu.MoveUp();
                                break;
                            case sf::Keyboard::Down: // if we press arrow down, go down
                                menu.MoveDown();
                                break;

                            case sf::Keyboard::Return:
                                switch (menu.GetPressedItem()) {
                                    case 0:
                                        cout << "Start button pressed" << endl;
                                        gameStarted = true;
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
                            case sf::Keyboard::Escape:
                                if(aboutPressed){
                                    aboutPressed = false;
                                }
                        }
                        break;
                }
            }

        }
        window.clear();
        if(!gameStarted && !aboutPressed){
            menu.MenuDraw(window);
        } else if(gameStarted){
            board.drawBoard(window);
            board.drawBugs(bugs, window);
            board.eat(bugs, messagePrinted);
        } else {
            menu.drawAboutPage(window);
        }
        if(aliveBugs == 1){
            menu.finalPage(window, bugs);
        }
        window.display();
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
