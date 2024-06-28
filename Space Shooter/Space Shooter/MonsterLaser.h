#ifndef MONSTERLASER_H_
#define MONSTERLASER_H_

#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;

class MonsterLaser
{
public:
    Sprite sprite;
    Texture tex;
    bool isfired ;
    MonsterLaser()
    {
        tex.loadFromFile("img/monster_laser.png");
        sprite.setTexture(tex);
        sprite.setScale(0.13, 0.8);
        sprite.setPosition(-678, -678);
        isfired = false ;
    }
};

#endif