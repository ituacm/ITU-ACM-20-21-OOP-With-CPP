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

    ~Player()
    {
        std::cout << "Player is destructed" << std::endl;
        // All member destructors are called
    }
};

// Why? Because RAII
class Laser{};
class Enemy{};

class Level
{
private:
    Player player;
    Laser* lasers;
    Enemy* enemies;
public:
    Level()
        :player("Player 1", 0, 0), lasers(new Laser[10]), enemies(new Enemy[10])
    { }

    ~Level()
    {
        delete[] lasers;
        delete[] enemies;
    }
};

// Example: Unique Ptr

class UniquePtrPlayer
{
private:
    Player* ptr;
public:
    UniquePtrPlayer(Player* ptr = nullptr)
        :ptr(ptr){}

    ~UniquePtrPlayer()
    {
        delete ptr;
    }
};

