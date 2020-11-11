#include <iostream>

struct Rect{
    float x, y;
    float w, h;
};

int main()
{
    int x = 7;
    int& y = x;
    y = 3;
    std::cout << "x: " << x << "y: " << y << std::endl;
    x = 4;
    std::cout << "x: " << x << "y: " << y << std::endl;
    int z = 9;
    y = z;
    z = 8;
    x = 5;
    std::cout << "x: " << x << "y: " <<  y << "z: " << z << std::endl;
}


// Write it first with (Rect) 
void resizeRect(Rect* rect, float scale)
{
    rect->x *= scale;
    rect->y *= scale;
    // WARN
    rect = nullptr;

    // Then
    rect->x *= scale;
    rect->y *= scale;
}

void resizeRect(Rect& rect, float scale)
{
    rect.x *= scale;
    rect.y *= scale;
}

// Argument Passing
float getArea(Rect rect)
{
    return rect.w * rect.h;
}

float getArea(Rect* rect)
{
    return rect->w * rect->h;
}

float getArea(Rect& rect)
{
    return rect.w * rect.h;
}
