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
        board.printCells(bugs);

    RenderWindow window(VideoMode(1000, 1000), "Bugs Life!");
    Clock clock; //this will start clock
    Time timeSinceLastUpdate = Time::Zero; // variable for keeping track of how much time passed, when created zero
    Time TimePerFrame = seconds(1.f); // set one second between each update

    while (window.isOpen()){
        Time elapsedTime = clock.restart(); // restart the clock
        timeSinceLastUpdate += elapsedTime; // adding elapsed time since restart
        while(timeSinceLastUpdate > TimePerFrame){ //if time elapsed is > timeperframe means enough time passed to call move
            timeSinceLastUpdate -=TimePerFrame;
            for(Bug* bug : bugs){ //move each bug
                if(bug->getStatus() == "Alive"){
                    bug->move();
                }
            }
//                    reset messagePrinted variable to false when clicked so the areInTheSameCell() check is possible again, this variable makes sure
//                    the message is not printed constantly until they move out
            messagePrinted = false;
        }

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
        }
        window.clear();
//      eat functionality
//        board.eat(bugs, messagePrinted);

//        window.clear();
        board.drawBoard(window);
        board.drawBugs(bugs, window);
        board.eat(bugs, messagePrinted);

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

