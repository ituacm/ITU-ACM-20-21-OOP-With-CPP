#include <string>
#include <iostream>

class Player
{
private:
    std::string name;
    float posX, posY;

public:
    Player()
        : name("Player"), posX(0), posY(0)
    {
        std::cout << "Default contructor is called" << std::endl;
    }

    Player(std::string name, float posX, float posY)
        :name(name), posX(posX), posY(posY)
    {
    }
};
