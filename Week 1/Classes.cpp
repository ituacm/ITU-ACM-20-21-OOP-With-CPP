class Vec2i
{
private:// don't put first
    int x;
    int y;

public:// don't put at first
    void set(int valX, int valY);

    int getX();
    int getY();

    int sqMag();
};

int main()
{
    Vec2i myVec;
    myVec.set(5, 3);
}


void Vec2i::set(int valX, int valY)
{
    x = valX;
    y = valY;
}

int Vec2i::getX()
{
    return x;
}

int Vec2i::sqMag()
{
    return x*x+y*y;
}