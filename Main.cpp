#include <SFML/Graphics.hpp>
#include <iostream>
#include "SecondaryPage.h"

using namespace sf;
using namespace std;
const int SCRWIDTH = 585;
const int SCRHEIGHT = 900;
bool mouseWasReleased;

int main()
{
    RenderWindow window(VideoMode(SCRWIDTH, SCRHEIGHT), "SFML Image Loading");

    SecondaryPage second(1);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                cout << "Handling event closed" << endl;
                exit(EXIT_SUCCESS);
            }
            if (event.type == Event::KeyPressed)
            {
                cout << "A key was pressedd" << endl;
                if (event.key.code == Keyboard::W)
                {
                    cout << " \t specifically the w key" << endl;
                }
            }
            mouseWasReleased = false;

            if (event.type == Event::MouseButtonReleased)
            {
                mouseWasReleased = true;
                if (event.mouseButton.button == Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    second.HandleChoseDate(mousePos.x, mousePos.y);
                    second.HandleChoseCenima(mousePos.x, mousePos.y);
                    second.HandleChoseTime(mousePos.x, mousePos.y);
                }
            }

            if (event.type == sf::Event::MouseMoved && event.type != sf::Event::MouseLeft)
            {
                // int mouseX = event.mouseMove.x;
                // int mouseY = event.mouseMove.y;
                // std::cout << "Mouse X: " << mouseX << " Mouse Y: " << mouseY << std::endl;

                // second.hoverDate(mousePos.x, mousePos.y);
            }
        }

        window.clear(Color::White);
        second.draw(window);
        window.display();
    }

    return 0;
}