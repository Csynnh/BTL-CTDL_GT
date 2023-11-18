#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenManager.h"
#include "FirstPage.h"
#include "SecondaryPage.h"
#include "ThirdPage.h"
#include "FourthPage.h"

using namespace sf;
using namespace std;
const int SCRWIDTH = 585;
const int SCRHEIGHT = 900;
bool mouseWasReleased;


enum State {
    page1, page2, page3, page4
};

int main()
{

    State state = page1;
    vector<int> seats;

    RenderWindow window(VideoMode(SCRWIDTH, SCRHEIGHT), "SFML Image Loading");

    ScreenManager screenManager;
    FirstPage Page1(1);
    SecondaryPage Page2(1);
    ThirdPage Page3(seats);
    FourthPage Page4;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
                cout << "Handling event closed" << endl;
                exit(EXIT_SUCCESS);
            }

            if (event.type == Event::MouseButtonPressed)
            {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                screenManager.Click(mouseX, mouseY);

            }

            /*
            if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    //if (state == page1) {
                    //    screenManager.HandleMouseClick(mousePos.x, mousePos.y);
                    //}
                    //else if (state == page2) {
                    //    Page2.HandleChoseDate(mousePos.x, mousePos.y);
                    //    Page2.HandleChoseCenima(mousePos.x, mousePos.y);
                    //    Page2.HandleChoseTime(mousePos.x, mousePos.y);
                    //}
                    //else if (state == page3) {
                    //    if (Page3.isButtonPressed(window, mousePos, 1))
                    //    {
                    //        // chuyển sang trang 4
                    //        state = page4;
                    //    }
                    //    else if (Page3.isButtonPressed(window, mousePos, 0))
                    //    {
                    //        // quay lại trang 1
                    //        state = page2;
                    //        Page3.seatUpdate(seats, 0);
                    //        seats.clear();
                    //        Page3.seatColorUpdate(seats);
                    //    }

                    //    // kiểm tra tình trạng ghế
                    //    int temp = Page3.seatSelected(window, mousePos);
                    //    auto it = find(seats.begin(), seats.end(), temp);
                    //    if (it != seats.end()) {
                    //        // hủy chọn nếu ghế đã được chọn trước đó
                    //        Page3.seatUpdate(seats, 0);
                    //        seats.erase(remove(seats.begin(), seats.end(), temp), seats.end());
                    //        Page3.seatColorUpdate(seats);
                    //        Page3.seatUpdate(seats, 1);
                    //        cout << '~' << Page3.seatName(temp) << endl;
                    //    }
                    //    else {
                    //        // chọn ghế nếu ghế chưa được chọn
                    //        if (temp != -1) {
                    //            Page3.seatUpdate(seats, 0);
                    //            seats.push_back(temp);
                    //            Page3.seatColorUpdate(seats);
                    //            Page3.seatUpdate(seats, 1);
                    //            cout << Page3.seatName(temp) << endl;
                    //        }
                    //    }
                    //}
                    //else if (state == page4){
                    //    if (Page4.prevButtonIsPressed(window, mousePos)) {
                    //        // quay lại trang 3
                    //        state = page3;
                    //    }
                    //    else if (Page4.nextButtonIsPressed(window, mousePos)) {
                    //        // thoát khỏi chương trình
                    //        window.close();
                    //    }
                    //}
                    screenManager.HandleMouseClick(mousePos.x, mousePos.y);
                }
            }
            */

            
        }

        window.clear(Color::White);
        screenManager.draw(window);
        /*switch (state) {
        case page1:
            Page1.draw(window);
            break;
        case page2:
            Page2.draw(window);
            break;
        case page3:
            Page3.draw(window);
            break;
        case page4:
            Page4.draw(window);
            break;
        }*/
        window.display();
    }

    return 0;
}