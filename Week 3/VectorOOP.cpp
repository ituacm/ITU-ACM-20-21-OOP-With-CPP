class Vector
{
private:
    double x;
    double y;

public:
    Vector(double x, double y)
        : x(x), y(y)
    {
    }

    Vector& add(const Vector& vec)
    {
        this->x += vec.x;
        this->y += vec.y;
        return *this;
    }

    static Vector s_add(const Vector& v1, const Vector& v2)
    {
        return Vector(v1.x + v2.x, v1.y + v2.y);
    }

    friend Vector fr_add(const Vector& v1, const Vector& v2);
};

Vector fr_add(const Vector& v1, const Vector& v2)
{
    return Vector(v1.x + v2.x, v1.y + v2.y);
}