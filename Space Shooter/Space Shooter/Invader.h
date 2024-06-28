
#ifndef INVADER_H_
#define INVADER_H_

#include <SFML/Graphics.hpp>
#include <string.h>
#include "Enemy.h"
using namespace sf;

class Invader : public Enemy
{
public:
    Invader()
    {
        bomb = new Bomb[no_of_bombs];
    }

    virtual void iskilled()
    {
        killed = true;
    }

    virtual void set_bomb_position()
    {
        for (int i = 0; i < no_of_bombs; i++)
        {
            if (!bomb[i].dropped && killed == false)
            {
                bomb[i].sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - 15 , sprite.getPosition().y + sprite.getGlobalBounds().height);
                bomb[i].dropped = true;
                break;
            }
        }
    }

    virtual void move_bomb() 
    {
        for (int i = 0; i < no_of_bombs; i++)
        {
            if (bomb[i].dropped)
            {
               bomb[i].moveBomb();
            }
        }
    }

    virtual void position_set () {}
    virtual void move_the_monster () {}
    virtual void display_laser_monster(std::string s) {}
    virtual void drop_laser_monster() {}
};

class Alpha : public Invader
{
public:
    Alpha(std::string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setScale(0.5, 0.5);
        sprite.setPosition(-100, -100);
    }
};

class Beta : public Invader
{
public:
    Beta(std::string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setScale(0.5, 0.5);
        sprite.setPosition(-100, -100);
    }
};

class Gamma : public Invader
{
public:
    Gamma(std::string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setScale(0.5, 0.5);
        sprite.setPosition(-100, -100);
    }
};

#endif