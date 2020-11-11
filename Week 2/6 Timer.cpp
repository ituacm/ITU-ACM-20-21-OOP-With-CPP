#include <iostream>
#include <chrono>

class Timer
{
private:
    std::chrono::time_point<std::chrono::steady_clock> start;
public:
    Timer()
    {
        this->start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;

        float dt = duration.count() * 1000.0f;
        std::cout << "Timer finished in " << dt << "ms" << std::endl;
    }
};