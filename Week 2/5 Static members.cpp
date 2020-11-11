// Something like a global in a namespace
// Like keyboard and mouse only one instance is required in some cases

class EnemySpawner
{
private:
    static unsigned int enemyCount;
public:
    static void spawn()
    {
        enemyCount--;
    }
};
unsigned int EnemySpawner::enemyCount = 10;

class Enemy
{
private:
    static float targetX;
    static float targetY;
public:
    static void setTarget(float tagetX, float targetY)
    {
        Enemy::targetX = targetX;
        Enemy::targetY = targetY;
    }
};

class Level
{
public:
    Level(){}

    void update()
    {
        EnemySpawner::spawn();

        Enemy e1, e2;
        Enemy::setTarget(2, 3);
    }
};