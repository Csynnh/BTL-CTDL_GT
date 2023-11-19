


#include "SecondaryPage.h"


SecondaryPage::SecondaryPage(int num) : m_blocks("second"), m_texts("second")
{
	// set font default

	fontFilmName.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
	fontTitle.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
	fontDesc.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");
	fontHeader.loadFromFile("fonts/Montserrat/Montserrat-Semibold.ttf");
	selectedItemIndex = num;
	curentState = num;
	string filePath = "images/data/ke-kien-tao.png";
	string filePathIconPrev = "images/icon-prev.png";

	// icon previous
	m_blocks.AddBlockContainer(filePathIconPrev, xPos, 44, 0.22, 0.2);
	// set film'poster
	m_blocks.AddBlockContainer(filePath, xPos, 113, xScale, yScale);

	ChoseDate(m_blocks, m_texts);
	// ChoseCenima(m_blocks, m_texts);
	// ChoseTime(m_blocks, m_texts);

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

	// set action'options
}
SecondaryPage::~SecondaryPage()
{
}
void SecondaryPage::draw(RenderWindow& window)
{
	m_blocks.Render(window);
	m_texts.Render(window);
}
// void SecondaryPage::Hover(int PosX, int PosY)
// {
// 	for (int i = 0; i < 7; i++)
// 	{
// 		if (PosX > 40 + 73 * i && PosX < 106 + 73 * i && PosY < 640)
// 			m_blocks.AddBlockContainer("images/bg-gray-hover.png", 40 + 73 * i, 5.75 * 85, 1, 1);
// 	}
// 	for (int i = 0; i < 2; i++)
// 	{
// 		if (PosX > 40 + (260 + 73) * i && PosX < 330 + 73 * i)
// 			m_blocks.AddBlockContainer("images/bg-gray-larger-hover.png", 40 + (260 + 25) * i, 640, 1, 1);
// 	}
// }
// void SecondaryPage::Blur(int PosX, int PosY)
// {
// 	if (PosY < 640)
// 	{
// 		for (int i = 0; i < 7; i++)
// 		{
// 			m_blocks.AddBlockContainer("images/bg-gray.png", 40 + 73 * i, 5.75 * 85, 1, 1);
// 		}
// 	}
// }
// void SecondaryPage::hoverDate(int Posx, int PosY)
// {
// 	int xMinGray = 40;
// 	int yMinGray = 470; // khong doi
// 	int xMaxGray = 524;
// 	int yMaxGray = 516; // khong doi
// 	if ((Posx > xMinGray && Posx < xMaxGray))
// 	{
// 		if (PosY > yMinGray && PosY < yMaxGray)
// 		{
// 			for (int i = 0; i < 7; i++)
// 			{
// 				if (Posx < 106 + 73 * i || Posx > 113 + 73 * i)
// 				{
// 					Hover(Posx, PosY);
// 				}
// 				else
// 				{
// 					Blur(Posx, PosY);
// 				}
// 			}
// 		}
// 		else if (PosY > 640 && PosY < 740)
// 		{
// 			for (int i = 0; i < 4; i++)
// 			{
// 				if (Posx < 260 || Posx > 330)
// 				{
// 					Hover(Posx, PosY);
// 				}
// 				else
// 				{
// 					Blur(Posx, PosY);
// 				}
// 			}
// 		}
// 	}
// 	else
// 	{
// 		Blur(Posx, PosY);
// 	}
// }

void SecondaryPage::ChoseDate(BlockContainer& m_blocks, TextContainer& m_texts)
{
	string date[7][2] = { {"T2", "19/11"}, {"T3", "20/11"}, {"T4", "21/11"}, {"T5", "22/11"}, {"T6", "23/11"}, {"T7", "24/11"}, {"CN", "25/11"} };
	m_texts.AddTextContainer("Chon ngay chieu", fontTitle, 18, Color::White, xPos + 22.5, 40 + 390);
	for (int i = 0; i < 7; i++)
	{
		m_texts.AddTextContainer(date[i][0], fontTitle, 16, Color::Black, xPos + 22 + i * 73, 22 + yPos + 390);
		m_texts.AddTextContainer(date[i][1], fontDesc, 14, Color::Black, xPos + 18 + i * 73, 40 + yPos + 390);
	}
	m_blocks.AddBlockContainer("images/bg-red.png", xPos, 4.95 * yPos + 0 * 150, 0.3, 0.3);
	for (int i = 0; i < 7; i++)
	{
		m_blocks.AddBlockContainer("images/bg-gray-page2.png", xPos + wBgGray * i, 5.75 * yPos, 1, 1);
	}
}
void SecondaryPage::ChoseCenima(BlockContainer& m_blocks, TextContainer& m_texts)
{
	m_texts.AddTextContainer("Chon rap chieu", fontTitle, 18, Color::White, xPos + 32.5, 40 + 541);

	m_texts.AddTextContainer("Cinestar Quoc Thanh", fontTitle, 16, Color::Black, xPos + 22.5, 110 + 541);
	m_texts.AddTextContainer("Cinestar Sinh vien", fontTitle, 16, Color::Black, xPos + 32.5, 164 + 542);
	m_texts.AddTextContainer("CGV Vincom Thu Duc", fontTitle, 16, Color::Black, xPos + 305, 110 + 541);
	m_texts.AddTextContainer("CGV GigaMall Thu Duc", fontTitle, 16, Color::Black, xPos + 300, 164 + 542);

	m_blocks.AddBlockContainer("images/bg-red.png", xPos, 4.95 * yPos + 1 * 150, 0.3, 0.3);
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 190, 1, 1);
		else
			m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i - 2), 5.3 * yPos + 245, 1, 1);
	}
}
void SecondaryPage::ChoseTime(BlockContainer& m_blocks, TextContainer& m_texts)
{
	string time[7] = { "7h", "9h", "11h", "13h", "15h", "17h", "19h" };
	m_texts.AddTextContainer("Suat chieu", fontTitle, 18, Color::White, xPos + 52.5, 40 + 740);

	m_blocks.AddBlockContainer("images/bg-red.png", xPos, 5 * yPos + 2 * 172.5, 0.3, 0.3);
	for (int i = 0; i < 7; i++)
	{
		m_texts.AddTextContainer(time[i], fontTitle, 16, Color::Black, xPos + 22.5 + i * 73, 5.1 * yPos + 418);
		m_blocks.AddBlockContainer("images/bg-gray-page2.png", xPos + wBgGray * i, 5.1 * yPos + 400, 1, 1);
	}
}

void SecondaryPage::HandleChoseDate(int xMouse, int yMouse)
{
	int xMinGray = 40;
	int yMinGray = 5.75 * yPos; // khong doi
	int xMaxGray = 558;
	int yMaxGray = 5.75 * yPos + 51; // khong doi
	int space = 73;						// khong doi
	for (int i = 0; i < 7; i++)
	{
		// Hover(xMouse, yMouse);
		if (xMouse > xMinGray + space * i && xMouse < 106 + space * i && yMouse <= yMaxGray && yMouse >= yMinGray && DateWasSelected != i)
		{
			// clear
			if (DateWasSelected >= 0)
			{
				TimeWasSelected = -1;
				clearChoseTime();
				CenimaWasSelected = -1;
				clearChoseCenima();
				clearBgGray();
				for (int i = 0; i < 7; i++)
				{
					m_blocks.AddBlockContainer("images/bg-gray-page2.png", xPos + wBgGray * i, 5.75 * yPos, 1, 1);
				}
			}
			// handle
			DateWasSelected = i;
			cout << "Ngay " << DateWasSelected << endl;
			m_blocks.AddBlockContainer("images/bg-gray-hover.png", 40 + space * i, 5.75 * yPos, 1, 1);
			ChoseCenima(m_blocks, m_texts);
		}
	}
}
void SecondaryPage::HandleChoseCenima(int xMouse, int yMouse)
{
	int xMinGray = 40;
	int yMinGray = 5.3 * yPos + 190; // khong doi
	int xMaxGray = 558;
	int yMaxGray = 5.3 * yPos + 245 + 43; // khong doi
	int space = wBgGrayLarger;				  // khong doi
	for (int i = 0; i < 2; i++)
	{
		// Hover(xMouse, yMouse);
		if (xMouse > xMinGray + space * i && xMouse < 260 + space * i && yMouse <= yMaxGray && yMouse >= yMinGray && CenimaWasSelected != i)
		{
			// clear
			if (CenimaWasSelected >= 0)
			{
				TimeWasSelected = -1;
				clearChoseCenima();
				for (int i = 0; i < 4; i++)
				{
					if (i < 2)
						m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 190, 1, 1);
					else
						m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i - 2), 5.3 * yPos + 245, 1, 1);
				}
				clearChoseTime();
			}
			// handle
			CenimaWasSelected = i;
			cout << "Rap " << CenimaWasSelected << endl;

			m_blocks.AddBlockContainer("images/bg-gray-larger-hover.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 190, 1, 1);
			ChoseTime(m_blocks, m_texts);
		}
	}
}
void SecondaryPage::HandleChoseTime(int xMouse, int yMouse)
{
	int xMinGray = 40;
	int yMinGray = 5.1 * yPos + 400; // khong doi
	int xMaxGray = 558;
	int yMaxGray = 5.1 * yPos + 400 + 51; // khong doi
	int space = 73;							  // khong doi
	for (int i = 0; i < 7; i++)
	{
		// Hover(xMouse, yMouse);
		if (xMouse > xMinGray + space * i && xMouse < 106 + space * i && yMouse <= yMaxGray && yMouse >= yMinGray && TimeWasSelected != i)
		{
			// clear
			if (TimeWasSelected >= 0)
			{
				clearChoseTime();
				TimeWasSelected = -1;
				for (int i = 0; i < 7; i++)
				{
					m_blocks.AddBlockContainer("images/bg-gray-page2.png", xPos + wBgGray * i, 5.1 * yPos + 400, 1, 1);
				}
			}
			// handle
			TimeWasSelected = i;
			cout << "Gio " << TimeWasSelected << endl;
			m_blocks.AddBlockContainer("images/bg-gray-hover.png", 40 + space * i, 5.1 * yPos + 400, 1, 1);
			// handle goto ThirdPage
		}
	}
}

void SecondaryPage::clearBgGray()
{
	for (int i = 0; i < 7; i++)
	{
		m_blocks.AddBlockContainer("images/bg-white-small.png", xPos + wBgGray * i, 5.75 * yPos, 1, 1);
	}
}

void SecondaryPage::clearChoseCenima()
{
	if (CenimaWasSelected < 0)
	{
		m_blocks.AddBlockContainer("images/bg-white.png", xPos, 4.95 * yPos + 1 * 150, 1, 1);
		// if (TimeWasSelected > 0)
		/*for (int i = 0; i < 5; i++)
			m_texts.pop();*/
	}
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			m_blocks.AddBlockContainer("images/bg-white-larger.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 190, 1, 1);
		else
			m_blocks.AddBlockContainer("images/bg-white-larger.png", xPos + wBgGrayLarger * (i - 2), 5.3 * yPos + 245, 1, 1);
	}
}
void SecondaryPage::clearChoseTime()
{
	if (TimeWasSelected < 0)
	{
		m_blocks.AddBlockContainer("images/bg-white.png", xPos, 5 * yPos + 2 * 174, 1, 1);
		/*if (CenimaWasSelected >= 0)
			for (int i = 0; i < 8; i++)
				m_texts.pop();*/
	}
	for (int i = 0; i < 7; i++)
	{
		m_blocks.AddBlockContainer("images/bg-white-small.png", xPos + wBgGray * i, 5.1 * yPos + 400, 1, 1);
	}
}
void SecondaryPage::HandleMouseClick(int x, int y)
{

	if (x >= 40 && x <= 80 && y >= 40 && y <= 80) {
		cout << "Back button" << endl;
		curentState = 1;
	}

	this->HandleChoseDate(x, y);
	this->HandleChoseCenima(x, y);
	if (TimeWasSelected != -1) {
		curentState += 10;
	}
	this->HandleChoseTime(x, y);
}
void SecondaryPage::Click(int x, int y) {

}
int SecondaryPage::GetState()
{
	return selectedItemIndex;
}
int SecondaryPage::GetCurrentState()
{
	return curentState;
}
void SecondaryPage::SetCurrentState(int state)
{
	curentState = state;
}






// scr bên dưới của nhánh dataBase
/*

#include "SecondaryPage.h"

SecondaryPage::SecondaryPage(int num) : m_blocks("second"), m_texts("second")
{
	// set font default

	fontFilmName.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
	fontTitle.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
	fontDesc.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");
	fontHeader.loadFromFile("fonts/Montserrat/Montserrat-Semibold.ttf");
	selectedItemIndex = num;

	listMovie x;

	string filePath = x.a[0].filePath;
	string filePathIconPrev = "images/icon-prev.png";

	// icon previous
	m_blocks.AddBlockContainer(filePathIconPrev, xPos, 44, 0.22, 0.2);
	// set film'poster
	m_blocks.AddBlockContainer(filePath, xPos, 113, xScale, yScale);

	ChoseDate(m_blocks, m_texts);
	// ChoseCenima(m_blocks, m_texts);
	// ChoseTime(m_blocks, m_texts);


	m_texts.AddTextContainer("SLC2T", fontFilmName, 50, Color::Red, 212, 35);
	// set film's name
	m_texts.AddTextContainer(x.a[0].name, fontFilmName, 30, Color::Black, xPosInfo, 113);
	// set film's category
	m_texts.AddTextContainer("The loai:", fontTitle, 18, Color::Black, xPosInfo, 150);
	// set film's category content
	m_texts.AddTextContainer(x.a[0].type, fontDesc, 16, Color::Black, xPosInfo + 85, 150 + 2);
	// set film's time
	m_texts.AddTextContainer("Thoi luong:", fontTitle, 18, Color::Black, xPosInfo, 172);
	// set film's time content
	m_texts.AddTextContainer(x.a[0].time, fontDesc, 16, Color::Black, xPosInfo + 110, 172 + 2);
	// set film's language
	m_texts.AddTextContainer("Ngon ngu:", fontTitle, 18, Color::Black, xPosInfo, 193);
	// set film's language content
	m_texts.AddTextContainer(x.a[0].language, fontDesc, 16, Color::Black, xPosInfo + 102, 193 + 2);
	// set film's Rate
	m_texts.AddTextContainer("Danh gia:", fontTitle, 18, Color::Black, xPosInfo, 215);
	// set film's Rate content
	m_texts.AddTextContainer(x.a[0].rating, fontDesc, 16, Color::Black, xPosInfo + 95, 215 + 2);
	// set film's Date
	m_texts.AddTextContainer("Khoi Chieu:", fontTitle, 18, Color::Black, xPosInfo, 238);
	// set film's Date content
	m_texts.AddTextContainer("10/11/2023", fontDesc, 16, Color::Black, xPosInfo + 110, 238 + 2);
	//sửa ở đây nè
	//set film's Time content
	m_texts.AddTextContainer("Thoi luong:", fontTitle, 18, Color::Black, xPosInfo, 262);
	m_texts.AddTextContainer(x.a[0].time, fontDesc, 16, Color::Black, xPosInfo + 108, 264);
	//// set film's description heading

	m_texts.AddTextContainer("Mo ta phim", fontHeader, 26, Color::Black, xPos, 310);
	// set film's director
	m_texts.AddTextContainer("Dao dien:", fontTitle, 18, Color::Black, xPos, 340);
	// set film's director content
	m_texts.AddTextContainer(x.a[0].director, fontDesc, 16, Color::Black, xPos + 95, 340 + 2);
	// set film's actor
	m_texts.AddTextContainer("Dien vien long tieng:", fontTitle, 18, Color::Black, xPos, 365);
	// set film's actor desc
	m_texts.AddTextContainer(x.a[0].artist, fontDesc, 16, Color::Black, xPos + 198, 365 + 2);
	//sửa ở đây
	// set film' content
	m_texts.AddTextContainer("Noi dung phim:", fontTitle, 18, Color::Black, xPos, 392);
	m_texts.AddTextContainer(x.a[0].content, fontDesc, 16, Color::Black, xPos + 150, 392 + 2);
	// set action'title

	// set action'options
}
SecondaryPage::~SecondaryPage()
{
}
void SecondaryPage::draw(RenderWindow& window)
{
	m_blocks.Render(window);
	m_texts.Render(window);
}
// void SecondaryPage::Hover(int PosX, int PosY)
// {
// 	for (int i = 0; i < 7; i++)
// 	{
// 		if (PosX > 40 + 73 * i && PosX < 106 + 73 * i && PosY < 640)
// 			m_blocks.AddBlockContainer("images/bg-gray-hover.png", 40 + 73 * i, 5.75 * 85, 1, 1);
// 	}
// 	for (int i = 0; i < 2; i++)
// 	{
// 		if (PosX > 40 + (260 + 73) * i && PosX < 330 + 73 * i)
// 			m_blocks.AddBlockContainer("images/bg-gray-larger-hover.png", 40 + (260 + 25) * i, 640, 1, 1);
// 	}
// }
// void SecondaryPage::Blur(int PosX, int PosY)
// {
// 	if (PosY < 640)
// 	{
// 		for (int i = 0; i < 7; i++)
// 		{
// 			m_blocks.AddBlockContainer("images/bg-gray.png", 40 + 73 * i, 5.75 * 85, 1, 1);
// 		}
// 	}
// }
// void SecondaryPage::hoverDate(int Posx, int PosY)
// {
// 	int xMinGray = 40;
// 	int yMinGray = 470; // khong doi
// 	int xMaxGray = 524;
// 	int yMaxGray = 516; // khong doi
// 	if ((Posx > xMinGray && Posx < xMaxGray))
// 	{
// 		if (PosY > yMinGray && PosY < yMaxGray)
// 		{
// 			for (int i = 0; i < 7; i++)
// 			{
// 				if (Posx < 106 + 73 * i || Posx > 113 + 73 * i)
// 				{
// 					Hover(Posx, PosY);
// 				}
// 				else
// 				{
// 					Blur(Posx, PosY);
// 				}
// 			}
// 		}
// 		else if (PosY > 640 && PosY < 740)
// 		{
// 			for (int i = 0; i < 4; i++)
// 			{
// 				if (Posx < 260 || Posx > 330)
// 				{
// 					Hover(Posx, PosY);
// 				}
// 				else
// 				{
// 					Blur(Posx, PosY);
// 				}
// 			}
// 		}
// 	}
// 	else
// 	{
// 		Blur(Posx, PosY);
// 	}
// }




void SecondaryPage::ChoseDate(BlockContainer& m_blocks, TextContainer& m_texts)
{
	string date[7][2] = { {"T2", "19/11"}, {"T3", "20/11"}, {"T4", "21/11"}, {"T5", "22/11"}, {"T6", "23/11"}, {"T7", "24/11"}, {"CN", "25/11"} };
	m_texts.AddTextContainer("Chon ngay chieu", fontTitle, 18, Color::White, xPos + 22.5, 40 + 390);
	for (int i = 0; i < 7; i++)
	{
		m_texts.AddTextContainer(date[i][0], fontTitle, 16, Color::Black, xPos + 22 + i * 73, 22 + yPos + 390);
		m_texts.AddTextContainer(date[i][1], fontDesc, 14, Color::Black, xPos + 18 + i * 73, 40 + yPos + 390);
	}
	m_blocks.AddBlockContainer("images/bg-red.png", xPos, 4.95 * yPos + 0 * 150, 0.3, 0.3);
	for (int i = 0; i < 7; i++)
	{
		m_blocks.AddBlockContainer("images/bg-gray.png", xPos + wBgGray * i, 5.75 * yPos, 1, 1);
	}
}
void SecondaryPage::ChoseCenima(BlockContainer& m_blocks, TextContainer& m_texts)
{
	m_texts.AddTextContainer("Chon rap chieu", fontTitle, 18, Color::White, xPos + 32.5, 40 + 541);

	m_texts.AddTextContainer("Cinestar Quoc Thanh", fontTitle, 16, Color::Black, xPos + 22.5, 110 + 541);
	m_texts.AddTextContainer("Cinestar Sinh vien", fontTitle, 16, Color::Black, xPos + 32.5, 164 + 542);
	m_texts.AddTextContainer("CGV Vincom Thu Duc", fontTitle, 16, Color::Black, xPos + 305, 110 + 541);
	m_texts.AddTextContainer("CGV GigaMall Thu Duc", fontTitle, 16, Color::Black, xPos + 300, 164 + 542);

	m_blocks.AddBlockContainer("images/bg-red.png", xPos, 4.95 * yPos + 1 * 150, 0.3, 0.3);
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 190, 1, 1);
		else
			m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i - 2), 5.3 * yPos + 245, 1, 1);
	}
}
void SecondaryPage::ChoseTime(BlockContainer& m_blocks, TextContainer& m_texts)
{
	string time[7] = { "7h", "9h", "11h", "13h", "15h", "17h", "19h" };
	m_texts.AddTextContainer("Suat chieu", fontTitle, 18, Color::White, xPos + 52.5, 40 + 740);

	m_blocks.AddBlockContainer("images/bg-red.png", xPos, 5 * yPos + 2 * 172.5, 0.3, 0.3);
	for (int i = 0; i < 7; i++)
	{
		m_texts.AddTextContainer(time[i], fontTitle, 16, Color::Black, xPos + 22.5 + i * 73, 5.1 * yPos + 418);
		m_blocks.AddBlockContainer("images/bg-gray.png", xPos + wBgGray * i, 5.1 * yPos + 400, 1, 1);
	}
}

void SecondaryPage::HandleChoseDate(int xMouse, int yMouse)
{
	int xMinGray = 40;
	int yMinGray = 5.75 * yPos; // khong doi
	int xMaxGray = 558;
	int yMaxGray = 5.75 * yPos + 51; // khong doi
	int space = 73;						// khong doi
	for (int i = 0; i < 7; i++)
	{
		// Hover(xMouse, yMouse);
		if (xMouse > xMinGray + space * i && xMouse < 106 + space * i && yMouse <= yMaxGray && yMouse >= yMinGray && DateWasSelected != i)
		{
			// clear
			if (DateWasSelected >= 0)
			{
				TimeWasSelected = -1;
				clearChoseTime();
				CenimaWasSelected = -1;
				clearChoseCenima();
				clearBgGray();
				for (int i = 0; i < 7; i++)
				{
					m_blocks.AddBlockContainer("images/bg-gray.png", xPos + wBgGray * i, 5.75 * yPos, 1, 1);
				}
			}
			// handle
			DateWasSelected = i;
			cout << "Ngay " << DateWasSelected << endl;
			m_blocks.AddBlockContainer("images/bg-gray-hover.png", 40 + space * i, 5.75 * yPos, 1, 1);
			ChoseCenima(m_blocks, m_texts);
		}
	}
}
void SecondaryPage::HandleChoseCenima(int xMouse, int yMouse)
{
	int xMinGray = 40;
	int yMinGray = 5.3 * yPos + 190; // khong doi
	int xMaxGray = 558;
	int yMaxGray = 5.3 * yPos + 245 + 43; // khong doi
	int space = wBgGrayLarger;				  // khong doi
	for (int i = 0; i < 2; i++)
	{
		// Hover(xMouse, yMouse);
		if (xMouse > xMinGray + space * i && xMouse < 260 + space * i && yMouse <= yMaxGray && yMouse >= yMinGray && CenimaWasSelected != i)
		{
			// clear
			if (CenimaWasSelected >= 0)
			{
				TimeWasSelected = -1;
				clearChoseCenima();
				for (int i = 0; i < 4; i++)
				{
					if (i < 2)
						m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 190, 1, 1);
					else
						m_blocks.AddBlockContainer("images/bg-gray-larger.png", xPos + wBgGrayLarger * (i - 2), 5.3 * yPos + 245, 1, 1);
				}
				clearChoseTime();
			}
			// handle
			CenimaWasSelected = i;
			cout << "Rap " << CenimaWasSelected << endl;

			m_blocks.AddBlockContainer("images/bg-gray-larger-hover.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 190, 1, 1);
			ChoseTime(m_blocks, m_texts);
		}
	}
}
void SecondaryPage::HandleChoseTime(int xMouse, int yMouse)
{
	int xMinGray = 40;
	int yMinGray = 5.1 * yPos + 400; // khong doi
	int xMaxGray = 558;
	int yMaxGray = 5.1 * yPos + 400 + 51; // khong doi
	int space = 73;							  // khong doi
	for (int i = 0; i < 7; i++)
	{
		// Hover(xMouse, yMouse);
		if (xMouse > xMinGray + space * i && xMouse < 106 + space * i && yMouse <= yMaxGray && yMouse >= yMinGray && TimeWasSelected != i)
		{
			// clear
			if (TimeWasSelected >= 0)
			{
				clearChoseTime();
				TimeWasSelected = -1;
				for (int i = 0; i < 7; i++)
				{
					m_blocks.AddBlockContainer("images/bg-gray.png", xPos + wBgGray * i, 5.1 * yPos + 400, 1, 1);
				}
			}
			// handle
			TimeWasSelected = i;
			cout << "Gio " << TimeWasSelected << endl;
			m_blocks.AddBlockContainer("images/bg-gray-hover.png", 40 + space * i, 5.1 * yPos + 400, 1, 1);
			// handle goto ThirdPage
		}
	}
}

void SecondaryPage::clearBgGray()
{
	for (int i = 0; i < 7; i++)
	{
		m_blocks.AddBlockContainer("images/bg-white-small.png", xPos + wBgGray * i, 5.75 * yPos, 1, 1);
	}
}

void SecondaryPage::clearChoseCenima()
{
	if (CenimaWasSelected < 0)
	{
		m_blocks.AddBlockContainer("images/bg-white.png", xPos, 4.95 * yPos + 1 * 150, 1, 1);
		// if (TimeWasSelected > 0)
		for (int i = 0; i < 5; i++)
			m_texts.pop();
	}
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			m_blocks.AddBlockContainer("images/bg-white-larger.png", xPos + wBgGrayLarger * (i), 5.3 * yPos + 190, 1, 1);
		else
			m_blocks.AddBlockContainer("images/bg-white-larger.png", xPos + wBgGrayLarger * (i - 2), 5.3 * yPos + 245, 1, 1);
	}
}
void SecondaryPage::clearChoseTime()
{
	if (TimeWasSelected < 0)
	{
		m_blocks.AddBlockContainer("images/bg-white.png", xPos, 5 * yPos + 2 * 174, 1, 1);
		if (CenimaWasSelected >= 0)
			for (int i = 0; i < 8; i++)
				m_texts.pop();
	}
	for (int i = 0; i < 7; i++)
	{
		m_blocks.AddBlockContainer("images/bg-white-small.png", xPos + wBgGray * i, 5.1 * yPos + 400, 1, 1);
	}
}

*/