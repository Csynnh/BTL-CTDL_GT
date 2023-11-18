#include <SFML/Graphics.hpp>
#include <iostream>

#include "FirstPage.h"
#include "SecondTab.h"
#include "ThirdTab.h"
#include "ScreenManager.h"

using namespace sf;
using namespace std;
const int SCRWIDTH = 585;
const int SCRHEIGHT = 900;

int main()
{
    RenderWindow window(VideoMode(SCRWIDTH, SCRHEIGHT), "SFML Image Loading");

    ScreenManager screenManager;
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
            if (event.type == Event::MouseButtonPressed)
            {
                cout << "Da kik chuot thanh cong" << endl;
            }
            // click 3 o tuy chon: dung cho ca 3 ham
            if (event.type == Event::MouseButtonPressed)
            {
                
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                screenManager.HandleMouseClick(mouseX, mouseY);

            }
            // click phim: dùng cho firstPage
            if (event.type == Event::MouseButtonPressed)
            {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                screenManager.Click(mouseX, mouseY);
               
            }
            
        }

        window.clear(Color::White);
        screenManager.draw(window);
        window.display();
    }

    return 0;
}
