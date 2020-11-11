// MORAL

// OOP
class Player
{
private:
	double posX;
	double posY;
	double direction;
	
public:
	Player();

	void Move(double targetX, double targetY);
	void Jump();
	void LookAt(double direction);
};


// Procedural
struct Player
{
	double posX;
	double posY;
	double direction;
};

Player createPlayer();
void PlayerMove(Player* player, double targetX, double targetY);
void PlayerJump(Player* player);
void PlayerLookAt(Player* player, double direction);

// USAGE
class Vec2i
{
private:// don't put first
    int x;
    int y;

public:// don't put at first
    void set(int x, int y);

    int getX();
    int getY();

    int sqMag();
};

int main()
{
    Vec2i myVec;
    myVec.set(5, 3);
}


void Vec2i::set(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Vec2i::getX()
{
    return x;
}

int Vec2i::sqMag()
{
    return x*x+y*y;
}
