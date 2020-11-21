namespace nsVector
{
    struct sVector
    {
        double x;
        double y;
    };
    
    sVector createVector(double x, double y)
    {
        sVector v;
        v.x = x;
        v.y = y;
        return v;
    }

    sVector& add(sVector* self, const sVector& vec)
    {
        self->x += vec.x;
        self->y += vec.y;
        return *self;
    }

    sVector s_add(const sVector& v1, const sVector& v2)
    {
        return createVector(v1.x + v2.x, v1.y + v2.y);
    }
}

// using namespace nsVector;
nsVector::sVector fr_add(const nsVector::sVector& v1, const nsVector::sVector& v2)
{
    return nsVector::createVector(v1.x + v2.x, v1.y + v2.y);
}
