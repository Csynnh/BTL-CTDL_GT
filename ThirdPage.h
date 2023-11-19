#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "MainTab.h"
class ThirdPage : public MainTab
{
private:
	vector<int> seats;
	int singleSeat = 45;
	int coupleSeat = 90;
	int selectedItemIndex;
	Font font;
	Font exBold;
	Font fontFilmName;
	Font fontTitle;
	Font fontDesc;
	Font fontHeader;
	Text menu[50];
	BlockContainer m_blocks;
	TextContainer m_texts;

public:
	ThirdPage(int num);
	~ThirdPage();
	void draw(RenderWindow& window);
	//bool isButtonPressed(RenderWindow& window, Vector2i mousePos, bool key);
	int seatSelected(int x, int y);
	void seatColorUpdate(vector<int> seatIndex);
	string seatName(int seatIndex);
	void seatUpdate(vector<int> seats, bool key);

	void HandleMouseClick(int x, int y);
	void Click(int x, int y);
	int GetState();
	int GetCurrentState();
	void SetCurrentState(int state);
};