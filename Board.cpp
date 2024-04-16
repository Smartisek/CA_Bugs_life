//
// Created by domal on 16/04/2024.
//

#include <fstream>
#include "Board.h"
void Board::drawBoard(sf::RenderWindow &window) {
    for(sf::RectangleShape &r : background){
        window.draw(r);
    }
}

void Board::drawBugs(vector<Bug *> bugs, sf::RenderWindow &window) {
    for(Bug* bug : bugs){
        int radius = bug->getSize()* 3;
        sf::CircleShape bugShape(radius);
        if(bug->getType() == "Crawler"){
            bugShape.setFillColor(sf::Color(0,0,250));
        } else if (bug->getType() == "Hopper"){
            bugShape.setFillColor(sf::Color(0, 250, 250));
        }
        bugShape.setPosition(100 * bug->getPosition().first + (50-radius), 100*bug->getPosition().second + (50-radius));
        if(bug->getStatus() == "Alive"){
            window.draw(bugShape);
        }
    }
}

void Board::eat(vector<Bug*> &bugs, bool &messagePrinted){
    //        Check for if more bugs are in the same cell, two for each loops going through bugs vector
    for(Bug* bug1 : bugs){
        for(Bug* bug2 : bugs){
//                make sure the function is not checking if bug is itself in the same cell
            if(bug1 != bug2){
//                    if they are in the same cell and message has not been printed before print a message and set messagePrinted variable to true so the condition cannot be met again
//                     this way we do not get ton of messages when bugs are in the same cell but only one message
                if(Bug::areInSameCell(*bug1, *bug2) && !messagePrinted){
                    cout << "Bugs " << bug1->getId() << " and " << bug2->getId() << " in the same cell: " << bug1->positionToString(bug1->getPosition()) << endl;
                    Bug::eat(bugs);
                    messagePrinted = true;
//                    eat(vector<>);
                }
            }

        }
    }
}

// function that saves path taken and passes it into our file .out
void Board::printFileLifePath(vector<Bug*> &bugs){
    ofstream fout("bugs_life_history_date_time.out");
//    check if the file is open and if it is go through bugs and pass their path into the file
    if(fout){
        for(auto &pos : bugs){
            fout << pos->printPath();
        }
//        after close the file
        fout.close();
//        if it does not open get error message
    } else{
        cout << "Unable to open file." << endl;
    }
}

void Board::searchForBug(vector<Bug*> &bugs){
    cout << "Enter bugs ID: ";
    int bugId;
    cin >> bugId;
    for(Bug* bug : bugs){
        if(bug->getId() == bugId){
            cout << bug->printBug() << endl;
        }
    }
}