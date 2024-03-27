#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Bug.h"
#include "Crawler.h"
#include "vector"
#include "fstream"
using namespace std;
using namespace sf;

int main() {
    vector<Bug*> bugs;
    ifstream bugFile("bugs.txt");
    if(bugFile.is_open()){
        string line;


        while(getline(bugFile, line)) {
            stringstream ss(line);
            string type;
            int id, x, y, direction, size;
            char delim;

            cout << "Error" << endl;

            if(!(ss >> type >> delim >> id >> delim >> x >> delim >> y >> delim >> direction >> size)){
            break;
               }

            cout << "Read: " << type << ";" << id << ";" << x << ";" << y << ";" << direction << ";" << size << endl;

            if(type == "C"){
                bugs.push_back(new Crawler(id, x, y, static_cast<Direction>(direction), size));
                cout << " Inside";
                }
            }
        }




//Crawler c1(5, 2, 5, static_cast<Direction>(4), 5);
//Bug c2(1, 5, 5, static_cast<Direction>(1), 6);
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

