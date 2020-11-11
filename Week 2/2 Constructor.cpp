#include <string>
#include <iostream>

class Player
{
private:
    std::string name;
    float posX; // show = 0 
    float posY;

public:
    Player() // show calling the constructor
    {
        this->name = "Player";
        this->posX = 0;
        this->posY = 0;
        std::cout << "Default contructor is called" << std::endl;
    }

    Player(std::string name, float posX, float posY)
    {
        this->name = name;
        this->posX = posX;
        this->posY = posY;
    }
};
