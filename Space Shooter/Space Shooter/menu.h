
#include "game.h"
#include <SFML/Audio.hpp>

class Menu
{
public:
    // add menu attributes here
    Menu()
    {
        // constructors body
    }

    void display_menu()
    {
        Game g;
        sf::RenderWindow window(sf::VideoMode(780, 780), title);
        sf::Sprite GameMenu;
        sf::Texture tex1;
        sf::Sprite InstructionMenu;
        sf::Texture tex2;
        sf::Sprite PlayAgain;
        sf::Texture tex3;
        bool gameend = false;

        if (!tex1.loadFromFile("img/startgamemenu.jpg"))
        {
            std::cerr << "Error loading startgamemenu.jpg" << std::endl;
        }
        GameMenu.setTexture(tex1);
        if (!tex2.loadFromFile("img/instructions.jpg"))
        {
            std::cerr << "Error loading instructions.jpg" << std::endl;
        }
        InstructionMenu.setTexture(tex2);
        if (!tex3.loadFromFile("img/PlayAgain.jpg"))
        {
            std::cerr << "Error loading PlayAgain.jpg" << std::endl;
        }
        PlayAgain.setTexture(tex3);
        while (window.isOpen())
        {
            sf::Event e;
            // While there are events to process
            while (window.pollEvent(e))
            {
                // Check if the window is closed or if the user presses the 'Num3' key to exit the game
                if (e.type == sf::Event::Closed || e.key.code == sf::Keyboard::Num3)
                {
                    window.close(); // Close the game window
                }
                // Check if the user presses the 'Num1' key to start the game
                else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Num1)
                {
                    g.start_game(); // Start the game
                    bool inPlayAgain = true;
                    // While the player wants to play again
                    while (inPlayAgain)
                    {
                        sf::Event e1;
                        // Check for events
                        while (window.pollEvent(e1))
                        {
                            // Check if the window is closed or if the user presses the 'Num3' key to exit the game
                            if (e1.type == sf::Event::Closed || e1.key.code == sf::Keyboard::Num3)
                            {
                                gameend = true;
                                break;
                            }
                        }
                        // Clear the screen, draw the play again menu, and display it
                        window.clear(sf::Color::Black);
                        window.draw(PlayAgain);
                        window.display();
                        if (gameend)
                            break;
                    }
                }
                // Check if the user presses the 'Num2' key to view the game instructions
                else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Num2)
                {
                    bool inInstructions = true;
                    // While the player is viewing the instructions
                    while (inInstructions)
                    {
                        sf::Event e1;
                        // Check for events
                        while (window.pollEvent(e1))
                        {
                            // Check if the window is closed or if the user presses the 'Num4' key to exit the instructions
                            if (e1.type == sf::Event::Closed || e1.key.code == sf::Keyboard::Num4)
                            {
                                inInstructions = false;
                            }
                        }
                        // Clear the screen, draw the instructions menu, and display it
                        window.clear(sf::Color::Black);
                        window.draw(InstructionMenu);
                        window.display();
                    }
                }
                // Check if the game has ended
                if (gameend)
                    break;
            }

            window.clear(sf::Color::Black);
            window.draw(GameMenu);
            window.display();
            if (gameend)
                break;
        }
    }
};
