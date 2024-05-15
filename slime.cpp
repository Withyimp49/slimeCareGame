#include "slime.h"

slime::slime(std::string n, int c, int h, int w, int a, int hu, int t)
{
    name = n;
    color = c;
    height = h;
    weight = w;
    affection = a;
    hunger = hu;
    type = t;
    petHeadRepetitiion = 0;
    playRepetition = 0;
}

void slime::setName(std::string change) { name = change; }
void slime::setColor(int amount) { color = amount; }
void slime::addHunger(int amount) { hunger += amount; }

std::string slime::getName() const { return name; }
int slime::getColor() const { return color; }
int slime::getHeight() const { return height; }
int slime::getWeight() const { return weight; }
int slime::getAffection() const { return affection; }
int slime::getHunger() const { return hunger; }
int slime::getType() const { return type; }
int slime::getPlayRepetition() const { return playRepetition; }
int slime::getPetHeadRepetitiion() const { return petHeadRepetitiion; }


void slime::numbersCheck() {
    if (petHeadRepetitiion < 0) {
        petHeadRepetitiion = 0;
    }
    if (playRepetition < 0) {
        playRepetition = 0;
    }
    if (affection > 25) {
        affection = 25;
    }
    if (hunger > 100) {
        hunger = 100;
    }
}
void slime::printInfo() const {
    std::cout << "Name: " << name << "\nHeight: " << height << " ft\nWeight: " << weight << " lbs\nColor: ";
    switch (color)
    {
    case 1:
        std::cout << "black";
        break;
    case 2:
        std::cout << "white";
        break;
    case 3:
        std::cout << "grey";
        break;
    case 4:
        std::cout << "brown";
        break;
    case 5:
        std::cout << "blue";
        break;
    case 6:
        std::cout << "green";
        break;
    case 7:
        std::cout << "purple";
        break;
    case 8:
        std::cout << "pink";
        break;
    case 9:
        std::cout << "red";
        break;
    case 10:
        std::cout << "yellow";
        break;
    case 11:
        std::cout << "orange";
        break;
    case 12:
        std::cout << "rainbow";
        break;
    default:
        std::cout << "pink";
        break;
    }
    std::cout << "\nSlime Type: ";
    switch (type) {
    case 1:
        std::cout << "regular";
        break;
    case 2:
        std::cout << "tabby cat";
        break;
    case 3:
        std::cout << "anemo wind";
        break;
    case 4:
        std::cout << "glowing";
        break;
    default:
        std::cout << "regular";
        break;
    }

    std::cout << "\nhunger:    ["; 
    for (int x = 0; x < hunger / 20; x++) {
        std::cout << "=";
    }
    for (int y = 0; y < 5 - (hunger / 20); y++) {
        std::cout << " ";
    }
    std::cout << "] " << hunger << "/100\naffection: [";
    for (int i = 0; i < affection / 5; i++) {
        std::cout << "=";
    }
    for (int e = 0; e < 5 - (affection / 5); e++) {
        std::cout << " ";
    }

    std::cout << "] " << affection / 5 << "/5\n";

    if (affection >= 20 && affection < 25) {
        std::cout << "you and " << name << "are really good friends!\n";
    }
    if (affection == 25) {
        std::cout << "you and " << name << "are the best of squishy friends!\n";
    }
    if (hunger < 21) {
        std::cout << name << " is gettin very hungry\n";
    }
}
void slime::play() {
    petHeadRepetitiion -= 2;
    hunger -= 15;
    if (playRepetition < 2) {
        std::cout << "you play with " << name <<
            " and they had fun\ntheir affection grows for you as they bounce and laugh\n";
        affection += 2;
    }
    else if (playRepetition == 2) {
        std::cout << "you play with " << name <<
            " and they're getting tired of playing\ntheir affection for you grows only a little as they become a sleepy slime\n";
        affection += 1;
    }
    else {
        std::cout << "you've played with " << name <<
            " too many times in a row and they don't like it\ntheir affection for you has decreased because they're exhausted\n";
        affection -= 5;
    }
    playRepetition++;
}
void slime::petHead() {
    playRepetition -= 2;
    hunger -= 5;
    if (petHeadRepetitiion < 2) {
        std::cout << "you pet " << name <<
            " and they like it\ntheir affection grows for you as they snuggle against your hand\n";
        affection += 2;
    }
    else if (petHeadRepetitiion == 2) {
        std::cout << "you pet " << name <<
            " but they're getting tired of head pats\ntheir affection grows only a little as they start becoming a pouty slime\n";
        affection += 1;
    }
    else {
        std::cout << "you've pet " << name <<
            " too many times in a row and they don't like it\ntheir affection has decreased because it's too much head patting\n";
        affection -= 5;
    }
    petHeadRepetitiion++;
}
void slime::feed() {
    petHeadRepetitiion--;
    playRepetition--;
    if (hunger > 70) {
        std::cout << name << " is too full to eat right now, they're a stuffed slime\n";
        affection -= 4;
    }
    else {
        std::cout << "you fed  " << name << "\nThey thought it was yummy\n";
    }
    hunger += (20 + (rand() % 30));
}