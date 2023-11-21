#include "FourthPage.h"


FourthPage::FourthPage(int num) : m_blocks("fourth"), m_texts("fourth")
{
    selectedItemIndex = num;
    curentState = num;
    string filePathIconPrev = "images/icon-prev.png";
    string filePath = "images/data/ke-kien-tao.png";

    float xPos = 40.0f;
    float yPos = 85.0f;
    float xScale = 0.55;
    float yScale = 0.55;

    float xLogoPosition = 220;
    float yLogoPosition = 20.0f;
    float xIconPrevPosition = 40.0f;
    float yIconPrevPosition = 35.0f;

    fontFilmName.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
    fontTitle.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
    fontDesc.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");
    fontHeader.loadFromFile("fonts/Montserrat/Montserrat-Semibold.ttf");

    //selectedItemIndex = num;

    m_blocks.AddBlockContainer(filePathIconPrev, xPos, 44, 0.22, 0.2);
    m_blocks.AddBlockContainer(filePath, xPos, 113, xScale, yScale);


    //TextContainer textTest("test Text");
    m_texts.AddTextContainer("SLC2T", fontFilmName, 50, Color::Red, 212, 35);
    // set film's name
    m_texts.AddTextContainer("Ke Kien Tao", fontFilmName, 30, Color::Black, 220 - 15, 100);
    // set film's category
    m_texts.AddTextContainer("The loai:", fontTitle, 18, Color::Black, xLogoPosition - 15, 135);
    // set film's category content
    m_texts.AddTextContainer("Hanh dong, KHVT,...", fontDesc, 16, Color::Black, xLogoPosition - 15 + 85, 137);
    // set film's time
    m_texts.AddTextContainer("Thoi luong:", fontTitle, 18, Color::Black, xLogoPosition - 15, 160);
    // set film's time content
    m_texts.AddTextContainer("120p", fontDesc, 16, Color::Black, xLogoPosition - 15 + 110, 162);
    // set film's language
    m_texts.AddTextContainer("Ngon ngu:", fontTitle, 18, Color::Black, xLogoPosition - 15, 185);
    // set film's language content
    m_texts.AddTextContainer("Tieng Anh - Phu de Tieng Viet", fontDesc, 16, Color::Black, xLogoPosition - 15 + 105, 187);
    // set film's Rate
    m_texts.AddTextContainer("Danh gia:", fontTitle, 18, Color::Black, xLogoPosition - 15, 210);
    // set film's Rate content
    m_texts.AddTextContainer("4,6/5", fontDesc, 16, Color::Black, xLogoPosition - 15 + 100, 212);
    // set film's Date
    m_texts.AddTextContainer("Khoi Chieu:", fontTitle, 18, Color::Black, xLogoPosition - 15, 235);
    // set film's Date content
    m_texts.AddTextContainer("10/11/2023", fontDesc, 16, Color::Black, xLogoPosition - 15 + 110, 237);

    // set bg-action
    Texture bgRed;
    bgRed.loadFromFile("images/bg-red.png");
    Sprite bgAction(bgRed);
    bgAction.setScale(0.3, 0.3);
    bgAction.setPosition(xIconPrevPosition, yIconPrevPosition + 380);
    // set action'title
    Text actionTitle("Thong tin ve", fontTitle, 18);
    actionTitle.setFillColor(Color::Black);
    actionTitle.move(xIconPrevPosition + 25, yIconPrevPosition + 390);

    //BlockContainer backGround("container");

    m_blocks.AddBlockContainer("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 280, 0.25, 0.3);
    m_texts.AddTextContainer("Thong tin ve", fontTitle, 20, Color::White, xIconPrevPosition + 18, yIconPrevPosition + 290);

    m_blocks.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition + 10, yIconPrevPosition + 330, 0.3, 0.8);
    m_blocks.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition + 150, yIconPrevPosition + 330, 0.3, 0.8);
    m_blocks.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition + 290, yIconPrevPosition + 330, 0.3, 0.8);

    m_texts.AddTextContainer("SO LUONG", fontTitle, 18, Color::Black, xIconPrevPosition, yIconPrevPosition + 410);
    m_blocks.AddBlockContainer("images/line.png", xIconPrevPosition - 50, yIconPrevPosition + 425, 1, 1);
    m_texts.AddTextContainer("Tong", fontDesc, 18, Color::Black, xIconPrevPosition, yIconPrevPosition + 440);

    m_blocks.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition - 20, yIconPrevPosition + 480, 1.3, 0.5);
    m_texts.AddTextContainer("MA KHUYEN MAI", fontTitle, 18, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 490);
    m_blocks.AddBlockContainer("images/list.png", xIconPrevPosition + 487, yIconPrevPosition + 490, 0.3, 0.3);

    m_blocks.AddBlockContainer("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 540, 0.25, 0.3);
    m_texts.AddTextContainer("Thanh toan", fontTitle, 20, Color::White, xIconPrevPosition + 25, yIconPrevPosition + 550);

    m_blocks.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition - 20, yIconPrevPosition + 600, 1.3, 0.5);
    m_texts.AddTextContainer("PHUONG THUC THANH TOAN", fontTitle, 18, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 610);
    m_blocks.AddBlockContainer("images/list.png", xIconPrevPosition + 487, yIconPrevPosition + 610, 0.3, 0.3);

    m_texts.AddTextContainer("Tong cong", fontDesc, 18, Color::Black, xIconPrevPosition, yIconPrevPosition + 670);
    m_texts.AddTextContainer("Giam gia", fontDesc, 18, Color::Black, xIconPrevPosition, yIconPrevPosition + 700);
    m_blocks.AddBlockContainer("images/line.png", xIconPrevPosition - 50, yIconPrevPosition + 720, 1, 1);
    m_texts.AddTextContainer("Tong", fontTitle, 20, Color::Black, xIconPrevPosition, yIconPrevPosition + 750);

    m_blocks.AddBlockContainer("images/bg-red.png", xIconPrevPosition + 30, yIconPrevPosition + 790, 0.65, 0.35);
    m_texts.AddTextContainer("Xac nhan thanh toan", fontTitle, 22, Color::White, xIconPrevPosition + 130, yIconPrevPosition + 800);

}

FourthPage::~FourthPage() {}

void FourthPage::draw(RenderWindow& window)
{
    m_blocks.Render(window);
    m_texts.Render(window);
}

bool FourthPage::prevButtonIsPressed(RenderWindow& window, Vector2i mousePos) {
    BlockComponent prevIcon("images/data/ke-kien-tao.png", 40.0f, 44.0f, 0.22, 0.2);
    return (prevIcon.getGlobalBounds().contains(window.mapPixelToCoords(mousePos)));
}


bool FourthPage::nextButtonIsPressed(RenderWindow& window, Vector2i mousePos) {
    BlockComponent nextIcon("images/bg-red.png", 70.0f, 825.0f, 0.65, 0.35);
    return (nextIcon.getGlobalBounds().contains(window.mapPixelToCoords(mousePos)));
}




void FourthPage::HandleMouseClick(int x, int y)
{
    if (x >= 40 && x <= 80 && y >= 40 && y <= 80)
    {
        cout << " Da click back button" << endl;
        curentState -= 10;
    }

    /*if (77 <= x && x <= 500 && 813 <= y && y <= 854) {
        cout << "Da xac nhan dat ve!" << endl;
        curentState = 1;
    }*/

    if (40 <= x && x <= 200 && 575 <= y && y <= 615) {
        curentState = 1;
    }
}
void FourthPage::Click(int x, int y) {

}
int FourthPage::GetState()
{
    return selectedItemIndex;
}
int FourthPage::GetCurrentState()
{
    return curentState;
}
void FourthPage::SetCurrentState(int state)
{
    curentState = state;
}