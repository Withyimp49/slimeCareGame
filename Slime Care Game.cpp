#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include "slime.h"

int random(int min, int max) { return min + (rand() % max); }

void space(int amount) {
    for (int x = 0; x < amount; x++) {
        std::cout << " ";
    }
}

void drawPicture(int index) {
    switch (index) {
    case 1:
        std::cout << "    ####\n"
                  << "  ########\n"
                  << " ##########\n"
                  << "###  ##  ###\n"
                  << "###  ##  ###\n"
                  << "############\n"
                  << "############\n"
                  << " ##########\n\n";
        break;
    case 2:
        std::cout << "    ####       ## ##\n"
                  << "  ########    #######\n"
                  << " ##########   #######\n"
                  << "###  ##  ###   #####\n"
                  << "###  ##  ###     #\n"
                  << "############\n"
                  << "############\n"
                  << " ##########\n\n";
        break;
    case 3:
        std::cout << "    ####\n"
                  << "  ########\n"
                  << " ##########\n"
                  << "### #### ###\n"
                  << "###  ##  ###\n"
                  << "############\n"
                  << "############\n"
                  << " ##########\n\n";
        break;
    case 4:
        std::cout << "     ####\n"
                  << "   ########\n"
                  << "  ##########\n"
                  << "  # R I P  #\n"
                  << "  ##########\n"
                  << "  ##########\n"
                  << "  ##########\n"
                  << "##############\n\n";
        break;
    case 5:
        std::cout << "################\n"
                  << "##### Bye  #####\n"
                  << "##### Bye  #####\n"
                  << "################\n"
                  << "      ####\n"
                  << "      ####\n"
                  << "      ####\n\n";
        break;
    default:
        std::cout << "ERROR LOADING IMAGE\n\n";
        break;
    }
}

int main(){
    srand(time(0));
    int response, callChance;
    bool gameOn = true;
    std::string naming = "Jerry";
    std::vector<slime> slimes;

    std::cout << "a slime has decided to become your pet! Give your first slime a name like 'Jerry' or something.\n";
    std::cin >> naming;
    slimes.push_back(slime (naming, 8, random(1, 4), random(10, 50), 10, random(76, 100), 2));

    while (gameOn) {
        for (int i = 0; i < slimes.size(); i++) {
            system("CLS");
            slimes[i].numbersCheck();
            if (slimes[i].getAffection() < 10) {
                drawPicture(3);
            }
            else if(slimes[i].getAffection() >= 20 ) {
                drawPicture(2);
            }
            else {
                drawPicture(1);
            }
            slimes[i].printInfo();
            std::cout << "\nthis is slime " << i + 1 << "/"  << slimes.size() << std::endl
                << "\nwhat would you like to do with " << slimes[i].getName()
                << "?\n0 = rename slime   1 = recolor slime   2 = release slime   3 = call for a new slime"
                << "\n4 = play with slime   5 = pet slime   6 = feed slime   7 = end game"
                << "\n\nplease type in one of the numbers to perform its related action\n";
            std::cin >> response;
            while (response > 7 || response < 0) {
                std::cout << "please type in a valid number response\n";
                std::cin >> response;
            }

            system("CLS");

            switch (response) {
            case 0:
                slimes[i].addHunger(-5);
                naming = " ";
                std::cout << " what would you like to name your slime? (OwO)\n";
                std::cin >> naming;
                slimes[i].setName(naming);
                std::cout << slimes[i].getName() << " likes its new name :3\n";
                system("pause>0");
                break;
            case 1:
                slimes[i].addHunger(-5);
                std::cout << "what color would you like to change your slime to:\n"
                    << "1 = black   2 = white   3 = grey   4 = brown   5 = blue   6 = green\n"
                    << "7 = purple   8 = pink   9 = red   10 = yellow   11 = orange   12 = rainbow"
                    << "\n\nplease type in one of the numbers to perform its related action\n";
                std::cin >> response;
                while (response > 12 || response < 1) {
                    std::cout << "please type in a valid number response\n";
                    std::cin >> response;
                }
                slimes[i].setColor(response);
                system("CLS");
                std::cout << slimes[i].getName() << " is looking stylish with their new color!\n";
                system("pause>0");
                break;
            case 2:
                drawPicture(5);
                std::cout << slimes[i].getName() << " was released. bye bye\n";
                slimes.erase(slimes.begin() + i);
                system("pause>0");
            case 3:
                slimes[i].addHunger(-5);
                callChance = random(1, slimes.size());
                if (callChance == 1) {                    
                    std::cout << "you called out for a slime...";
                    system("pause>0");
                    system("CLS");
                    drawPicture(1);
                    std::cout << "and a new slime friend came!\nwhat will you call it?\n";
                    std::cin >> naming;
                    slimes.push_back(slime(naming, random(1,12), random(1, 4), random(10, 50), 10, random(76, 100), random(1, 3)));
                    std::cout << "welcome to the family " << naming << std::endl;
                    system("pause>0");
                }
                else {
                    std::cout << "you called out for a slime...";
                    system("pause>0");
                    system("CLS");
                    std::cout << "but no slime came\n";
                    system("pause>0");
                }
                break;
            case 4:
                if (slimes[i].getPlayRepetition() > 2) {
                    drawPicture(3);
                }
                else {
                    drawPicture(1);
                }
                slimes[i].play();
                system("pause>0");           
                break;
            case 5:
                if (slimes[i].getPetHeadRepetitiion() > 2) {
                    drawPicture(3);
                }
                else {
                    drawPicture(1);
                }
                slimes[i].petHead();
                system("pause>0");
                break;
            case 6:
                if (slimes[i].getHunger() > 70) {
                    drawPicture(3);
                }
                else {
                    drawPicture(1);
                }
                slimes[i].feed();
                system("pause>0");
                break;
            case 7:
            default:
                gameOn = false;
                break;
            }

            if (slimes[i].getHunger() <= 0) {
                system("CLS");
                drawPicture(4);
                std::cout << "oh no! " << slimes[i].getName() << " has died from hunger :( you monster\n";
                slimes.erase(slimes.begin() + i);
                system("pause>0");
            }

            if (slimes[i].getAffection() <= 0) {
                system("CLS");
                drawPicture(5);
                std::cout << "oh no! " << slimes[i].getName() << " has run away because they don't like you\n";
                slimes.erase(slimes.begin() + i);
                system("pause>0");
            }

            if (slimes.size() == 0) {
                system("CLS");
                std::cout << " oh no! you have no more slimes to take care of! GAME OVER\n";
                return 0;
            }
        }
    }
    system("CLS");    
    std::cout << "you ended your time with your slimes. Don't worry, they'll be here waiting for you :)\n";
    return 0;
}