#include "SecondaryPage.h"
void SecondaryPage::DrawContent()
{

    string filePath = "images/data/ke-kien-tao.png";
    string filePathIconPrev = "images/icon-prev.png";

    float xPos = 40.0f;
    float yPos = 85.0f;
    float xScale = 0.55;
    float yScale = 0.55;
    float wBgGray = 73;
    float wBgGrayLarger = 285;

    // set film'poster
    m_image.AddBlockContainer(filePath, xPos, yPos, xScale, yScale);
    // icon previous
    m_image.AddBlockContainer(filePathIconPrev, xPos, 20, 0.22, 0.2);

    // Background img
    for (int i = 0; i < 18; i++)
    {
        i < 7 ? m_image.AddBlockContainer("images/bg-gray.png", xPos + wBgGray * i, 5.5 * yPos, 1, 1) : i >= 7 && i < 11 ? m_image.AddBlockContainer("images/bg-gray-larger.png", i < 9 ? xPos + wBgGrayLarger * (i - 7) : xPos + wBgGrayLarger * (i - 9), i < 9 ? 5.3 * yPos + 150 : 5.3 * yPos + 205, 1, 1)
                                                                                                                         : m_image.AddBlockContainer("images/bg-gray.png", xPos + wBgGray * (i - 11), 5.1 * yPos + 345, 1, 1);
    }
    for (int i = 0; i < 3; i++)
    {
        i < 2 ? m_image.AddBlockContainer("images/bg-red.png", xPos, 4.75 * yPos + i * 135, 0.3, 0.3) : m_image.AddBlockContainer("images/bg-red.png", xPos, 4.4 * yPos + i * 172.5, 0.3, 0.3);
    }
}

void SecondaryPage::Render(RenderWindow &ref)
{
    // m_text.Render(ref);
    m_image.Render(ref);
}

void SecondaryPage::Hover(int PosX,int PosY){

     for (int i = 0; i < 7; i++)
    {
         if (PosX > 40 + 73*i && PosX < 106 + 73 *i)
             m_image.AddBlockContainer("images/bg-gray-hover.png", 40 + 73 * i, 5.5 * 85, 1, 1);
    }

     
}
void SecondaryPage::Blur(int PosX, int PosY) {
    for (int i = 0; i < 7; i++)
    {
        m_image.AddBlockContainer("images/bg-gray.png", 39 + 73 * i, 5.5 * 85, 1, 1);
    }

}

void SecondaryPage::hoverDate(int Posx, int PosY) {

    int xMinGray = 40;
    int yMinGray = 470;//khong doi
    int xMaxGray = 524;
    int yMaxGray = 516;//khong doi

    if ((Posx > xMinGray && Posx < xMaxGray) && (PosY > yMinGray && PosY < yMaxGray))
    {
        for (int i = 0; i < 7; i++)
        {
            if (Posx < 106 + 73 * i || Posx > 113 + 73 * i) {
                Hover(Posx, PosY);
            }
            else {
                Blur(Posx, PosY);

            }
        }
    }
    else {
        Blur(Posx, PosY);

    }
}