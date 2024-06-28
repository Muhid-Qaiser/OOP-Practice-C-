#ifndef DRAGON_H_
#define DRAGON_H_

#include <SFML/Graphics.hpp>
#include <string.h>
#include "Enemy.h"
using namespace sf;

class Dragon : public Enemy
{
public:
    Dragon(std::string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setScale(1, 1);
        sprite.setPosition(280, -300);
        dragonlaser = new DragonLaser[no_of_dragonlasers];
    }

    virtual void position_set()
    {

        if (!positionset)
        {
            sprite.move(0, 0.1);
            if (sprite.getPosition().y >= 100)
                positionset = true;
        }
    }

    virtual void display_laser_monster(std::string s)
    {
        if (positionset)
        {
            for (int i = 0, j = 0; i < no_of_dragonlasers; i++, j += dragonlaser[i].sprite.getGlobalBounds().height - 3)
            {
                if (s == "s")
                {
                    dragonlaser[i].sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - 20, j + sprite.getPosition().y + sprite.getGlobalBounds().height - dragonlaser[i].sprite.getGlobalBounds().height + 30);
                }
                else if (s == "l")
                {
                    dragonlaser[i].sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - 40 - j, j + sprite.getPosition().y + sprite.getGlobalBounds().height - dragonlaser[i].sprite.getGlobalBounds().height + 30);
                }
                else if (s == "r")
                {
                    dragonlaser[i].sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2 + j, j + sprite.getPosition().y + sprite.getGlobalBounds().height - dragonlaser[i].sprite.getGlobalBounds().height + 30);
                }
            }
        }
    }

    virtual void move_bomb(){}
    virtual void move_the_monster() {}
    virtual void iskilled() {}
    virtual void set_bomb_position() {}
};

#endif