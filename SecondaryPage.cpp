#include "SecondaryPage.h"

SecondaryPage::SecondaryPage(int num) : m_blocks("second"), m_texts("second")
{
	// set font default

	fontFilmName.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
	fontTitle.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
	fontDesc.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");
	fontHeader.loadFromFile("fonts/Montserrat/Montserrat-Semibold.ttf");
	selectedItemIndex = num;
	if (!font.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf"))
	{
		// handle error
	}

	string filePath = "images/data/ke-kien-tao.png";
	string filePathIconPrev = "images/icon-prev.png";

	float xPos = 40.0f;
	float yPos = 85.0f;
	float xScale = 0.55;
	float yScale = 0.55;
	float xPosInfo = 200.0f;
	float wBgGray = 73;
	float wBgGrayLarger = 285;

	// icon previous
	m_blocks.AddBlockContainer(filePathIconPrev, xPos, 44, 0.22, 0.2);
	// set film'poster
	m_blocks.AddBlockContainer(filePath, xPos, 113, xScale, yScale);

	// Background img
	for (int i = 0; i < 18; i++)
	{
		i < 7 ? m_blocks.AddBlockContainer("images/bg-gray.png", xPos + wBgGray * i, 5.75 * yPos, 1, 1) : i >= 7 && i < 11 ? m_blocks.AddBlockContainer("images/bg-gray-larger.png", i < 9 ? xPos + wBgGrayLarger * (i - 7) : xPos + wBgGrayLarger * (i - 9), i < 9 ? 5.3 * yPos + 190 : 5.3 * yPos + 245, 1, 1)
																																								 : m_blocks.AddBlockContainer("images/bg-gray.png", xPos + wBgGray * (i - 11), 5.1 * yPos + 400, 1, 1);
	}
	for (int i = 0; i < 3; i++)
	{
		i < 2 ? m_blocks.AddBlockContainer("images/bg-red.png", xPos, 4.95 * yPos + i * 150, 0.3, 0.3) : m_blocks.AddBlockContainer("images/bg-red.png", xPos, 5 * yPos + i * 172.5, 0.3, 0.3);
	}

	m_texts.AddTextContainer("SLC2T", fontFilmName, 50, Color::Red, 212, 35);
	// set film's name
	m_texts.AddTextContainer("Ke Kien Tao", fontFilmName, 30, Color::Black, xPosInfo, 113);
	// set film's category
	m_texts.AddTextContainer("The loai:", fontTitle, 18, Color::Black, xPosInfo, 150);
	// set film's category content
	m_texts.AddTextContainer("Hanh dong, KHVT,...", fontDesc, 16, Color::Black, xPosInfo + 85, 150 + 2);
	// set film's time
	m_texts.AddTextContainer("Thoi luong:", fontTitle, 18, Color::Black, xPosInfo, 172);
	// set film's time content
	m_texts.AddTextContainer("120p", fontDesc, 16, Color::Black, xPosInfo + 110, 172 + 2);
	// set film's language
	m_texts.AddTextContainer("Ngon ngu:", fontTitle, 18, Color::Black, xPosInfo, 193);
	// set film's language content
	m_texts.AddTextContainer("Tieng Anh - Phu de Tieng Viet", fontDesc, 16, Color::Black, xPosInfo + 102, 193 + 2);
	// set film's Rate
	m_texts.AddTextContainer("Danh gia:", fontTitle, 18, Color::Black, xPosInfo, 215);
	// set film's Rate content
	m_texts.AddTextContainer("4,6/5", fontDesc, 16, Color::Black, xPosInfo + 95, 215 + 2);
	// set film's Date
	m_texts.AddTextContainer("Khoi Chieu:", fontTitle, 18, Color::Black, xPosInfo, 238);
	// set film's Date content
	m_texts.AddTextContainer("10/11/2023", fontDesc, 16, Color::Black, xPosInfo + 110, 238 + 2);

	//// set film's description heading

	m_texts.AddTextContainer("Mo ta phim", fontHeader, 26, Color::Black, xPos, 310);
	// set film's director
	m_texts.AddTextContainer("Dao dien:", fontTitle, 18, Color::Black, xPos, 340);
	// set film's director content
	m_texts.AddTextContainer("Huynh Thi Truc Lam", fontDesc, 16, Color::Black, xPos + 95, 340 + 2);
	// set film's actor
	m_texts.AddTextContainer("Dien vien long tieng:", fontTitle, 18, Color::Black, xPos, 365);
	// set film's actor desc
	m_texts.AddTextContainer("Brie Larson, Samuel L. Jackson, Zaw... ", fontDesc, 16, Color::Black, xPos + 198, 365 + 2);

	// set action'title

	m_texts.AddTextContainer("Chon ngay chieu", fontTitle, 18, Color::White, xPos + 22.5, 40 + 390);
	m_texts.AddTextContainer("Chon rap chieu", fontTitle, 18, Color::White, xPos + 32.5, 40 + 541);
	m_texts.AddTextContainer("Suat chieu", fontTitle, 18, Color::White, xPos + 52.5, 40 + 740);

	// set action'options
	m_texts.AddTextContainer("Cinestar Quoc Thanh", fontTitle, 16, Color::Black, xPos + 22.5, 110 + 541);
	m_texts.AddTextContainer("Cinestar Sinh vien", fontTitle, 16, Color::Black, xPos + 32.5, 164 + 542);
	m_texts.AddTextContainer("CGV Vincom Thu Duc", fontTitle, 16, Color::Black, xPos + 305, 110 + 541);
	m_texts.AddTextContainer("CGV GigaMall Thu Duc", fontTitle, 16, Color::Black, xPos + 300, 164 + 542);

	for (int i = 0; i < 7; i++)
	{
		m_texts.AddTextContainer("T7", fontTitle, 16, Color::Black, xPos + 22 + i * 73, 22 + yPos + 390);
		m_texts.AddTextContainer("31/10", fontDesc, 14, Color::Black, xPos + 18 + i * 73, 40 + yPos + 390);
	}
	for (int i = 0; i < 7; i++)
	{
		m_texts.AddTextContainer("10h", fontTitle, 16, Color::Black, xPos + 22.5 + i * 73, 5.1 * yPos + 418);
	}
}
SecondaryPage::~SecondaryPage()
{
}
void SecondaryPage::draw(RenderWindow &window)
{
	m_blocks.Render(window);
	m_texts.Render(window);
}
void SecondaryPage::Hover(int PosX, int PosY) {

	for (int i = 0; i < 7; i++)
	{
		if (PosX > 40 + 73 * i && PosX < 106 + 73 * i)
			m_blocks.AddBlockContainer("images/bg-gray-hover.png", 40 + 73 * i, 5.75 * 85, 1, 1);
	}
	for (int i = 0; i < 2; i++)
	{
		if (PosX > 40 + (260 + 73) * i && PosX < 330 + 73 * i)
			m_blocks.AddBlockContainer("images/bg-gray-larger-hover.png", 40 + 73 * i, 640, 1, 1);
	}

}
void SecondaryPage::Blur(int PosX, int PosY) {
	for (int i = 0; i < 7; i++)
	{
		m_blocks.AddBlockContainer("images/bg-gray.png", 40 + 73 * i, 5.75 * 85, 1, 1);
	}

}

void SecondaryPage::hoverDate(int Posx, int PosY) {

	int xMinGray = 40;
	int yMinGray = 470;//khong doi
	int xMaxGray = 524;
	int yMaxGray = 516;//khong doi

	if ((Posx > xMinGray && Posx < xMaxGray) )
	{
		if (PosY > yMinGray && PosY < yMaxGray)
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
		else if (PosY >  640 && PosY < 740)
		{
			for (int i = 0; i < 4; i++)
			{
				if (Posx < 260|| Posx > 330) {
					Hover(Posx, PosY);
				}
				else {
					Blur(Posx, PosY);
				}
			}
		}
	}
	else {
		Blur(Posx, PosY);

	}
}

