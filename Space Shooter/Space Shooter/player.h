#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include <string.h>
using namespace sf;
class Player
{
public:
	Texture tex;
	Sprite sprite;
	float speed = 0.7;
	int x, y;
	int no_of_bullets;
	bool playerhascollided = false;
	Bullet *b;
	sf::Music music1;
	Player(std::string png_path)
	{
		if (!music1.openFromFile("img/lasersound.ogg"))
		{
			std::cerr << "Failed to load music file" << std::endl;
		}
		music1.setVolume(30);
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		no_of_bullets = 5;
		b = new Bullet[no_of_bullets];
		x = 340;
		y = 700;
		sprite.setPosition(x, y);
		sprite.setScale(0.6, 0.6);
	}

	void iscollide()
	{
		playerhascollided = true;
	}

	void set_bullet()
	{
		for (int i = 0; i < no_of_bullets; i++)
		{
			if (!b[i].isfired)
			{
				b[i].bullet.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - 2, sprite.getPosition().y - sprite.getGlobalBounds().height / 2);
				music1.play();
				b[i].isfired = true;
				break;
			}
		}
	}

	void move_bullet()
	{
		for (int i = 0; i < no_of_bullets; i++)
		{
			if (b[i].isfired == true)
			{
				b[i].move_Bullet();
			}
		}
	}

	void move(std::string s)
	{
		float delta_x = 0, delta_y = 0;

		tex.loadFromFile("img/player_ship.png");
		sprite.setTexture(tex);
		sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y);

		if (s == "l")
		{
			delta_x = -1;
		}
		else if (s == "r")
		{
			delta_x = 1;
		}
		else if (s == "u")
		{
			delta_y = -1;
		}
		else if (s == "d")
		{
			delta_y = 1;
		}
		else if (s == "ul")
		{
			tex.loadFromFile("img/l.png");
			sprite.setTexture(tex);
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y);
			delta_x = -1;
			delta_y = -1;
		}
		else if (s == "ur")
		{
			tex.loadFromFile("img/r.png");
			sprite.setTexture(tex);
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y);
			delta_x = 1;
			delta_y = -1;
		}
		else if (s == "lb")
		{
			tex.loadFromFile("img/lb.png");
			sprite.setTexture(tex);
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y);
			delta_x = -1;
			delta_y = 1;
		}
		else if (s == "rb")
		{
			tex.loadFromFile("img/rb.png");
			sprite.setTexture(tex);
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y);
			delta_x = 1;
			delta_y = 1;
		}

		if (sprite.getPosition().y < 0)
		{
			sprite.setPosition(sprite.getPosition().x, 700);
		}
		if (sprite.getPosition().x < 0)
		{
			sprite.setPosition(700, sprite.getPosition().y);
		}
		if (sprite.getPosition().y > 780)
		{
			sprite.setPosition(sprite.getPosition().x, 0);
		}
		if (sprite.getPosition().x > 780)
		{
			sprite.setPosition(0, sprite.getPosition().y);
		}

		delta_x *= speed;
		delta_y *= speed;

		sprite.move(delta_x, delta_y);
	}
};
