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

void searchForBug(vector<Bug*> &bugs);

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
        if (type == "C") {
            bugs.push_back(new Crawler(id, x, y, static_cast<Direction>(direction), size));
        } else if(type == "H"){
            bugs.push_back(new Hopper(id, x, y, static_cast<Direction>(direction), size, hopLength));
        }
    }
    cout << bugs.size() << endl;
        bugFile.close();

        for(int i=0; i<bugs.size(); i++){
           cout << bugs[i]->printBug() << endl;
        }

//    searchForBug(bugs);

    RenderWindow window(VideoMode(1000, 1000), "Bugs Life!");

    vector<RectangleShape> background;
    for(int r = 0; r<10; r++){
        for(int c = 0; c <10; c++){
            RectangleShape shape(Vector2f(100,100));
            shape.setFillColor((r+c) %2==0?Color::Black:Color(0,120,20));
            shape.setPosition(c*100, r*100);
            background.push_back(shape);
        }
    }


    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }

            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    for(Bug* bug : bugs){
                        bug->move();
                    }
                }
            }
        }

        window.clear();
        for(RectangleShape &r : background){
            window.draw(r);
        }

        for(Bug* bug : bugs){
            int radius = bug->getSize()* 3;
            CircleShape bugShape(radius);
            bugShape.setFillColor(Color(210,180,140));
            bugShape.setPosition(100 * bug->getPosition().first + radius, 100*bug->getPosition().second + radius);
            window.draw(bugShape);
        }

        window.display();
    }


    for(Bug* bug : bugs){
        delete bug;
    }
    bugs.clear();

    return 0;
}

void searchForBug(vector<Bug*> &bugs){
    cout << "Enter bugs ID: ";
    int bugId;
    cin >> bugId;
    for(Bug* bug : bugs){
        if(bug->getId() == bugId){
            cout << bug->printBug() << endl;
        }
    }

    for(Bug* bug : bugs){
        delete bug;
    }
    bugs.clear();
}





// ***** https://www.youtube.com/watch?v=_IzYGiuX8QM
