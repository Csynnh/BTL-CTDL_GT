#include "FirstPage.h"
#include "SecondTab.h"
#include <fstream>
FirstPage::FirstPage(int num) : m_blocks("second"), m_texts("second")
{
	// set font default
	selectedItemIndex = num;
	curentState = num;
	fontFilmName.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
	//fontTitle.loadFromFile("fonts/VNI-Full/VNTIME.TTF");
	fontTitle.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");

	fontDesc.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");
	fontHeader.loadFromFile("fonts/Montserrat/Montserrat-Semibold.ttf");
	if (!font.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf"))
	{
		// handle error
	}
	//string filePath = "images/data/ke-kien-tao.png";
	string phim_1 = "images/data/cu-may-an-tien.png";
	string phim_2 = "images/data/biet-doi-danh-thue.png";
	string phim_3 = "images/data/nam-dem-kinh-hoang.png";
	string phim_4 = "images/data/marvel.png";
	string phim_5 = "images/data/ke-kien-tao.png";
	string phim_6 = "images/data/sieu-dang.png";
	string khungdo = "images/bg-red.png";
	string khungden = "images/bg-gray-larger.png";
	float xIconPrevPosition = 109.0f;
	float yIconPrevPosition = 148.0f;

	//m_blocks.AddBlockContainer(filePathIconPrev, xPos, 44, 0.22, 0.2);

	m_blocks.AddBlockContainer(phim_1, xIconPrevPosition, yIconPrevPosition, 0.633, 0.532);
	m_blocks.AddBlockContainer(phim_2, 320, yIconPrevPosition, 0.521, 0.466);
	m_blocks.AddBlockContainer(phim_3, xIconPrevPosition, 392, 0.49, 0.42);
	m_blocks.AddBlockContainer(phim_4, 320, 393, 0.408, 0.358);
	m_blocks.AddBlockContainer(phim_5, xIconPrevPosition, 647, 0.65, 0.587);
	m_blocks.AddBlockContainer(phim_6, 320, 647, 0.891, 0.838);
	m_blocks.AddBlockContainer(khungdo, 105, 92, 0.1769, 0.2469);
	m_blocks.AddBlockContainer(khungden, 236, 92, 0.5454, 0.9302);
	m_blocks.AddBlockContainer(khungden, 367, 92, 0.5454, 0.9302);
	//
	ifstream fin("input.txt");
	string phim;
	std::getline(fin, phim);
	fin.close();
	wstring wtext = L"Phim chiếu";
	sf::String text;
	text = sf::String::fromUtf8(begin(wtext), end(wtext));
	m_texts.AddTextContainer("Phim Chieu", fontTitle, 15, Color::White, 109, 95);
	m_texts.AddTextContainer("Rap Chieu", fontTitle, 15, Color::Black, 248, 95);
	m_texts.AddTextContainer("Thong Tin", fontTitle, 15, Color::Black, 380, 95);
	//
	m_texts.AddTextContainer("Cu May An Tien", fontTitle, 16, Color::Black, 133, 353);
	m_texts.AddTextContainer("Biet Doi Danh Thue 4", fontTitle, 16, Color::Black, 321, 353);
	m_texts.AddTextContainer("Nam Dem Kinh hoang", fontTitle, 16, Color::Black, 109, 601);
	m_texts.AddTextContainer("The Marvel", fontTitle, 16, Color::Black, 360, 599);
	m_texts.AddTextContainer("Ke Kien Tao", fontTitle, 16, Color::Black, 149, 855);
	m_texts.AddTextContainer("Sieu Dang", fontTitle, 16, Color::Black, 368, 853);
	m_texts.AddTextContainer("SLC2T", fontFilmName, 50, Color::Red, 212, 25);

}
void FirstPage::draw(RenderWindow& window)
{
	m_blocks.Render(window);
	m_texts.Render(window);
}

void FirstPage::HandleMouseClick(int x, int y)
{
	int xIconPrevPosition = 109;
	int yIconPrevPosition = 148;
	int width = 119;// chieu rong
	int height = 39; // chieu dai
	// Kiểm tra xem click có nằm trong vị trí cụ thể không
	if (x >= xIconPrevPosition && x <= xIconPrevPosition + width && y >= 95 && y <= 95 + height)
	{
		curentState = 1;
		cout << "Da click vao phim chieu" << endl;
	}
	else if (x >= xIconPrevPosition + 139 && x <= xIconPrevPosition + 139 + width && y >= 95 && y <= 95 + height)
	{
		curentState = 2;
		cout << " Da click vao o Rap chieu" << endl;
	}
	else if (x >= 380 && x <= 380 + width && y >= 95 && y <= 95 + height)
	{
		curentState = 3;
		cout << " Da click vao o Thong tin" << endl;
	}	
}
void FirstPage::Click(int x, int y) {
	int width = 173;// chieu rong
	int height = 202; // chieu dai
	int xIconPrevPosition = 109; // chieu rong X
	int yIconPrevPosition = 148; // chieu dai Y
	
	if (x >= xIconPrevPosition && x <= xIconPrevPosition + width && y >= yIconPrevPosition && y <= yIconPrevPosition + height)
	{
		
		curentState = 11;// Page phim 1
		cout << "Click chuot vao phim 1	" << endl;//
	}
	else if (x >= 320 && x <= 320 + width && y >= yIconPrevPosition && y <= yIconPrevPosition + height)
		// truyền curentState của Page phim 2
		cout << "Click vao phim 2" << endl;
	else if (x >= xIconPrevPosition && x <= xIconPrevPosition + width && y >= 392 && y <= 392 + height)
		cout << "Click vao phim 3" << endl;
	else if (x >= 320 && x <= 320 + width && y >= 393 && y <= 393 + height)
		cout << "Click chuot vao phim 4	" << endl;
	else if (x >= xIconPrevPosition && x <= xIconPrevPosition + width && y >= 647 && y <= 647 + height)
		cout << "Click chuot vao phim 5	" << endl;
	else if (x >= 320 && x <= 320 + width && y >= 647 && y <= 647 + height)
		cout << "Click chuot vao phim 6	" << endl;
}
// Viết thêm
int FirstPage::GetState()
{
	return selectedItemIndex;
}
int FirstPage::GetCurrentState()
{
	return curentState;
}
void FirstPage::SetCurrentState(int state)
{
	curentState = state;
}
// in man 2
