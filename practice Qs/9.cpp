#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

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
    int x, y, life;

public:
    Player() : x(0), y(0), life(0) {}
    Player(int a, int b, int c) : x(a), y(b), life(c) {}
    void SetX(int a) { x = a; }
    void SetY(int a) { y = a; }
    int getX() const { return x; }
    int getY() const { return y; }
    int getLife() const { return life; }
    void reduceLife(int a)
    {
        life -= a;
    }
};

class Enemy
{
protected:
    int x, y;

public:
    Enemy(int a, int b) : x(a), y(b) {}
    int getX() const { return x; }
    int getY() const { return y; }
    virtual int getAttack() const = 0;
};

class Ninja : public Enemy
{
public:
    Ninja(int x, int y) : Enemy(x, y) {}
    int getAttack() const { return 1; }
};

class Monster : public Enemy
{
public:
    Monster(int x, int y) : Enemy(x, y) {}
    int getAttack() const { return 2; }
};

class ABC_Game
{
    Enemy *enemy[10];
    Player *player;
    int e_count;

public:
    ABC_Game() : player(NULL), e_count(0)
    {
        for (int i = 0; i < 10; i++)
        {
            enemy[i] = NULL;
        }
    }
    void AddPlayer(Player *obj)
    {
        if (player == NULL)
            player = obj;
        else
            cout << "Player already exists!" << endl;
    }
    int GetPlayersLifeCount()
    {
        return player->getLife();
    }
    void AddEnemy(Enemy *enemy)
    {
        if (e_count <= 10)
            this->enemy[e_count++] = enemy;
        else
            cout << "Max Enemy Count Reached!" << endl;
    }
    void Play()
    {
        if (player != NULL)
        {
            for (int i = 0; i < e_count; i++)
            {
                if (enemy[i]->getAttack() == 1)
                {
                    if (CalculateDistance(player->getX(), player->getY(), enemy[i]->getX(), enemy[i]->getY()) < 10)
                    {
                        player->reduceLife(1);
                        cout << "Ninja Attacked with a Knife!" << endl;
                    }
                }
                else if (enemy[i]->getAttack() == 2)
                {
                    if (CalculateDistance(player->getX(), player->getY(), enemy[i]->getX(), enemy[i]->getY()) > 10)
                    {
                        player->reduceLife(2);
                        cout << "Monster Attacked with a Gun!" << endl;
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
