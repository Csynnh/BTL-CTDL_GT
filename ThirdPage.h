#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"

class ThirdPage
{
private:
	int singleSeat;
	int coupleSeat;
	int selectedItemIndex;
	Font font;
	Font exBold;
	Font fontFilmName;
	Font fontTitle;
	Font fontDesc;
	Font fontHeader;
	Text menu[50];
	vector<int> seatIndex;
	BlockContainer m_blocks;
	TextContainer m_texts;

public:
	ThirdPage(vector<int> seats);
	~ThirdPage();
	void draw(RenderWindow& window);
	bool isButtonPressed(RenderWindow& window, Vector2i mousePos, bool key);
	int seatSelected(RenderWindow& window, Vector2i mousePos);
	void seatColorUpdate(vector<int> seatIndex);
	string seatName(int seatIndex);
	void seatUpdate(vector<int> seats, bool key);
};