#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Bullet
{
public:
    Texture texB;
    Sprite bullet;
    float bullet_speed = 1;
    bool collision = false ;
    bool isfired;

    Bullet()
    {
        isfired = false;
        texB.loadFromFile("img/PNG/Lasers/laserBlue01.png");
        bullet.setTexture(texB);
        bullet.setScale(0.6, 0.6);
    }

    void move_Bullet()
    {
        float delta_Y = -1 ;
        delta_Y *= bullet_speed ;
        bullet.move(0, delta_Y);
        if (bullet.getPosition().y < -20)
        {
            isfired = false;
        }
    }

};