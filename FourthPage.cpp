#include "FourthPage.h"


FourthPage::FourthPage(int num) : m_blocks("fourth"), m_texts("fourth"), b_payment("b_payment"), t_payment("t_payment"),
b_offer("b_offer"), t_offer("t_offer")
{

    selectedItemIndex = num;
    curentState = num;

    bold.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
    semiBold.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
    regular.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");

    listMovie x;
    int filmIndex = (num - 20) % 11;
    string filePath = x.a[filmIndex].filePath;
    string filePathIconPrev = "images/icon-prev.png";

    m_blocks.AddBlockContainer(filePath, xPos, 113, xScale, yScale);
    m_blocks.AddBlockContainer(filePathIconPrev, xPos, 44, 0.22, 0.2);

    
    m_texts.AddTextContainer("SLC2T", bold, 50, Color::Red, 212, 35);
    // set film's name
    m_texts.AddTextContainer(x.a[filmIndex].name, bold, 30, Color::Black, 220 - 15, 100);
    // set film's category
    m_texts.AddTextContainer("The loai:", semiBold, 18, Color::Black, xLogoPosition - 15, 135);
    // set film's category content
    m_texts.AddTextContainer(x.a[filmIndex].type, regular, 16, Color::Black, xLogoPosition - 15 + 85, 137);
    // set film's time
    m_texts.AddTextContainer("Thoi luong:", semiBold, 18, Color::Black, xLogoPosition - 15, 160);
    // set film's time content
    m_texts.AddTextContainer(x.a[filmIndex].time, regular, 16, Color::Black, xLogoPosition - 15 + 110, 162);
    // set film's language
    m_texts.AddTextContainer("Ngon ngu:", semiBold, 18, Color::Black, xLogoPosition - 15, 185);
    // set film's language content
    m_texts.AddTextContainer(x.a[filmIndex].language, regular, 16, Color::Black, xLogoPosition - 15 + 105, 187);
    // set film's Rate
    m_texts.AddTextContainer("Danh gia:", semiBold, 18, Color::Black, xLogoPosition - 15, 210);
    // set film's Rate content
    m_texts.AddTextContainer(x.a[filmIndex].rating, regular, 16, Color::Black, xLogoPosition - 15 + 100, 212);
    // set film's Date
    m_texts.AddTextContainer("Khoi Chieu:", semiBold, 18, Color::Black, xLogoPosition - 15, 235);
    // set film's Date content
    m_texts.AddTextContainer("10/11/2023", regular, 16, Color::Black, xLogoPosition - 15 + 110, 237);
    
    // set bg-action
    Texture bgRed;
    bgRed.loadFromFile("images/bg-red.png");
    Sprite bgAction(bgRed);
    bgAction.setScale(0.3, 0.3);
    bgAction.setPosition(xIconPrevPosition, yIconPrevPosition + 380);
    // set action'title
    Text actionTitle("Thong tin ve", semiBold, 18);
    actionTitle.setFillColor(Color::Black);
    actionTitle.move(xIconPrevPosition + 25, yIconPrevPosition + 390);

    m_blocks.AddBlockContainer("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 280, 0.25, 0.3);
    m_texts.AddTextContainer("Thong tin ve", semiBold, 20, Color::White, xIconPrevPosition + 18, yIconPrevPosition + 290);

    m_texts.AddTextContainer("Vui long kiem tra thong tin truoc khi xac nhan!", regular, 16, Color::Black, xIconPrevPosition + 60, yIconPrevPosition + 360);


    //m_seats = ThirdPage::getSeat();

    m_texts.AddTextContainer("SO LUONG", semiBold, 18, Color::Black, xIconPrevPosition, yIconPrevPosition + 410);
    m_texts.AddTextContainer(to_string(m_seats.first), semiBold, 18, Color::Black, xIconPrevPosition + 400, yIconPrevPosition + 410);
    m_blocks.AddBlockContainer("images/line.png", xIconPrevPosition - 50, yIconPrevPosition + 425, 1, 1);
    m_texts.AddTextContainer("Tong", regular, 18, Color::Black, xIconPrevPosition, yIconPrevPosition + 440);
    m_texts.AddTextContainer(to_string(m_seats.second), semiBold, 18, Color::Black, xIconPrevPosition + 400, yIconPrevPosition + 440);

    m_blocks.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition - 20, yIconPrevPosition + 480, 1.3, 0.5);
    t_offer.AddTextContainer("MA KHUYEN MAI", semiBold, 18, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 490);
    m_blocks.AddBlockContainer("images/list-1.png", xIconPrevPosition + 487, yIconPrevPosition + 490, 0.3, 0.3);

    m_blocks.AddBlockContainer("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 540, 0.25, 0.3);
    m_texts.AddTextContainer("Thanh toan", semiBold, 20, Color::White, xIconPrevPosition + 25, yIconPrevPosition + 550);

    m_blocks.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition - 20, yIconPrevPosition + 600, 1.3, 0.5);
    t_payment.AddTextContainer("PHUONG THUC THANH TOAN", semiBold, 18, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 610);
    m_blocks.AddBlockContainer("images/list-1.png", xIconPrevPosition + 487, yIconPrevPosition + 610, 0.3, 0.3);

    m_texts.AddTextContainer("Tong cong", regular, 18, Color::Black, xIconPrevPosition, yIconPrevPosition + 670);
    m_texts.AddTextContainer("Giam gia", regular, 18, Color::Black, xIconPrevPosition, yIconPrevPosition + 700);
    m_blocks.AddBlockContainer("images/line.png", xIconPrevPosition - 50, yIconPrevPosition + 720, 1, 1);
    m_texts.AddTextContainer("Tong", semiBold, 20, Color::Black, xIconPrevPosition, yIconPrevPosition + 750);

    m_blocks.AddBlockContainer("images/bg-red.png", xIconPrevPosition + 30, yIconPrevPosition + 790, 0.65, 0.35);
    m_texts.AddTextContainer("Xac nhan thanh toan", semiBold, 22, Color::White, xIconPrevPosition + 130, yIconPrevPosition + 800);

}

FourthPage::~FourthPage() {}

void FourthPage::draw(RenderWindow& window)
{
    m_blocks.Render(window);
    m_texts.Render(window);
    b_payment.Render(window);
    t_payment.Render(window);
    b_offer.Render(window);
    t_offer.Render(window);
}

void FourthPage::HandleMouseClick(int x, int y)
{
    // sự kiện bấm vào nút prev thì quay về trang 3
    if (x >= 40 && x <= 80 && y >= 40 && y <= 80)
    {
        cout << "Back button" << endl;
        curentState -= 10;
    }


    // chương để tạm
    /*if (40 <= x && x <= 200 && 575 <= y && y <= 615) {
       curentState = 1;
    }*/

    //xác nhận thanh toán, quay về page 1
    if (80 <= x && x <= 500 && 830 <= y && y <= 870) {
        cout << "Da xac nhan dat ve!" << endl;
        curentState = 1;
    }

     // Ấn vào logo để quay về trang chủ
    if (212 <= x && x <= 360 && 37 <= y && y <= 73) {
        cout << "Click on logo" << endl;
        curentState = 1;
    }

    // Chọn mã khuyến mãi
    if (30 <= x && x <= 555 && 520 <= y && y <= 550) {
        if (!isOfferSelected) {
            this->selectOffer();
            isOfferSelected = true;
        }
        else {
            this->resetOffer();
            isOfferSelected = false;
            t_offer.AddTextContainer("MA KHUYEN MAI", semiBold, 18, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 490);
        }
    }
    
    
    // Chọn phương thức thanh toán
    if (30 <= x && x <= 555 && 640 <= y && y <= 670) {
        if (!isPaymentSelected) {
            this->selectPayment();
            isPaymentSelected = true;
        }
        else {
            this->resetPayment();
            isPaymentSelected = false;
            t_payment.AddTextContainer("PHUONG THUC THANH TOAN", semiBold, 18, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 610);
        }
    }

}

void FourthPage::selectOffer()
{
    string code[3] = { {"Combo cuoi tuan"}, {"Combo 1"}, {"Combo 2"} };
    b_offer.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition - 20, yIconPrevPosition + 480, 1.3, 1.6);
    b_offer.AddBlockContainer("images/list-2.png", xIconPrevPosition + 487, yIconPrevPosition + 490, 0.3, 0.3);
    for (int i = 0; i < 3; i++)
    {
        t_offer.AddTextContainer(code[i], regular, 16, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 520 + (i * 25));
    }
}

void FourthPage::resetOffer()
{
    t_offer.reset();
    b_offer.reset();
}



/* hàm hiển thị phương thức thanh toán đã chọn */

//void FourthPage::paymentIndex(int x, int y) {
//    int i = -1;
//    if (30 <= x && x <= 555 && 640 <= y && y <= 670)
//        i = 0;
//    if (30 <= x && x <= 555 && 692 <= y && y <= 712)
//        i = 1;
//    if (30 <= x && x <= 555 && 713 <= y && y <= 733)
//        i = 2;
//    this->resetPayment();
//    if (i != -1) {
//        string method[3] = { {"Tien mat"}, {"MoMo"}, {"The ngan hang"} };
//        t_payment.AddTextContainer(method[i], regular, 16, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 610);
//    }
//    else {
//        t_payment.AddTextContainer("PHUONG THUC THANH TOAN", semiBold, 18, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 610);
//    }
//}



/* hàm hiển thị mã km đã chọn */

//void FourthPage::offerIndex(int x, int y) {
//    int i = -1;
//    if (30 <= x && x <= 555 && 552 <= y && y <= 571)
//        i = 0;
//    if (30 <= x && x <= 555 && 572 <= y && y <= 593)
//        i = 1;
//    if (30 <= x && x <= 555 && 594 <= y && y <= 615)
//        i = 2;
//    isOfferSelected = true;
//    this->resetOffer();
//    if (i != -1) {
//        string code[3] = { {"Combo cuoi tuan"}, {"Combo 1"}, {"Combo 2"} };
//        t_Offer.AddTextContainer(code[i], regular, 16, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 610);
//    }
//    else {
//        t_offer.AddTextContainer("MA KHUYEN MAI", semiBold, 18, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 490);
//    }
//}




void FourthPage::selectPayment()
{
    string method[3] = { {"Tien mat"}, {"MoMo"}, {"The ngan hang"} };
    b_payment.AddBlockContainer("images/bg-red-3.png", xIconPrevPosition - 20, yIconPrevPosition + 600, 1.3, 1.6);
    b_payment.AddBlockContainer("images/list-2.png", xIconPrevPosition + 487, yIconPrevPosition + 610, 0.3, 0.3);
    for (int i = 0; i < 3; i++)
    {
        t_payment.AddTextContainer(method[i], regular, 16, Color::Black, xIconPrevPosition + 15, yIconPrevPosition + 520 + (i * 25) + 120 );
    }
}


void FourthPage::resetPayment()
{
    t_payment.reset();
    b_payment.reset();
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