#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "MainTab.h"
class FourthPage : public MainTab
{
private:
	vector<int> seats;
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
	FourthPage(int num);
	~FourthPage();
	void draw(RenderWindow& window);
	bool prevButtonIsPressed(RenderWindow& window, Vector2i mousePos);
	bool nextButtonIsPressed(RenderWindow& window, Vector2i mousePos);
	void seatUpdate(vector<int> seats);
	void resetSeatText(vector<int> seats);
	//	bool isSeatSelected(RenderWindow& window);
	//	vector<int> seatSelected(RenderWindow& window);
	void HandleMouseClick(int x, int y);
	void Click(int x, int y);
	int GetState();
	int GetCurrentState();
	void SetCurrentState(int state);
};
