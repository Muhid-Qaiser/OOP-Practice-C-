
#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>
#include "Bomb.h"
#include "MonsterLaser.h"
#include "DragonLaser.h"
#include <string.h>
using namespace sf;

class Enemy
{
public:
    Sprite sprite;
    Texture tex;
    Bomb *bomb;
    MonsterLaser *laser;
    DragonLaser *dragonlaser;
    bool killed = false;
    bool activate = false;
    bool left = false ;
    bool straight = false ;
    bool right = false ;
    int no_of_bombs = 3;
    int no_of_dragonlasers = 15;
    bool positionset = false ;
    bool laser_set = false ;
    bool laser_isActive = false ;
    virtual void position_set () = 0 ;
    virtual void move_the_monster () = 0 ;
    virtual void display_laser_monster(std::string s) = 0 ;
    virtual void iskilled() = 0;
    virtual void set_bomb_position() = 0;
    virtual void move_bomb() = 0;
};

#endif
