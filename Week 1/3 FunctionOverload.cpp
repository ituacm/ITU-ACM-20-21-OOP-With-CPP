#include <cstdio>

struct Rect
{
    float x, y;
    float w, h;
};

struct Circle
{
    float x, y;
    float r;
};

float getArea(const Rect& rect)
{
    return rect.w * rect.h;
}

float getArea(const Circle& circle)
{
    return 3.1415f * circle.r * circle.r;
}

///////////////

void print(const char* x)
{
    printf("%s", x);
}

void print(int x)
{
    printf("%d", x);
}

void print(float x)
{
    printf("%f", x);
}