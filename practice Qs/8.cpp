#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Global function to compute distance between two coordinates
int CalculateDistance(int x1, int y1, int x2, int y2)
{
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

// Function to generate random X coordinate
int GetRandomScreenCoordinates_X()
{
    return rand() % 100 + 1; // Generating random X coordinate between 1 and 100
}

// Function to generate random Y coordinate
int GetRandomScreenCoordinates_Y()
{
    return rand() % 100 + 1; // Generating random Y coordinate between 1 and 100
}

// Forward declaration of classes
class Player;
class Enemy;
class Monster;
class Ninja;

class Player
{
private:
    int x;
    int y;
    int lifeLimit;

public:
    Player(int _x, int _y, int _lifeLimit) : x(_x), y(_y), lifeLimit(_lifeLimit) {}

    int GetX() const { return x; }
    int GetY() const { return y; }
    int GetLifeLimit() const { return lifeLimit; }

    void SetX(int _x) { x = _x; }
    void SetY(int _y) { y = _y; }

    void ReduceLife(int amount)
    {
        lifeLimit -= amount;
        if (lifeLimit < 0)
        {
            lifeLimit = 0;
        }
    }
};

class Enemy
{
private:
    int x;
    int y;

public:
    Enemy(int _x, int _y) : x(_x), y(_y) {}

    int GetX() const { return x; }
    int GetY() const { return y; }

    virtual ~Enemy() {}
};

class Monster : public Enemy
{
public:
    Monster(int _x, int _y) : Enemy(_x, _y) {}
};

class Ninja : public Enemy
{
public:
    Ninja(int _x, int _y) : Enemy(_x, _y) {}
};

class ABC_Game
{
private:
    Player *player;
    Enemy *enemies[10];
    int enemyCount;

public:
    ABC_Game() : player(nullptr), enemyCount(0)
    {
        for (int i = 0; i < 10; i++)
        {
            enemies[i] = nullptr;
        }
    }

    ~ABC_Game()
    {
        if (player != nullptr)
        {
            delete player;
        }

        for (int i = 0; i < enemyCount; i++)
        {
            delete enemies[i];
        }
    }

    void AddPlayer(Player *p)
    {
        if (player == nullptr)
        {
            player = p;
        }
        else
        {
            std::cout << "Player already exists in the game!" << std::endl;
        }
    }

    void AddEnemy(Enemy *e)
    {
        if (enemyCount < 10)
        {
            enemies[enemyCount] = e;
            enemyCount++;
        }
        else
        {
            std::cout << "Maximum number of enemies reached!" << std::endl;
        }
    }

    int GetPlayersLifeCount()
    {
        if (player != nullptr)
        {
            return player->GetLifeLimit();
        }
        return 0;
    }

    void Play()
    {
        for (int i = 0; i < enemyCount; i++)
        {
            if (enemies[i] != nullptr)
            {
                if (Monster *monster = dynamic_cast<Monster *>(enemies[i]))
                {
                    if (CalculateDistance(player->GetX(), player->GetY(), monster->GetX(), monster->GetY()) > 10)
                    {
                        player->ReduceLife(2);
                        std::cout << "Monster attacked with a Gun" << std::endl;
                    }
                }
                else if (Ninja *ninja = dynamic_cast<Ninja *>(enemies[i]))
                {
                    if (CalculateDistance(player->GetX(), player->GetY(), ninja->GetX(), ninja->GetY()) < 10)
                    {
                        player->ReduceLife(1);
                        std::cout << "Ninja attacked with a knife" << std::endl;
                    }
                }
            }
        }
    }

    void MovePlayer()
    {
        if (player != nullptr)
        {
            int newX = GetRandomScreenCoordinates_X();
            int newY = GetRandomScreenCoordinates_Y();
            player->SetX(newX);
            player->SetY(newY);
        }
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator

    ABC_Game game;
    int x = GetRandomScreenCoordinates_X();
    int y = GetRandomScreenCoordinates_Y();
    game.AddPlayer(new Player(x, y, 10));

    while (game.GetPlayersLifeCount() > 0)
    {
        int randomNumber = rand() % 10;

        if (randomNumber == 1)
        {
            int x1 = GetRandomScreenCoordinates_X();
            int y1 = GetRandomScreenCoordinates_Y();
            game.AddEnemy(new Ninja(x1, y1));
        }
        else if (randomNumber == 2)
        {
            int x1 = GetRandomScreenCoordinates_X();
            int y1 = GetRandomScreenCoordinates_Y();
            game.AddEnemy(new Monster(x1, y1));
        }

        game.Play();
        game.MovePlayer();
    }

    return 0;
}
