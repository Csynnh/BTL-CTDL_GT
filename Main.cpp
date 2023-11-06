#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "BlockContainer.h"
#include "TextContainer.h"
#include "SecondaryPage.h"

using namespace sf;
using namespace std;
const int SCRWIDTH = 585;
const int SCRHEIGHT = 900;

int main()
{
    RenderWindow window(VideoMode(SCRWIDTH, SCRHEIGHT), "SFML Image Loading");
    float xLogoPosition = 220.0f;
    float yLogoPosition = 20.0f;
    float xIconPrevPosition = 40.0f;
    float yIconPrevPosition = 35.0f;

    // Header
    // set logo app
    Font font;
    font.loadFromFile("fonts/Montserrat/Montserrat-ExtraBold.ttf");
    TextContainer LogoApp("Icon");
    LogoApp.AddTextContainer("SLC2T", font, 50, Color::Red, xLogoPosition, yLogoPosition);

    // set icon previous
    Texture icon;
    icon.loadFromFile("images/icon-prev.png");
    Sprite iconPrev(icon);
    iconPrev.setScale(0.2, 0.2);
    iconPrev.setPosition(xIconPrevPosition, yIconPrevPosition);

    // Content
    // set film'poster
    Texture film;
    film.loadFromFile("images/data/ke-kien-tao.png");
    Sprite filmPoster(film);
    filmPoster.setScale(0.55, 0.55);
    filmPoster.setPosition(xIconPrevPosition, 100.0f);

    // set font default
    Font fontFilmName;
    fontFilmName.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
    Font fontTitle;
    fontTitle.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
    Font fontDesc;
    fontDesc.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");
    Font fontHeader;
    fontHeader.loadFromFile("fonts/Montserrat/Montserrat-Semibold.ttf");

    TextContainer m_text("test Text");
    // set film's name
    m_text.AddTextContainer("Ke Kien Tao", fontFilmName, 30, Color::Black, xLogoPosition + 20, 100); // -15
    // set film's category
    m_text.AddTextContainer("The loai:", fontTitle, 18, Color::Black, xLogoPosition - 15, 135);
    // set film's category content
    m_text.AddTextContainer("Hanh dong, KHVT,...", fontDesc, 16, Color::Black, xLogoPosition - 15 + 85, 137);
    // set film's time
    m_text.AddTextContainer("Thoi luong:", fontTitle, 18, Color::Black, xLogoPosition - 15, 160);
    // set film's time content
    m_text.AddTextContainer("120p", fontDesc, 16, Color::Black, xLogoPosition - 15 + 110, 162);
    // set film's language
    m_text.AddTextContainer("Ngon ngu:", fontTitle, 18, Color::Black, xLogoPosition - 15, 185);
    // set film's language content
    m_text.AddTextContainer("Tieng Anh - Phu de Tieng Viet", fontDesc, 16, Color::Black, xLogoPosition - 15 + 105, 187);
    // set film's Rate
    m_text.AddTextContainer("Danh gia:", fontTitle, 18, Color::Black, xLogoPosition - 15, 210);
    // set film's Rate content
    m_text.AddTextContainer("4,6/5", fontDesc, 16, Color::Black, xLogoPosition - 15 + 100, 212);
    // set film's Date
    m_text.AddTextContainer("Khoi Chieu:", fontTitle, 18, Color::Black, xLogoPosition - 15, 235);
    // set film's Date content
    m_text.AddTextContainer("10/11/2023", fontDesc, 16, Color::Black, xLogoPosition - 15 + 110, 237);

    //// set film's description heading

    m_text.AddTextContainer("Mo ta phim", fontHeader, 26, Color::Black, xIconPrevPosition, 320);
    // set film's director
    m_text.AddTextContainer("Dao dien:", fontTitle, 18, Color::Black, xIconPrevPosition, 350);
    // set film's director content
    m_text.AddTextContainer("Huynh Thi Truc Lam", fontDesc, 16, Color::Black, xIconPrevPosition + 110, 352);
    // set film's actor
    m_text.AddTextContainer("Dien vien long tieng:", fontTitle, 18, Color::Black, xIconPrevPosition, 375);
    // set film's actor desc
    m_text.AddTextContainer("Brie Larson, Samuel L. Jackson, Zaw... ", fontDesc, 16, Color::Black, xIconPrevPosition + 200, 377);

    //// set action'title

    // m_text.AddTextContainer("Chon ngay chieu", fontTitle, 18, Color::White, xIconPrevPosition + 25, yIconPrevPosition + 390);
    // m_text.AddTextContainer("Chon rap chieu", fontTitle, 18, Color::White, xIconPrevPosition + 25, yIconPrevPosition + 520);

    // text component test

    BlockContainer m_backgroundGrayLarge("container");
    for (int i = 0; i < 7; i++)
    {
        m_backgroundGrayLarge.AddBlockContainer("images/bg-gray.png", 40 + 74 * i, 550, 1, 1);
    }

    m_backgroundGrayLarge.AddBlockContainer("images/bg-red.png", xIconPrevPosition, 480, 0.3, 0.3);

    SecondaryPage item(1);
    item.DrawContent();

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
                cout << "Mouse button pressed" << endl;
            }
        }

        window.clear(Color::White);
        LogoApp.Render(window);
         m_text.Render(window);
        item.Render(window);
        window.display();
    }

    return 0;
}