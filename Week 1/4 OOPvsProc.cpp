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
