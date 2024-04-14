//
// Created by domal on 26/03/2024.
//

#ifndef SFML_002_BUG_H
#define SFML_002_BUG_H

#include <utility>
#include <vector>
#include "iostream"
#include "list"
using namespace std;

enum class Direction{
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4
};


class Bug {
private:
    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;

public:
    Bug(int id, int x, int y, Direction direction, int size)
            : id(id), position(x,y), direction(direction), size(size), alive(true){
    }
    int getId() const;
    pair<int,int> getPosition() const;
    void setPosition(pair<int, int> positionNew);
    void setDirection(Direction directionNew);
    void setSize(int size);
    void setStatus(bool status);
    Direction getDirection() const;
    int getSize() const;
    string getStatus() const;
    string directionToString(Direction direction);
    static string positionToString(pair<int,int>);
    string printBug();
    bool isWayBlocked() const;
    virtual string getType() const = 0;
    virtual void move () = 0;
    list<pair<int,int>> getPathTaken() const;
    string printPath();
    static bool areInSameCell(const Bug& bug1, const Bug& bug2);
    static void eat(vector<Bug*> &bugs);
};

#endif //SFML_002_BUG_H
