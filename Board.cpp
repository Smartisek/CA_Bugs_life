//
// Created by domal on 16/04/2024.
//

#include <fstream>
#include <sstream>
#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"

void Board::drawBoard(sf::RenderWindow &window) {
    for(sf::RectangleShape &r : background){
        window.draw(r);
    }
}

void Board::drawBugs(vector<Bug *> bugs, sf::RenderWindow &window) {
    for(Bug* bug : bugs){
        sf::Sprite bugSprite;
        float scale = static_cast<float>(bug->getSize() *50.0)/ 1920; //set a scale for bugs
        if(bug->getType() == "Crawler"){
            bugSprite.setTexture(crawlerTexture); //set texture for each bug
        } else if (bug->getType() == "Hopper"){
            bugSprite.setTexture(hopperTexture);
        }
        bugSprite.setOrigin(bugSprite.getTexture()->getSize().x / 2.0f, bugSprite.getTexture()->getSize().y / 2.0f); //center the image
        bugSprite.setScale(scale, scale); //set scale for image
        bugSprite.setPosition(100*bug->getPosition().first  + 50, 100*bug->getPosition().second+ 50); // set position like before

        if(bug->getStatus() == "Alive"){
            window.draw(bugSprite);
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

vector<Bug*> Board::loadBugsFromFile(){
    vector<Bug*> bugs;
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
//    after reading data, close the file
    bugFile.close();
    for(int i=0; i<bugs.size(); i++){
        cout << bugs[i]->printBug() << endl;
    }
    return bugs;
}


// https://www.pngwing.com/en/free-png-xyjou/download
// https://www.pngwing.com/en/free-png-zpydh/download