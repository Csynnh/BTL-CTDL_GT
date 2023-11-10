#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"

class SecondaryPage
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

	float xPos = 40.0f;
	float yPos = 85.0f;
	float xScale = 0.55;
	float yScale = 0.55;
	float xPosInfo = 200.0f;
	float wBgGray = 73;
	float wBgGrayLarger = 285;

	int DateWasSelected = -1;
	int CenimaWasSelected = -1;
	int TimeWasSelected = -1;

public:
	SecondaryPage(int num);
	~SecondaryPage();
	// int getDateWasSelected() { return isDateWasSelected; }
	// int getCenimaWasSelected() { return isCenimaWasSelected; }
	// int getFlimWasSelected() { return isFlimWasSelected; }
	void draw(RenderWindow &window);
	void ChoseDate(BlockContainer &a, TextContainer &b);
	void ChoseCenima(BlockContainer &a, TextContainer &b);
	void ChoseTime(BlockContainer &a, TextContainer &b);
	void HandleChoseDate(int xMouse, int yMouse);
	void HandleChoseCenima(int xMouse, int yMouse);
	void HandleChoseTime(int xMouse, int yMouse);
	void clearBgGray();
	void clearChoseCenima();
	void clearChoseTime();

	// void Hover(int PosX, int PosY);
	// void Blur(int PosX, int PosY);
	// void hoverDate(int Posx, int PosY);

	// void Hover();
	// void Blur();
	// int GetPressedItem() { return selectedItemIndex; }
};