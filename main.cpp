#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bug.h"
#include "vector"
#include "Board.h"
using namespace std;
using namespace sf;


int main() {
    Board board; //instance of a board class
    vector<Bug*> bugs = board.loadBugsFromFile(); //creating a vector with reference of type pointer to Bug, meaning it can point to any derived class like hopper and crawler
    bool messagePrinted = false; // for stopping printing ton of messages a second when collision

//          functionality for searching for bug inside of board
//        board.searchForBug(bugs);

    RenderWindow window(VideoMode(1000, 1000), "Bugs Life!");

    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if(event.type == Event::Closed){
//                before closing application, loop through each bugs path taken and print it
//                for(int i =0; i < bugs.size(); i++){
//                    cout << bugs[i]->printPath();
//                }
//              when application closed print paths into date_out file
                board.printFileLifePath(bugs);
                window.close();
            }

            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    for(Bug* bug : bugs){
                        if(bug->getStatus() == "Alive"){
                            bug->move();
                        }

                    }
//                    reset messagePrinted variable to false when clicked so the areInTheSameCell() check is possible again, this variable makes sure
//                    the message is not printed constantly until they move out
                    messagePrinted = false;
                }
            }
        }
//      eat functionality
        board.eat(bugs, messagePrinted);

        window.clear();
        board.drawBoard(window);
        board.drawBugs(bugs, window);

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
