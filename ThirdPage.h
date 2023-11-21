#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "MainTab.h"
#include "dataBase.h"
class ThirdPage : public MainTab
{
private:
	vector<int> seats;
	int selectedItemIndex;
	Font font;
	Font exBold;
	Font bold;
	Font semiBold;
	Font regular;
	Text menu[50];
	BlockContainer m_blocks;
	TextContainer m_texts;

	float xPos = 40.0f;
	float yPos = 85.0f;
	float xScale = 0.55;
	float yScale = 0.55;
	float xLogoPosition = 220;
	float yLogoPosition = 20.0f;
	float xIconPrevPosition = 40.0f;
	float yIconPrevPosition = 35.0f;

public:
	ThirdPage(int num);
	~ThirdPage();
	void draw(RenderWindow& window);
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