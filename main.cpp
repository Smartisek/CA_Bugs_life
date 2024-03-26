#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bug.h"
#include "vector"
using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 800), "Bugs Life!");

    vector<RectangleShape> background;
    for(int r = 0; r<8; r++){
      for(int c = 0; c <8; c++){
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
        }

        window.clear();
        for(RectangleShape &r : background){
            window.draw(r);
        }

        window.display();
    }
    return 0;
}
