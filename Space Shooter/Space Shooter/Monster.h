
#ifndef MONSTER_H_
#define MONSTER_H_

#include <SFML/Graphics.hpp>
#include <string.h>
#include "Enemy.h"
using namespace sf;

class Monster : public Enemy
{
public:
    virtual void iskilled() {}
    virtual void set_bomb_position() {}
    virtual void move_bomb() {}
    Monster(std::string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setScale(0.1, 0.1);
        sprite.setPosition(-300, -100);
        laser = new MonsterLaser;
    }

    virtual void position_set()
    {
        if (!positionset)
        {
            sprite.setPosition(600, 100);
            positionset = true;
            right = true;
        }
    }
    virtual void move_the_monster()
    {
        if (right)
        {
            sprite.move(0.1, 0);
            if (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > 780)
                right = false;
        }
        else
        {
            sprite.move(-0.1, 0);
            if (sprite.getGlobalBounds().left < 0)
                right = true;
        }
    }

    virtual void display_laser_monster(std::string s)
    {
        laser->sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - 6, sprite.getPosition().y + sprite.getGlobalBounds().height - 80);
    }

};

#endif