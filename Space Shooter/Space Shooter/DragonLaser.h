#ifndef DRAGONLASER_H_
#define DRAGONLASER_H_

#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;

class DragonLaser
{
public:
    Sprite sprite;
    Texture tex;
    bool is_set ;
    DragonLaser()
    {
        tex.loadFromFile("img/laserBlue08.png");
        sprite.setTexture(tex);
        sprite.setScale(0.7,0.7);
        sprite.setPosition(-345,-345);
        is_set = false ;
    }
};

#endif