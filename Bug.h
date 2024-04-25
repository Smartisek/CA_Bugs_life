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
    WEST = 4,
    NORTHEAST = 5, //adding another directions for my third bug to go diagonally
    NORTHWEST = 6,
    SOUTHEAST = 7,
    SOUTHWEST = 8

};


class Bug {
private:
    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;
    int isEatenBy = -1; //default -1, later if eaten gets assigned id of a bug that ate current bug
public:
    Bug(int id, int x, int y, Direction direction, int size);
    //// Getters
    int getId() const;
    Direction getDirection() const;
    int getSize() const;
    string getStatus() const;
    pair<int,int> getPosition() const;
    virtual string getType() const = 0;
    //// Setters
    void setPosition(pair<int, int> positionNew);
    void setDirection(Direction directionNew);
    void setSize(int size);
    void setStatus(bool status);

    string directionToString(Direction direction);
    static string positionToString(pair<int,int>);
    string printBug();
    bool isWayBlocked() const;
    virtual void move () = 0;
    string printPath();
    static bool areInSameCell(const Bug& bug1, const Bug& bug2);
    static void eat(vector<Bug*> &bugs);
};

#endif //SFML_002_BUG_H
