
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <math.h>
#include <iostream>
using namespace std;
#include "player.h"
#include "Invader.h"
#include "Monster.h"
#include "Dragon.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
    Sprite background; // Game background sprite
    Texture bg_texture;
    Player *p;      // player
    Enemy *alpha;   // alpha enemy
    Enemy *beta;    // beta enemy
    Enemy *gamma;   // gamma enemy
    Enemy *monster; // monster enemy
    Enemy *dragon;
    int enemyships = 3;
    int level01_counter = 0;
    int health = 10;
    int score = 0;
    bool sub_level01 = false;
    bool sub_level02 = false;
    bool sub_level03 = false;
    bool sub_level04 = false;
    bool sub_level05 = false;
    bool sub_level06 = false;
    bool sub_level07 = false;
    bool sub_level08 = false;
    bool sub_level09 = false;
    int previous_health = 0;
    sf::Font font;
    sf::Text text, text1,text2;

    Sprite image;
    Texture im_tex;

    Sprite PauseMenu ;
    Texture tex4;

    bool checkphase1 = true, checkphase2 = true, checkphase3 = true, monstercheck = true, dragoncheck = true;
    bool killmonster = false;
    Game()
    {
        p = new Player("img/player_ship.png");
        bg_texture.loadFromFile("img/galaxy_bg.jpg");
        background.setTexture(bg_texture);
        background.setScale(0.4, 0.4);
        alpha = new Alpha[3]{
            Alpha("img/enemy_1.png"),
            Alpha("img/enemy_1.png"),
            Alpha("img/enemy_1.png")};
        beta = new Beta[3]{
            Beta("img/enemy_2.png"),
            Beta("img/enemy_2.png"),
            Beta("img/enemy_2.png")};
        gamma = new Gamma[3]{
            Gamma("img/enemy_3.png"),
            Gamma("img/enemy_3.png"),
            Gamma("img/enemy_3.png")};
        monster = new Monster("img/monster.png");
        dragon = new Dragon("img/dragon.png");

        im_tex.loadFromFile("img/InvadersIncoming.png");
        image.setTexture(im_tex);

        if (!font.loadFromFile("img/Quantify.ttf"))
            cout << " Error ! ";

        tex4.loadFromFile("img/Pause.jpg");
        PauseMenu.setTexture(tex4);

        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Green);
        text.setPosition(600, 10);
        text1.setFont(font);
        text1.setCharacterSize(24);
        text1.setFillColor(sf::Color::Red);
        text1.setPosition(600, 40);
        text2.setFont(font);
        text2.setCharacterSize(15);
        text2.setFillColor(sf::Color::White);
        text2.setPosition(10,10);
    }
    void start_game()
    {
        srand(time(0));
        RenderWindow window(VideoMode(780, 780), title);
        Clock clock;
        sf::Clock bulletTimer;
        sf::Clock enemyTimer;
        sf::Clock bombTimeralpha;
        sf::Clock bombTimerbeta;
        sf::Clock bombTimergamma;
        sf::Clock MonsterTimer;
        sf::Clock DragonTimer;
        float timer = 0;
        sf::Music music;
        if (!music.openFromFile("img/song.ogg"))
        {
            std::cerr << "Failed to load music file" << std::endl;
        }
        music.setLoop(true);
        music.play();

        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close();          // close the game
            }

            if (Keyboard::isKeyPressed(Keyboard::Left))  // If left key is pressed
                p->move("l");                            // Player will move to left
            if (Keyboard::isKeyPressed(Keyboard::Up))    // If up key is pressed
                p->move("u");                            // playet will move upwards
            if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                p->move("r");                            // player will move to right
            if (Keyboard::isKeyPressed(Keyboard::Down))  // If down key is pressed
                p->move("d");

            if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
                p->move("ul");
            if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
                p->move("ur");
            if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left))
                p->move("lb");
            if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right))
                p->move("rb");
            if (Keyboard::isKeyPressed(Keyboard::P))
            {
                bool inPauseMenu = true; 
                while (inPauseMenu)
                {
                    sf::Event e1;
                    while (window.pollEvent(e1))
                    {
                        if (e1.type == sf::Event::Closed || e1.key.code == sf::Keyboard::Num4)
                        {
                            inPauseMenu = false; 
                        }
                    }
                    window.clear(sf::Color::Black);
                    window.draw(PauseMenu);
                    window.display();
                }
            }

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////      Call your functions here        //////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////
            ////////////// Bullets of Player //////////////
            ///////////////////////////////////////////////

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                float elapsed = bulletTimer.getElapsedTime().asSeconds();
                if (elapsed >= 0.3f)
                {
                    bulletTimer.restart();
                    p->set_bullet();
                }
                for (int i = 0; i < p->no_of_bullets; i++)
                {
                    p->b[i].collision = false;
                }
            }
            p->move_bullet();

            ///////////////////////////////////////////////
            ///////////////////////////////////////////////
            ///////////////////////////////////////////////

            ///////////////////////////////////////////////
            //////////////       Invaders       ///////////
            ///////////////////////////////////////////////

            float elapsed_enemytime = enemyTimer.getElapsedTime().asSeconds();

            if (level01_counter == 0)
            {
                sub_level01 = true;
                sub_level02 = false;
                sub_level03 = false;
                sub_level04 = false;
                sub_level05 = false;
                sub_level06 = false;
                sub_level07 = false;
                sub_level08 = false;
                sub_level09 = false;
                for (int i = 0; i < enemyships; i++)
                {
                    alpha[i].killed = false;
                    beta[i].killed = false;
                    gamma[i].killed = false;
                }
            }
            if (level01_counter == 9)
            {
                sub_level01 = false;
                sub_level02 = true;
                sub_level03 = false;
                sub_level04 = false;
                sub_level05 = false;
                sub_level06 = false;
                sub_level07 = false;
                sub_level08 = false;
                sub_level09 = false;
                for (int i = 0; i < enemyships; i++)
                {
                    alpha[i].killed = false;
                    beta[i].killed = false;
                    gamma[i].killed = false;
                }
                for (int i = 0; i < enemyships; i++)
                {
                    for (int j = 0; j < alpha[i].no_of_bombs; j++)
                    {
                        alpha[i].bomb[j].sprite.setPosition(-1000, -1000);
                        beta[i].bomb[j].sprite.setPosition(-1000, -1000);
                        gamma[i].bomb[j].sprite.setPosition(-1000, -1000);
                        alpha[i].bomb[j].dropped = false;
                        beta[i].bomb[j].dropped = false;
                        gamma[i].bomb[j].dropped = false;
                    }
                }
                p->sprite.setPosition(360, 700);
            }
            if (level01_counter == 18)
            {
                sub_level01 = false;
                sub_level02 = false;
                sub_level03 = true;
                sub_level04 = false;
                sub_level05 = false;
                sub_level06 = false;
                sub_level07 = false;
                sub_level08 = false;
                sub_level09 = false;
                for (int i = 0; i < enemyships; i++)
                {
                    alpha[i].killed = false;
                    beta[i].killed = false;
                    gamma[i].killed = false;
                }
                for (int i = 0; i < enemyships; i++)
                {
                    for (int j = 0; j < alpha[i].no_of_bombs; j++)
                    {
                        alpha[i].bomb[j].sprite.setPosition(-1000, -1000);
                        beta[i].bomb[j].sprite.setPosition(-1000, -1000);
                        gamma[i].bomb[j].sprite.setPosition(-1000, -1000);
                        alpha[i].bomb[j].dropped = false;
                        beta[i].bomb[j].dropped = false;
                        gamma[i].bomb[j].dropped = false;
                    }
                }
                p->sprite.setPosition(360, 700);
            }
            if (level01_counter == 27)
            {
                sub_level01 = false;
                sub_level02 = false;
                sub_level03 = false;
                sub_level04 = true;
                sub_level05 = false;
                sub_level06 = false;
                sub_level07 = false;
                sub_level08 = false;
                sub_level09 = false;
                for (int i = 0; i < enemyships; i++)
                {
                    alpha[i].killed = false;
                    beta[i].killed = false;
                    gamma[i].killed = false;
                }
                for (int i = 0; i < enemyships; i++)
                {
                    for (int j = 0; j < alpha[i].no_of_bombs; j++)
                    {
                        alpha[i].bomb[j].sprite.setPosition(-1000, -1000);
                        beta[i].bomb[j].sprite.setPosition(-1000, -1000);
                        gamma[i].bomb[j].sprite.setPosition(-1000, -1000);
                        alpha[i].bomb[j].dropped = false;
                        beta[i].bomb[j].dropped = false;
                        gamma[i].bomb[j].dropped = false;
                    }
                }
                p->sprite.setPosition(360, 700);
            }
            if (level01_counter == 35)
            {
                sub_level01 = false;
                sub_level02 = false;
                sub_level03 = false;
                sub_level04 = false;
                sub_level05 = true;
                sub_level06 = false;
                sub_level07 = false;
                sub_level08 = false;
                sub_level09 = false;
                for (int i = 0; i < enemyships; i++)
                {
                    alpha[i].killed = false;
                    beta[i].killed = false;
                    gamma[i].killed = false;
                }
                for (int i = 0; i < enemyships; i++)
                {
                    for (int j = 0; j < alpha[i].no_of_bombs; j++)
                    {
                        alpha[i].bomb[j].sprite.setPosition(-1000, -1000);
                        beta[i].bomb[j].sprite.setPosition(-1000, -1000);
                        gamma[i].bomb[j].sprite.setPosition(-1000, -1000);
                        alpha[i].bomb[j].dropped = false;
                        beta[i].bomb[j].dropped = false;
                        gamma[i].bomb[j].dropped = false;
                    }
                }
                p->sprite.setPosition(360, 700);
            }
            if (level01_counter == 43)
            {
                sub_level01 = false;
                sub_level02 = false;
                sub_level03 = false;
                sub_level04 = false;
                sub_level05 = false;
                sub_level06 = true;
                sub_level07 = false;
                sub_level08 = false;
                sub_level09 = false;
                for (int i = 0; i < enemyships; i++)
                {
                    alpha[i].killed = false;
                    beta[i].killed = false;
                    gamma[i].killed = false;
                }
                for (int i = 0; i < enemyships; i++)
                {
                    for (int j = 0; j < alpha[i].no_of_bombs; j++)
                    {
                        alpha[i].bomb[j].sprite.setPosition(-1000, -1000);
                        beta[i].bomb[j].sprite.setPosition(-1000, -1000);
                        gamma[i].bomb[j].sprite.setPosition(-1000, -1000);
                        alpha[i].bomb[j].dropped = false;
                        beta[i].bomb[j].dropped = false;
                        gamma[i].bomb[j].dropped = false;
                    }
                }
                p->sprite.setPosition(360, 700);
            }
            if (level01_counter == 51)
            {
                sub_level01 = false;
                sub_level02 = false;
                sub_level03 = false;
                sub_level04 = false;
                sub_level05 = false;
                sub_level06 = false;
                sub_level07 = true;
                sub_level08 = false;
                sub_level09 = false;
                for (int i = 0; i < enemyships; i++)
                {
                    alpha[i].killed = false;
                    beta[i].killed = false;
                    gamma[i].killed = false;
                }
                for (int i = 0; i < enemyships; i++)
                {
                    for (int j = 0; j < alpha[i].no_of_bombs; j++)
                    {
                        alpha[i].bomb[j].sprite.setPosition(-1000, -1000);
                        beta[i].bomb[j].sprite.setPosition(-1000, -1000);
                        gamma[i].bomb[j].sprite.setPosition(-1000, -1000);
                        alpha[i].bomb[j].dropped = false;
                        beta[i].bomb[j].dropped = false;
                        gamma[i].bomb[j].dropped = false;
                    }
                }
                p->sprite.setPosition(360, 700);
            }
            if (level01_counter == 60)
            {
                sub_level01 = false;
                sub_level02 = false;
                sub_level03 = false;
                sub_level04 = false;
                sub_level05 = false;
                sub_level06 = false;
                sub_level07 = false;
                sub_level08 = true;
                sub_level09 = false;
                for (int i = 0; i < enemyships; i++)
                {
                    alpha[i].killed = false;
                    beta[i].killed = false;
                    gamma[i].killed = false;
                }
                for (int i = 0; i < enemyships; i++)
                {
                    for (int j = 0; j < alpha[i].no_of_bombs; j++)
                    {
                        alpha[i].bomb[j].sprite.setPosition(-1000, -1000);
                        beta[i].bomb[j].sprite.setPosition(-1000, -1000);
                        gamma[i].bomb[j].sprite.setPosition(-1000, -1000);
                        alpha[i].bomb[j].dropped = false;
                        beta[i].bomb[j].dropped = false;
                        gamma[i].bomb[j].dropped = false;
                    }
                }
                p->sprite.setPosition(360, 700);
            }
            if (level01_counter == 69)
            {
                sub_level01 = false;
                sub_level02 = false;
                sub_level03 = false;
                sub_level04 = false;
                sub_level05 = false;
                sub_level06 = false;
                sub_level07 = false;
                sub_level08 = false;
                sub_level09 = true;
                for (int i = 0; i < enemyships; i++)
                {
                    alpha[i].killed = false;
                    beta[i].killed = false;
                    gamma[i].killed = false;
                }
                for (int i = 0; i < enemyships; i++)
                {
                    for (int j = 0; j < alpha[i].no_of_bombs; j++)
                    {
                        alpha[i].bomb[j].sprite.setPosition(-1000, -1000);
                        beta[i].bomb[j].sprite.setPosition(-1000, -1000);
                        gamma[i].bomb[j].sprite.setPosition(-1000, -1000);
                        alpha[i].bomb[j].dropped = false;
                        beta[i].bomb[j].dropped = false;
                        gamma[i].bomb[j].dropped = false;
                    }
                }
                p->sprite.setPosition(360, 700);
            }
            if (level01_counter == 78)
            {
                sub_level01 = false;
                sub_level02 = false;
                sub_level03 = false;
                sub_level04 = false;
                sub_level05 = false;
                sub_level06 = false;
                sub_level07 = false;
                sub_level08 = false;
                sub_level09 = false;
                for (int i = 0; i < enemyships; i++)
                {
                    alpha[i].killed = true;
                    beta[i].killed = true;
                    gamma[i].killed = true;
                }
                for (int i = 0; i < enemyships; i++)
                {
                    for (int j = 0; j < alpha[i].no_of_bombs; j++)
                    {
                        alpha[i].bomb[j].sprite.setPosition(-1000, -1000);
                        beta[i].bomb[j].sprite.setPosition(-1000, -1000);
                        gamma[i].bomb[j].sprite.setPosition(-1000, -1000);
                    }
                }
                MonsterTimer.restart();
            }

            if (level01_counter == 0)
            {
                if (checkphase1 == true)
                {
                    window.clear();
                    sf::Clock clock;
                    while (clock.getElapsedTime().asSeconds() < 2)
                    {
                        window.draw(image);
                        window.display();
                    }
                    window.clear();
                    im_tex.loadFromFile("img/InvaderPhase1.png");
                    while (clock.getElapsedTime().asSeconds() > 2 && clock.getElapsedTime().asSeconds() < 4)
                    {
                        window.draw(image);
                        window.display();
                    }
                    checkphase1 = false;
                }
            }
            if (level01_counter == 27)
            {
                if (checkphase2 == true)
                {
                    window.clear();
                    sf::Clock clock;
                    im_tex.loadFromFile("img/InvaderPhase2.png");
                    while (clock.getElapsedTime().asSeconds() < 2)
                    {
                        window.draw(image);
                        window.display();
                    }
                    checkphase2 = false;
                }
            }
            if (level01_counter == 51)
            {
                if (checkphase3 == true)
                {
                    window.clear();
                    sf::Clock clock;
                    im_tex.loadFromFile("img/InvaderPhase3.png");
                    while (clock.getElapsedTime().asSeconds() < 2)
                    {
                        window.draw(image);
                        window.display();
                    }
                    checkphase3 = false;
                }
            }
            if (level01_counter == 78)
            {
                if (monstercheck == true)
                {
                    window.clear();
                    sf::Clock clock;
                    im_tex.loadFromFile("img/MonsterIncoming.png");
                    while (clock.getElapsedTime().asSeconds() < 2)
                    {
                        window.draw(image);
                        window.display();
                    }
                    monstercheck = false;
                    level01_counter = 79;
                }
            }
            if (level01_counter == 80)
            {
                if (dragoncheck == true)
                {
                    window.clear();
                    sf::Clock clock;
                    im_tex.loadFromFile("img/DragonIncoming.png");
                    while (clock.getElapsedTime().asSeconds() < 2)
                    {
                        window.draw(image);
                        window.display();
                    }
                    dragoncheck = false;
                    DragonTimer.restart();
                    level01_counter = 81;
                }
            }

            if (elapsed_enemytime >= 2.0f)
            {
                ////////////////// Rectangle ////////////////////////
                if (sub_level01)
                {
                    for (int i = 0; i < enemyships; i++)
                    {
                        if (!alpha[i].killed)
                        {
                            alpha[0].sprite.setPosition(156, 100);
                            alpha[1].sprite.setPosition(468, 200);
                            alpha[2].sprite.setPosition(312, 300);
                        }
                        if (!beta[i].killed)
                        {
                            beta[0].sprite.setPosition(312, 100);
                            beta[1].sprite.setPosition(156, 200);
                            beta[2].sprite.setPosition(468, 300);
                        }
                        if (!gamma[i].killed)
                        {
                            gamma[0].sprite.setPosition(468, 100);
                            gamma[1].sprite.setPosition(312, 200);
                            gamma[2].sprite.setPosition(156, 300);
                        }
                    }
                }
                //////////////////// Triangle ////////////////////////
                else if (sub_level02)
                {
                    for (int i = 0; i < enemyships; i++)
                    {
                        if (!alpha[i].killed)
                        {
                            alpha[0].sprite.setPosition(390, 100);
                            alpha[1].sprite.setPosition(487.5, 200);
                            alpha[2].sprite.setPosition(195, 300);
                        }
                        if (!beta[i].killed)
                        {
                            beta[0].sprite.setPosition(477.5, 290);
                            beta[1].sprite.setPosition(282.5, 190);
                            beta[2].sprite.setPosition(282.5, 290);
                        }
                        if (!gamma[i].killed)
                        {
                            gamma[0].sprite.setPosition(575, 290);
                            gamma[1].sprite.setPosition(380, 190);
                            gamma[2].sprite.setPosition(380, 290);
                        }
                    }
                }

                //////////////////// Cross ////////////////////////

                else if (sub_level03)
                {
                    for (int i = 0; i < enemyships; i++)
                    {
                        if (!alpha[i].killed)
                        {
                            alpha[0].sprite.setPosition(195 - 30, 100 - 30);
                            alpha[1].sprite.setPosition(520 - 30, 200 - 30);
                            alpha[2].sprite.setPosition(260 - 30, 400 - 30);
                        }
                        if (!beta[i].killed)
                        {
                            beta[0].sprite.setPosition(585 - 40, 100 - 40);
                            beta[1].sprite.setPosition(260 - 40, 200 - 40);
                            beta[2].sprite.setPosition(585 - 40, 500 - 40);
                        }
                        if (!gamma[i].killed)
                        {
                            gamma[0].sprite.setPosition(390 - 40, 300 - 40);
                            gamma[1].sprite.setPosition(520 - 40, 400 - 40);
                            gamma[2].sprite.setPosition(195 - 40, 500 - 40);
                        }
                    }
                }

                //////////////////// Circle ////////////////////////
                else if (sub_level04)
                {
                    for (int i = 0; i < enemyships; i++)
                    {
                        if (!alpha[i].killed)
                        {
                            alpha[0].sprite.setPosition(390 - 30, 100 - 30);
                            alpha[1].sprite.setPosition(195 - 30, 300 - 30);
                            alpha[2].sprite.setPosition(260 - 30, 400 - 30);
                        }
                        if (!beta[i].killed)
                        {
                            beta[0].sprite.setPosition(250 - 30, 190 - 30);
                            beta[1].sprite.setPosition(510 - 30, 190 - 30);
                            beta[2].sprite.setPosition(380 - 30, 490 - 30);
                        }
                        if (!gamma[i].killed)
                        {
                            gamma[0].sprite.setPosition(575 - 30, 290 - 30);
                            gamma[1].sprite.setPosition(510 - 30, 390 - 30);
                            gamma[2].killed = true;
                        }
                    }
                }

                //////////////////// Diamond ////////////////////////
                else if (sub_level05)
                {
                    for (int i = 0; i < enemyships; i++)
                    {
                        if (!alpha[i].killed)
                        {
                            alpha[0].sprite.setPosition(260 - 50, 300 - 10);
                            alpha[1].sprite.setPosition(520 - 10, 300 - 10);
                            alpha[2].sprite.setPosition(468 - 10, 200 - 10);
                        }
                        if (!beta[i].killed)
                        {
                            beta[0].sprite.setPosition(312 - 40, 200 - 40);
                            beta[1].sprite.setPosition(468 - 40, 400 - 40);
                            beta[2].killed = true;
                        }
                        if (!gamma[i].killed)
                        {
                            gamma[0].sprite.setPosition(390 - 40, 100 - 40);
                            gamma[1].sprite.setPosition(312 - 40, 400 - 40);
                            gamma[2].sprite.setPosition(390 - 40, 500 - 40);
                        }
                    }
                }

                //////////////////// Heart ////////////////////////
                else if (sub_level06)
                {
                    for (int i = 0; i < enemyships; i++)
                    {
                        if (!alpha[i].killed)
                        {
                            alpha[0].sprite.setPosition(260, 100);
                            alpha[1].sprite.setPosition(585, 200);
                            alpha[2].sprite.setPosition(390, 400);
                        }
                        if (!beta[i].killed)
                        {
                            beta[0].sprite.setPosition(520 - 10, 100 - 10);
                            beta[1].sprite.setPosition(260 - 10, 300 - 10);
                            beta[2].killed = true;
                        }
                        if (!gamma[i].killed)
                        {
                            gamma[0].sprite.setPosition(195 - 10, 200 - 10);
                            gamma[1].sprite.setPosition(390 - 10, 200 - 10);
                            gamma[2].sprite.setPosition(520 - 10, 300 - 10);
                        }
                    }
                }

                //////////////////// Filled Square ////////////////////////
                else if (sub_level07)
                {
                    for (int i = 0; i < enemyships; i++)
                    {
                        if (!alpha[i].killed)
                        {
                            alpha[0].sprite.setPosition(195, 100);
                            alpha[1].sprite.setPosition(585, 200);
                            alpha[2].sprite.setPosition(390, 300);
                        }
                        if (!beta[i].killed)
                        {
                            beta[0].sprite.setPosition(390 - 10, 100 - 10);
                            beta[1].sprite.setPosition(195 - 10, 200 - 10);
                            beta[2].sprite.setPosition(585 - 10, 300 - 10);
                        }
                        if (!gamma[i].killed)
                        {
                            gamma[0].sprite.setPosition(585 - 10, 100 - 10);
                            gamma[1].sprite.setPosition(390 - 10, 200 - 10);
                            gamma[2].sprite.setPosition(195 - 10, 300 - 10);
                        }
                    }
                }
                // //////////////////// Big Plus  ////////////////////////
                else if (sub_level08)
                {
                    for (int i = 0; i < enemyships; i++)
                    {
                        if (!alpha[i].killed)
                        {
                            alpha[0].sprite.setPosition(390, 100);
                            alpha[1].sprite.setPosition(390, 400);
                            alpha[2].sprite.setPosition(250, 300);
                        }
                        if (!beta[i].killed)
                        {
                            beta[0].sprite.setPosition(390, 200 - 10);
                            beta[1].sprite.setPosition(390, 500 - 10);
                            beta[2].sprite.setPosition(550 - 10, 300 - 10);
                        }
                        if (!gamma[i].killed)
                        {
                            gamma[0].sprite.setPosition(390 - 10, 300 - 10);
                            gamma[1].sprite.setPosition(100 - 10, 300 - 10);
                            gamma[2].sprite.setPosition(680 - 10, 300 - 10);
                        }
                    }
                }

                //////////////////// |---|  ////////////////////////
                else if (sub_level09)
                {
                    for (int i = 0; i < enemyships; i++)
                    {
                        if (!alpha[i].killed)
                        {
                            alpha[0].sprite.setPosition(130, 200);
                            alpha[1].sprite.setPosition(520, 200);
                            alpha[2].sprite.setPosition(650, 100);
                        }
                        if (!beta[i].killed)
                        {
                            beta[0].sprite.setPosition(260 - 10, 200 - 10);
                            beta[1].sprite.setPosition(650 - 10, 200 - 10);
                            beta[2].sprite.setPosition(130 - 10, 300 - 10);
                        }
                        if (!gamma[i].killed)
                        {
                            gamma[0].sprite.setPosition(390 - 10, 200 - 10);
                            gamma[1].sprite.setPosition(130 - 10, 100 - 10);
                            gamma[2].sprite.setPosition(650 - 10, 300 - 10);
                        }
                    }
                }
                ///////////////  Bomb Dropping  ////////////////////

                float elapsed1 = bombTimeralpha.getElapsedTime().asSeconds();
                float elapsed2 = bombTimerbeta.getElapsedTime().asSeconds();
                float elapsed3 = bombTimergamma.getElapsedTime().asSeconds();
                if (elapsed1 >= 5.0f)
                {
                    bombTimeralpha.restart();
                    for (int j = 0; j < enemyships; j++)
                        alpha[j].set_bomb_position();
                }
                if (elapsed2 >= 3.0f)
                {
                    bombTimerbeta.restart();
                    for (int j = 0; j < enemyships; j++)
                        beta[j].set_bomb_position();
                }
                if (elapsed3 >= 2.0f)
                {
                    bombTimergamma.restart();
                    for (int j = 0; j < enemyships; j++)
                        gamma[j].set_bomb_position();
                }
                for (int j = 0; j < enemyships; j++)
                    alpha[j].move_bomb();
                for (int j = 0; j < enemyships; j++)
                    beta[j].move_bomb();
                for (int j = 0; j < enemyships; j++)
                    gamma[j].move_bomb();

                ////////////////////////////////////////////////////
                /////// Bullet Collsion Checker Loop ///////////////

                for (int i = 0; i < p->no_of_bullets; i++)
                {
                    for (int j = 0; j < enemyships; j++)
                    {

                        if (!alpha[j].killed)
                        {
                            if (p->b[i].bullet.getGlobalBounds().left <= alpha[j].sprite.getGlobalBounds().left + alpha[j].sprite.getGlobalBounds().width &&
                                p->b[i].bullet.getGlobalBounds().left + p->b[i].bullet.getGlobalBounds().width >= alpha[j].sprite.getGlobalBounds().left &&
                                p->b[i].bullet.getGlobalBounds().top <= alpha[j].sprite.getGlobalBounds().top + alpha[j].sprite.getGlobalBounds().height &&
                                p->b[i].bullet.getGlobalBounds().top + p->b[i].bullet.getGlobalBounds().height >= alpha[j].sprite.getGlobalBounds().top)
                            {
                                score += 10;
                                alpha[j].iskilled();
                                p->b[i].collision = true;
                                p->b[i].bullet.setPosition(-80, -80);
                                level01_counter++;
                            }
                            if (p->sprite.getGlobalBounds().left <= alpha[j].sprite.getGlobalBounds().left + alpha[j].sprite.getGlobalBounds().width &&
                                p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width >= alpha[j].sprite.getGlobalBounds().left &&
                                p->sprite.getGlobalBounds().top <= alpha[j].sprite.getGlobalBounds().top + alpha[j].sprite.getGlobalBounds().height &&
                                p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height >= alpha[j].sprite.getGlobalBounds().top)
                            {
                                p->iscollide();
                                p->sprite.setPosition(700, 700);
                                health -= 1;
                                sf::sleep(sf::seconds(1));
                            }
                        }
                        if (!beta[j].killed)
                        {
                            if (p->b[i].bullet.getGlobalBounds().left <= beta[j].sprite.getGlobalBounds().left + beta[j].sprite.getGlobalBounds().width &&
                                p->b[i].bullet.getGlobalBounds().left + p->b[i].bullet.getGlobalBounds().width >= beta[j].sprite.getGlobalBounds().left &&
                                p->b[i].bullet.getGlobalBounds().top <= beta[j].sprite.getGlobalBounds().top + beta[j].sprite.getGlobalBounds().height &&
                                p->b[i].bullet.getGlobalBounds().top + p->b[i].bullet.getGlobalBounds().height >= beta[j].sprite.getGlobalBounds().top)
                            {
                                score += 20;
                                beta[j].iskilled();
                                p->b[i].collision = true;
                                p->b[i].bullet.setPosition(-80, -80);
                                level01_counter++;
                            }
                            if (p->sprite.getGlobalBounds().left <= beta[j].sprite.getGlobalBounds().left + beta[j].sprite.getGlobalBounds().width &&
                                p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width >= beta[j].sprite.getGlobalBounds().left &&
                                p->sprite.getGlobalBounds().top <= beta[j].sprite.getGlobalBounds().top + beta[j].sprite.getGlobalBounds().height &&
                                p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height >= beta[j].sprite.getGlobalBounds().top)
                            {
                                p->iscollide();
                                p->sprite.setPosition(700, 700);
                                health -= 1;
                                sf::sleep(sf::seconds(1));
                            }
                        }
                        if (!gamma[j].killed)
                        {
                            if (p->b[i].bullet.getGlobalBounds().left <= gamma[j].sprite.getGlobalBounds().left + gamma[j].sprite.getGlobalBounds().width &&
                                p->b[i].bullet.getGlobalBounds().left + p->b[i].bullet.getGlobalBounds().width >= gamma[j].sprite.getGlobalBounds().left &&
                                p->b[i].bullet.getGlobalBounds().top <= gamma[j].sprite.getGlobalBounds().top + gamma[j].sprite.getGlobalBounds().height &&
                                p->b[i].bullet.getGlobalBounds().top + p->b[i].bullet.getGlobalBounds().height >= gamma[j].sprite.getGlobalBounds().top)
                            {
                                score += 30;
                                gamma[j].iskilled();
                                p->b[i].bullet.setPosition(-80, -80);
                                p->b[i].collision = true;
                                level01_counter++;
                            }
                            if (p->sprite.getGlobalBounds().left <= gamma[j].sprite.getGlobalBounds().left + gamma[j].sprite.getGlobalBounds().width &&
                                p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width >= gamma[j].sprite.getGlobalBounds().left &&
                                p->sprite.getGlobalBounds().top <= gamma[j].sprite.getGlobalBounds().top + gamma[j].sprite.getGlobalBounds().height &&
                                p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height >= gamma[j].sprite.getGlobalBounds().top)
                            {
                                p->iscollide();
                                p->sprite.setPosition(700, 700);
                                health -= 1;
                                sf::sleep(sf::seconds(1));
                            }
                        }
                        for (int z = 0; z < alpha[j].no_of_bombs; z++)
                        {
                            if (alpha[j].bomb[z].sprite.getGlobalBounds().left <= p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width &&
                                alpha[j].bomb[z].sprite.getGlobalBounds().left + alpha[j].bomb[z].sprite.getGlobalBounds().width >= p->sprite.getGlobalBounds().left &&
                                alpha[j].bomb[z].sprite.getGlobalBounds().top <= p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height &&
                                alpha[j].bomb[z].sprite.getGlobalBounds().top + alpha[j].bomb[z].sprite.getGlobalBounds().height >= p->sprite.getGlobalBounds().top)
                            {
                                alpha[j].bomb[z].collision = true;
                                p->iscollide();
                                p->sprite.setPosition(700, 700);
                                health -= 1;
                                sf::sleep(sf::seconds(1));
                            }
                            if (beta[j].bomb[z].sprite.getGlobalBounds().left <= p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width &&
                                beta[j].bomb[z].sprite.getGlobalBounds().left + beta[j].bomb[z].sprite.getGlobalBounds().width >= p->sprite.getGlobalBounds().left &&
                                beta[j].bomb[z].sprite.getGlobalBounds().top <= p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height &&
                                beta[j].bomb[z].sprite.getGlobalBounds().top + beta[j].bomb[z].sprite.getGlobalBounds().height >= p->sprite.getGlobalBounds().top)
                            {
                                beta[j].bomb[z].collision = true;
                                p->iscollide();
                                p->sprite.setPosition(700, 700);
                                health -= 1;
                                sf::sleep(sf::seconds(1));
                            }
                            if (gamma[j].bomb[z].sprite.getGlobalBounds().left <= p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width &&
                                gamma[j].bomb[z].sprite.getGlobalBounds().left + gamma[j].bomb[z].sprite.getGlobalBounds().width >= p->sprite.getGlobalBounds().left &&
                                gamma[j].bomb[z].sprite.getGlobalBounds().top <= p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height &&
                                gamma[j].bomb[z].sprite.getGlobalBounds().top + gamma[j].bomb[z].sprite.getGlobalBounds().height >= p->sprite.getGlobalBounds().top)
                            {
                                gamma[j].bomb[z].collision = true;
                                p->iscollide();
                                p->sprite.setPosition(700, 700);
                                health -= 1;
                                sf::sleep(sf::seconds(1));
                            }
                        }
                    }
                }
            }
            ////////////////////////////////////////////////////
            if (health != 0)
            {
                p->playerhascollided = false;
            }
            ///////////////////////////////////////////////
            ///////////////////////////////////////////////
            ///////////////////////////////////////////////

            ///////////////////////////////////////////////
            ///////////////     Monster   /////////////////
            ///////////////////////////////////////////////

            if (level01_counter == 79)
            {
                monster->position_set();
                monster->move_the_monster();
                cout << MonsterTimer.getElapsedTime().asSeconds() << endl;
                float elapsedmons = MonsterTimer.getElapsedTime().asSeconds();
                if ((elapsedmons > 8 && elapsedmons < 12) || (elapsedmons > 19 && elapsedmons < 26) || (elapsedmons > 32 && elapsedmons < 37))
                {
                    monster->display_laser_monster("");
                    if (monster->positionset)
                    {
                        if (monster->laser->sprite.getGlobalBounds().left <= p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width &&
                            monster->laser->sprite.getGlobalBounds().left + monster->laser->sprite.getGlobalBounds().width >= p->sprite.getGlobalBounds().left &&
                            monster->laser->sprite.getGlobalBounds().top <= p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height &&
                            monster->laser->sprite.getGlobalBounds().top + monster->laser->sprite.getGlobalBounds().height >= p->sprite.getGlobalBounds().top)
                        {

                            if (monster->right)
                            {
                                p->sprite.setPosition(monster->laser->sprite.getPosition().x - 100, 700);
                            }
                            else
                            {
                                p->sprite.setPosition(monster->laser->sprite.getPosition().x + 100, 700);
                            }
                            health -= 1;
                            sf::sleep(sf::seconds(1));
                        }
                    }
                    monster->laser_isActive = true;
                }
                else
                {
                    monster->laser_isActive = false;
                }
                if (elapsedmons <= 8)
                {
                    previous_health = health;
                }
                if (elapsedmons >= 40)
                {
                    level01_counter = 80;
                    killmonster = true;
                    if (previous_health == health)
                    {
                        score += 40;
                    }
                    monster->sprite.setPosition(-1233, -1233);
                }
            }
            ///////////////////////////////////////////////
            ///////////////////////////////////////////////
            ///////////////////////////////////////////////

            ///////////////////////////////////////////////
            ///////////////     Dragon    /////////////////
            ///////////////////////////////////////////////
            cout << level01_counter << endl;
            if (level01_counter == 81)
            {
                dragon->position_set();
                float elapsed78 = DragonTimer.getElapsedTime().asSeconds();
                cout << elapsed78 << endl;
                if (elapsed78 >= 5.0f && elapsed78 <= 30.0f)
                {
                    if (p->sprite.getPosition().x >= 0 && p->sprite.getPosition().x < 260)
                    {
                        dragon->display_laser_monster("l");
                    }
                    if (p->sprite.getPosition().x >= 260 && p->sprite.getPosition().x <= 520)
                    {
                        dragon->display_laser_monster("s");
                    }
                    if (p->sprite.getPosition().x >= 520 && p->sprite.getPosition().x <= 780)
                    {
                        dragon->display_laser_monster("r");
                    }
                }
                if (elapsed78 <= 8)
                {
                    previous_health = health;
                }
                // DragonTimer.restart();
                if (dragon->sprite.getGlobalBounds().left <= p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width &&
                    dragon->sprite.getGlobalBounds().left + dragon->sprite.getGlobalBounds().width >= p->sprite.getGlobalBounds().left &&
                    dragon->sprite.getGlobalBounds().top <= p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height &&
                    dragon->sprite.getGlobalBounds().top + dragon->sprite.getGlobalBounds().height >= p->sprite.getGlobalBounds().top)
                {
                    p->sprite.setPosition(0, 0);
                    health -= 1;
                }
                for (int i = 0; i < dragon->no_of_dragonlasers; i++)
                {
                    if (dragon->dragonlaser[i].sprite.getGlobalBounds().left <= p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width &&
                        dragon->dragonlaser[i].sprite.getGlobalBounds().left + dragon->dragonlaser[i].sprite.getGlobalBounds().width >= p->sprite.getGlobalBounds().left &&
                        dragon->dragonlaser[i].sprite.getGlobalBounds().top <= p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height &&
                        dragon->dragonlaser[i].sprite.getGlobalBounds().top + dragon->dragonlaser[i].sprite.getGlobalBounds().height >= p->sprite.getGlobalBounds().top)
                    {
                        p->sprite.setPosition(0, 0);
                        health -= 1;
                        sf::sleep(sf::seconds(1));
                    }
                }
                if (elapsed78 >= 35)
                {
                    level01_counter = 82;
                    dragon->killed = true;
                    if (previous_health == health)
                    {
                        score += 50;
                    }
                    dragon->sprite.setPosition(-1233, -1233);
                }
            }

            ///////////////////////////////////////////////
            ///////////////////////////////////////////////
            ///////////////////////////////////////////////

            ///////////////////////////////////////////////
            //////////////  Game Ended  ///////////////////
            ///////////////////////////////////////////////

            if ( level01_counter == 82 )
            {
                return ;
            }

            ///////////////////////////////////////////////
            ///////////////////////////////////////////////
            ///////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////     Function Calling ends here         ////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            window.clear(Color::Black); // clears the screen
            window.draw(background);    // setting background

            if (health > 0 && p->playerhascollided == false)
            {
                for (int i = 0; i < p->no_of_bullets; i++)
                    if (p->b[i].isfired && p->b[i].collision == false)
                        window.draw(p->b[i].bullet); // displaying bullets of the player
                window.draw(p->sprite);              // setting player on screen
            }
            for (int i = 0; i < enemyships; i++)
            {
                for (int j = 0; j < alpha[i].no_of_bombs; j++)
                {
                    if (!alpha[i].killed)
                    {
                        window.draw(alpha[i].sprite);
                    }
                    window.draw(alpha[i].bomb[j].sprite);

                    if (!beta[i].killed)
                    {
                        window.draw(beta[i].sprite);
                    }
                    window.draw(beta[i].bomb[j].sprite);

                    if (!gamma[i].killed)
                    {
                        window.draw(gamma[i].sprite);
                    }
                    window.draw(gamma[i].bomb[j].sprite);
                }
            }
            if (!killmonster)
            {
                window.draw(monster->sprite);
                if (monster->laser_isActive)
                    window.draw(monster->laser->sprite);
            }
            if (dragon->killed == false)
            {
                window.draw(dragon->sprite);
                if (dragon->positionset)
                {
                    for (int i = 0; i < dragon->no_of_dragonlasers; i++)
                        window.draw(dragon->dragonlaser[i].sprite);
                }
            }
            if (health <= 0)
                window.close();

            text.setString("Score: " + std::to_string(score));
            text1.setString("Health: " + std::to_string(health));
            text2.setString("Press P to Pause the game ");
            window.draw(text);
            window.draw(text1);
            window.draw(text2);
            window.display(); // Displying all the sprites
        }
        music.stop();
    }
};
