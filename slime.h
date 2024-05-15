#include <iostream>
#pragma once

class slime {
public:
    slime(std::string, int, int, int, int, int, int);
        
    void setName(std::string);
    void setColor(int);
    void addHunger(int);

    std::string getName() const;
    int getColor() const;
    int getHeight() const;
    int getWeight() const;
    int getAffection() const;
    int getHunger() const;
    int getType() const;
    int getPlayRepetition() const;
    int getPetHeadRepetitiion() const;

    void numbersCheck();
    void printInfo() const;
    void play();
    void petHead();
    void feed();

private:
    std::string name;
    short int affection, hunger, petHeadRepetitiion, playRepetition;
    unsigned short int color, height, weight, type;
};