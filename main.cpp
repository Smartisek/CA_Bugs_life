#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "vector"
#include "fstream"
#include "Board.h"
using namespace std;
using namespace sf;

int main() {
//    creating a vector with reference of type pointer to Bug, meaning it can point to any derived class like hopper and crawler
    vector<Bug*> bugs;
    Board board;
    ifstream bugFile("bugs.txt");
    if(!bugFile.is_open()){
        cout << "File failed to open" << endl;
    }
    string line;
    string type, idT, xT, yT, directionT, sizeT, hopLengthT;
    int id, x, y, direction, size, hopLength;
//  reading from the file
    while(getline(bugFile, line)) {
        stringstream ss(line);
        getline(ss, type, ';');
        getline(ss, idT, ';');
        id = stoi(idT);
        getline(ss, xT, ';');
        x = stoi(xT);   //stoi converts string to an integer
        getline(ss, yT, ';');
        y = stoi(yT);
        getline(ss, directionT, ';');
        direction = stoi(directionT);
        getline(ss, sizeT, ';');
        size = stoi(sizeT);
        hopLength =0; //default hop length
        if(getline(ss, hopLengthT, ';') && !hopLengthT.empty()){
            hopLength = stoi(hopLengthT);
        }
//        creating bugs om HEAP with data taken from bugs.txt file
        if (type == "C") {
            bugs.push_back(new Crawler(id, x, y, static_cast<Direction>(direction), size));
        } else if(type == "H"){
            bugs.push_back(new Hopper(id, x, y, static_cast<Direction>(direction), size, hopLength));
        }
    }
    cout << bugs.size() << endl;
//    after reading data, close the file
        bugFile.close();

        for(int i=0; i<bugs.size(); i++){
           cout << bugs[i]->printBug() << endl;
        }
//          functionality for searching for bug inside of board
//        board.searchForBug(bugs);

    RenderWindow window(VideoMode(1000, 1000), "Bugs Life!");

//    vector<RectangleShape> background;
//    for(int r = 0; r<10; r++){
//        for(int c = 0; c <10; c++){
//            RectangleShape shape(Vector2f(100,100));
//            shape.setFillColor((r+c) %2==0?Color::Black:Color(0,120,20));
//            shape.setPosition(c*100, r*100);
//            background.push_back(shape);
//        }
//    }

// for stopping printing ton of messages a second when collision
    bool messagePrinted = false;


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
