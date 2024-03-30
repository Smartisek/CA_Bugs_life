#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "vector"
#include "fstream"
using namespace std;
using namespace sf;

int main() {
    vector<Bug*> bugs;
    ifstream bugFile("bugs.txt");
    if(!bugFile.is_open()){
        cout << "File failed to open" << endl;
    }
    string line;
    string type, idT, xT, yT, directionT, sizeT, hopLengthT;
    int id, x, y, direction, size, hopLength;

    while(getline(bugFile, line)) {
        stringstream ss(line);
        getline(ss, type, ';');
        getline(ss, idT, ';');
        id = stoi(idT);
        getline(ss, xT, ';');
        x = stoi(xT);
        getline(ss, yT, ';');
        y = stoi(yT);
        getline(ss, directionT, ';');
        direction = stoi(directionT);
        getline(ss, sizeT, ';');
        size = stoi(sizeT);
        hopLength =0;
        if(getline(ss, hopLengthT, ';') && !hopLengthT.empty()){
            hopLength = stoi(hopLengthT);
        }

        cout << "Read: " << type << ";" << id << ";" << x << ";" << y << ";" << direction << ";" << size << ";" << hopLength <<  endl;
        if (type == "C") {
            bugs.push_back(new Crawler(id, x, y, static_cast<Direction>(direction), size));
        } else if(type == "H"){
            bugs.push_back(new Hopper(id, x, y, static_cast<Direction>(direction), size, hopLength));
        }
    }
    cout << bugs.size() << endl;
        bugFile.close();

        for(Bug* bug : bugs){
            delete bug;
        }
        bugs.clear();

        cout << bugs.size() << endl;
        Direction getDir = bugs[1]->getDirection();
        string printDir = bugs[1]->directionToString(getDir);
        cout << printDir;
        pair<int, int> position = bugs[1]->getPosition();
        cout << bugs[1]->positionToString(position);

    return 0;
}

    //    RenderWindow window(VideoMode(800, 800), "Bugs Life!");
//
//    vector<RectangleShape> background;
//    for(int r = 0; r<8; r++){
//      for(int c = 0; c <8; c++){
//          RectangleShape shape(Vector2f(100,100));
//          shape.setFillColor((r+c) %2==0?Color::Black:Color(0,120,20));
//          shape.setPosition(c*100, r*100);
//          background.push_back(shape);
//      }
//    }
//
//
//    while (window.isOpen()){
//        Event event;
//        while (window.pollEvent(event)){
//            if(event.type == Event::Closed){
//                window.close();
//            }
//        }
//
//        window.clear();
//        for(RectangleShape &r : background){
//            window.draw(r);
//        }
//
//        window.display();
//    }



// ***** https://www.youtube.com/watch?v=_IzYGiuX8QM
