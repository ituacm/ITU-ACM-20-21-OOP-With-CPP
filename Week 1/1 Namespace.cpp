// Give example to sin function


// Decleration
namespace myNS {
    struct vec2i {
        int a, b;
    };
    int x;
    int y;
    int someFunction();
}

namespace myNS 
{
	struct vec2f 
	{
		float x, y;
	};

	float sin(float angle);
	float getAngle(vec2f v);
}

// Usage
int main()
{
    myNS::vec2i v;
    v.a = 5;
    v.b = 2;

    myNS::x = 9;
    int y = someFunction();
}

// Using
using namespace myNS;

int main()
{
    vec2i v;
    v.a = 5;
    v.b = 2;

    x = 9;
    int y = someFunction();
}

// Error in 'using'

using namespace myNS;
// int x;

int main()
{
    vec2i v;
    v.a = 5;
    v.b = 2;

    x = 9;
    someFunction();
}

// Declerating outside

int myNS::someFunction()
{
   return myNS::x + myNS::y; 
}

// Extending
namespace myNS{
    void otherFunc();
}

// Nested
namespace myNS{
    int calculate(int y);
    namespace otherNS{
        int func();
    }
}

int main()
{
    int x = myNS::otherNS::func();
}