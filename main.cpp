#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Bug.h"
#include "vector"
#include "fstream"
using namespace std;
using namespace sf;

int main() {
    ifstream bugFile("bugs.txt");
    if(bugFile.is_open()){
        string line;
        while(getline(bugFile, line)){
            stringstream ss(line);
            string item;
            vector<string> data;
            while(getline(ss,item, ';')){
                data.push_back(item);
            }
            for(int i=0; i < data.size(); i++){
                cout << data[i] << endl;
            }
        }
        bugFile.close();
    } else {
        cout << "File could not be opened";
    }

//    string filename = "bugs.txt";
//    ifstream inFile;
//    inFile.open(filename);
//
//    if(inFile.fail()){
//        cout << "Error" << endl;
//    }
//    char c;
//    while(inFile.get(c)){
//        cout << c;
//    }
//    inFile.close();
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

