#include "ThirdPage.h"


ThirdPage::ThirdPage(int num) : m_blocks("third"), m_texts("third")
{

    exBold.loadFromFile("fonts/Montserrat/Montserrat-ExtraBold.ttf");
    bold.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
    semiBold.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
    regular.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");
    selectedItemIndex = num;
    curentState = num;

    /*listMovie x;
    int filmIndex = num % 11;
    string filePath = x.a[filmIndex].filePath;*/
    string filePathIconPrev = "images/icon-prev.png";
    string filePath = "images/data/ke-kien-tao.png";

    m_blocks.AddBlockContainer(filePathIconPrev, xPos, 44, 0.22, 0.2);
    m_blocks.AddBlockContainer(filePath, xPos, 113, xScale, yScale);

    //TextContainer textTest("test Text");
    m_texts.AddTextContainer("SLC2T", bold, 50, Color::Red, 212, 35);
    // set film's name
    m_texts.AddTextContainer("Ke Kien Tao", bold, 30, Color::Black, 220 - 15, 100);
    // set film's category
    m_texts.AddTextContainer("The loai:", semiBold, 18, Color::Black, xLogoPosition - 15, 135);
    // set film's category content
    m_texts.AddTextContainer("Hanh dong, KHVT,...", regular, 16, Color::Black, xLogoPosition - 15 + 85, 137);
    // set film's time
    m_texts.AddTextContainer("Thoi luong:", semiBold, 18, Color::Black, xLogoPosition - 15, 160);
    // set film's time content
    m_texts.AddTextContainer("120p", regular, 16, Color::Black, xLogoPosition - 15 + 110, 162);
    // set film's language
    m_texts.AddTextContainer("Ngon ngu:", semiBold, 18, Color::Black, xLogoPosition - 15, 185);
    // set film's language content
    m_texts.AddTextContainer("Tieng Anh - Phu de Tieng Viet", regular, 16, Color::Black, xLogoPosition - 15 + 105, 187);
    // set film's Rate
    m_texts.AddTextContainer("Danh gia:", semiBold, 18, Color::Black, xLogoPosition - 15, 210);
    // set film's Rate content
    m_texts.AddTextContainer("4,6/5", regular, 16, Color::Black, xLogoPosition - 15 + 100, 212);
    // set film's Date
    m_texts.AddTextContainer("Khoi Chieu:", semiBold, 18, Color::Black, xLogoPosition - 15, 235);
    // set film's Date content
    m_texts.AddTextContainer("10/11/2023", regular, 16, Color::Black, xLogoPosition - 15 + 110, 237);

    // set film's description heading

    m_texts.AddTextContainer("Mo ta phim", semiBold, 26, Color::Black, xIconPrevPosition, 320);
    // set film's director
    m_texts.AddTextContainer("Dao dien:", semiBold, 18, Color::Black, xIconPrevPosition, 350);
    // set film's director content
    m_texts.AddTextContainer("Huynh Thi Truc Lam", regular, 16, Color::Black, xIconPrevPosition + 110, 352);
    // set film's actor
    m_texts.AddTextContainer("Dien vien long tieng:", semiBold, 18, Color::Black, xIconPrevPosition, 375);
    // set film's actor desc
    m_texts.AddTextContainer("Brie Larson, Samuel L. Jackson, Zaw... ", regular, 16, Color::Black, xIconPrevPosition + 200, 377);

    m_texts.AddTextContainer("Chon ghe", semiBold, 25, Color::White, xIconPrevPosition + 35, 421);

    // set bg-action
    Texture bgRed;
    bgRed.loadFromFile("images/bg-red.png");
    Sprite bgAction(bgRed);
    bgAction.setScale(0.3, 0.3);
    bgAction.setPosition(xIconPrevPosition, yIconPrevPosition + 380);

    // set action'title
    Text actionTitle("Chon ngay chieu", semiBold, 18);
    actionTitle.setFillColor(Color(255, 255, 255));
    actionTitle.move(xIconPrevPosition + 25, yIconPrevPosition + 390);

    m_blocks.AddBlockContainer("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 380, 0.3, 0.3);
    m_blocks.AddBlockContainer("images/img-screen.png", xIconPrevPosition + 10, yIconPrevPosition + 450, 0.7, 0.7);

    for (int i = 0; i < 35; i++) {
        float xScale = 0.1;
        float xMargin = 50.0f;
        if (i > 29) {
            xScale = 0.2f;
            xMargin = 100.0f;
        }
        m_blocks.AddBlockContainer("images/bg-gray-page3.png", 40 + (i % 10) * xMargin, 35.0f + 520 + (i / 10) * 40, xScale, 0.1f);
    }

    m_blocks.AddBlockContainer("images/bg-gray-page3.png", xIconPrevPosition + 20, yIconPrevPosition + 690, 0.05, 0.05);
    m_texts.AddTextContainer("Ghe chua chon", regular, 15, Color::Black, xIconPrevPosition + 50, yIconPrevPosition + 690);

    m_blocks.AddBlockContainer("images/bg-red-2.png", xIconPrevPosition + 20, yIconPrevPosition + 710, 0.2, 0.16);
    m_texts.AddTextContainer("Ghe da chon", regular, 15, Color::Black, xIconPrevPosition + 50, yIconPrevPosition + 710);

    m_texts.AddTextContainer("A,B,C,D", semiBold, 15, Color::Black, xIconPrevPosition + 270, yIconPrevPosition + 710);
    m_texts.AddTextContainer("Hang ghe", regular, 15, Color::Black, xIconPrevPosition + 340, yIconPrevPosition + 710);

    m_blocks.AddBlockContainer("images/bg-gray-page3.png", xIconPrevPosition + 270, yIconPrevPosition + 690, 0.1, 0.05);
    m_texts.AddTextContainer("Ghe doi", regular, 15, Color::Black, xIconPrevPosition + 340, yIconPrevPosition + 690);


    for (int i = 0; i <= 7; i++) {
        if (i < 2)
            m_texts.AddTextContainer("A", semiBold, 18, Color::Black, 15 + i * 540, yIconPrevPosition + 525);
        else if (i < 4)
            m_texts.AddTextContainer("B", semiBold, 18, Color::Black, 15 + (i - 2) * 540, yIconPrevPosition + 565);
        else if (i < 6)
            m_texts.AddTextContainer("C", semiBold, 18, Color::Black, 15 + (i - 4) * 540, yIconPrevPosition + 605);
        else
            m_texts.AddTextContainer("D", semiBold, 18, Color::Black, 15 + (i - 6) * 540, yIconPrevPosition + 650);
    }


    vector<int> v[4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) v[i].push_back(j + 1);
    }
    for (int i = 1; i <= 5; i++) v[3].push_back(i);
    float yP = 560.0f;
    for (int i = 0; i < 4; i++) {
        float xP = xIconPrevPosition + 20.0f;
        for (int j = 0; j < v[i].size(); j++) {
            m_texts.AddTextContainer(to_string(v[i][j]), semiBold, 18, Color::Black, xP, yP);
            if (i == 3) xP += 100.0f;
            else xP += 49.0f;
        }
        yP += 40.0f;
    }


    m_blocks.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition - 22, yIconPrevPosition + 750, 1.3, 1.3);
    m_texts.AddTextContainer("Ghe chon:", semiBold, 22, Color::Black, xIconPrevPosition, yIconPrevPosition + 758);
    m_texts.AddTextContainer("Tam tinh:", semiBold, 22, Color::Black, xIconPrevPosition, yIconPrevPosition + 790);
}

ThirdPage::~ThirdPage() {}

void ThirdPage::draw(RenderWindow& window)
{
    m_blocks.Render(window);
    m_texts.Render(window);
}

//        yScale = 0.2;
//    }
//    BlockComponent button(filePath, xPos, yPos, xScale, yScale);
//    return (button.getGlobalBounds().contains(window.mapPixelToCoords(mousePos)));
//}


int ThirdPage::seatSelected(int x, int y) {

    const int rows = 4; // Tổng số hàng là 4 (3 hàng trên và 1 hàng dưới cùng)
    const int cols = 10;
    const int extraCols = 5; // Số cột ở hàng dưới cùng
    const int height = 35;
    const int width_1 = 42; // Chiều rộng của ghế ở 3 hàng trên
    const int width_2 = 85; // Chiều rộng của ghế ở hàng dưới cùng
    const int spacing_1 = 8;
    const int spacing_2 = 15; // Khoảng cách giữa các vật thể ở hàng dưới cùng
    const int startX = 40;
    const int startY = 550;

    for (int i = 0; i < 35; ++i) {

        int row = i / cols;
        int colUpper = i % cols;
        int colLower = i % extraCols;
        int xLeft;
        int yTop;

        if (row == rows - 1 && colLower < extraCols) {
            xLeft = startX + colLower * (width_2 + spacing_2);
            yTop = startY + row * (height + spacing_1);

            if (xLeft <= x && x <= xLeft + width_2 && yTop <= y && y <= yTop + height) {
                return i;
            }
        }
        else {
            xLeft = startX + colUpper * (width_1 + spacing_1);
            yTop = startY + row * (height + spacing_1);

            if (xLeft <= x && x <= xLeft + width_1 && yTop <= y && y <= yTop + height) {
                return i;
            }
        }
    }

    return -1;
}

void ThirdPage::seatColorUpdate(vector<int> seatIndex) {
    float xMargin = 50.0f;
    float grayxScale = 0.1f;
    float redxScale = 0.7f;
    for (int i = 0; i < 35; i++) {
        if (i > 28) {
            xMargin = 100.0f;
            grayxScale = 0.2f;
            redxScale = 1.3f;
        }
        m_blocks.AddBlockContainer("images/bg-gray-page3.png", 40 + (i % 10) * xMargin, 35.0f + 520 + (i / 10) * 40, grayxScale, 0.1f);
        for (int temp : seatIndex) {
            if (i == temp) {
                m_blocks.AddBlockContainer("images/bg-gray-hover.png", 40 + (i % 10) * xMargin, 35.0f + 520 + (i / 10) * 40, redxScale, 0.65f);
            }
        }
    }
}

string ThirdPage::seatName(int seatIndex) {
    string text, num;
    switch (seatIndex / 10) {
    case 0:
        text = "A";
        break;
    case 1:
        text = "B";
        break;
    case 2:
        text = "C";
        break;
    default:
        text = "D";
        break;
    }
    if ((seatIndex % 10) != 9) num = "0" + to_string((seatIndex + 1) % 10);
    else num = "10";
    return text + num;
}

void ThirdPage::seatUpdate(vector<int> seats, bool key) {
    float xPos = 500.0f;
    float xMarginRight = 50.0f;
    int price = 0;
    for (int temp : seats) {
        if (key) {
            m_texts.AddTextContainer(seatName(temp), regular, 16, Color::Black, xPos, 793.0f);
        }
        else {
            m_texts.AddTextContainer(seatName(temp), exBold, 16, Color::White, xPos, 793.0f);
        }
        xPos -= xMarginRight;
        price += (temp > 28 ? 90 : 45);
    }
    if (key) {
        m_texts.AddTextContainer(to_string(price * 1000), regular, 16, Color::Black, 480.0f, 825.0f);
    }
    else {
        m_texts.AddTextContainer(to_string(price * 1000), exBold, 16, Color::White, 480.0f, 825.0f);
    }
}

void ThirdPage::HandleMouseClick(int x, int y)
{
   if (x >= 40 && x <= 80 && y >= 40 && y <= 80)
    {
        cout << " Da click back button" << endl;
        curentState -= 10;
        seats.clear();
        this->seatColorUpdate(seats);
        this->seatUpdate(seats, 0);
    }

   if (212 <= x && x <= 360 && 37 <= y && y <= 73) {
       cout << "Click on logo" << endl;
       curentState = 1;
   }

   if (x >= 40 && x <= 240 && y >= 415 && y <= 455) {
       curentState += 10;
   }
   
   int temp = this->seatSelected(x, y);
   
   auto it = find(seats.begin(), seats.end(), temp);
   if (it != seats.end()) {
       // hủy chọn nếu ghế đã được chọn trước đó
       this->seatUpdate(seats, 0);
       seats.erase(remove(seats.begin(), seats.end(), temp), seats.end());
       this->seatColorUpdate(seats);
       this->seatUpdate(seats, 1);
       cout << '~' << this->seatName(temp) << endl;
   }
   else {
       // chọn ghế nếu ghế chưa được chọn
       if (temp != -1) {
           this->seatUpdate(seats, 0);
           seats.push_back(temp);
           this->seatColorUpdate(seats);
           this->seatUpdate(seats, 1);
           cout << this->seatName(temp) << endl;
       }
   }
}
void ThirdPage::Click(int x, int y) {

}
int ThirdPage::GetState()
{
    return selectedItemIndex;
}
int ThirdPage::GetCurrentState()
{
    return curentState;
}
void ThirdPage::SetCurrentState(int state)
{
    curentState = state;
}