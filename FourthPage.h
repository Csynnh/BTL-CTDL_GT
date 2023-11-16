#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
class FourthPage
{
private:
	int selectedItemIndex;
	Font font;
	Font fontFilmName;
	Font fontTitle;
	Font fontDesc;
	Font fontHeader;
	Text menu[50];
	BlockContainer m_blocks;
	TextContainer m_texts;

public:
	FourthPage();
	~FourthPage();
	void draw(RenderWindow& window);
	bool prevButtonIsPressed(RenderWindow& window, Vector2i mousePos);
	bool nextButtonIsPressed(RenderWindow& window, Vector2i mousePos);
	void seatUpdate(vector<int> seats);
	void resetSeatText(vector<int> seats);
	//	bool isSeatSelected(RenderWindow& window);
	//	vector<int> seatSelected(RenderWindow& window);
};
