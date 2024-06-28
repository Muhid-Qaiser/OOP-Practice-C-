#ifndef BOMB_H_
#define BOMB_H_

#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;

class Bomb
{

public:
    Sprite sprite;
    Texture tex;
    float delta_Y;
    bool collision = false ;
    bool dropped = false;
    Bomb()
    {
        tex.loadFromFile("img/enemy_laser.png");
        sprite.setTexture(tex);
        sprite.setScale(1, 1);
        sprite.setPosition(-679,-243) ;
    }

    void moveBomb()
    {
        delta_Y = 0.1;
        delta_Y *= 0.5;
        sprite.move(0, delta_Y);
        if (sprite.getPosition().y > 800)
        {
            dropped = false;
        }
        if ( collision == true )
        {
            sprite.setPosition(-1232,-1232);
        }
    }
};

#endif