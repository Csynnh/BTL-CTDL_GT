
#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "MainTab.h"
#include "dataBase.h"

class SecondaryPage : public MainTab
{
private:
	Font font;
	Font fontFilmName;
	Font fontTitle;
//	int selectedItemIndex;
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
	~SecondaryPage(){}
	void draw(RenderWindow& window);
	void ChoseDate(BlockContainer& a, TextContainer& b);
	void ChoseCenima(BlockContainer& a, TextContainer& b);
	void ChoseTime(BlockContainer& a, TextContainer& b);
	void HandleChoseDate(int xMouse, int yMouse);
	void HandleChoseCenima(int xMouse, int yMouse);
	void HandleChoseTime(int xMouse, int yMouse);
	void clearBgGray();
	void clearChoseCenima();
	void clearChoseTime();
	void HandleMouseClick(int x, int y);
	void Click(int x, int y);
	int GetState();
	int GetCurrentState();
	void SetCurrentState(int state);
	bool prevButtonIsPressed(RenderWindow& window);
	bool nextButtonIsPressed(RenderWindow& window);
	void handleResetValue() {
		DateWasSelected = -1;
		CenimaWasSelected = -1;
		TimeWasSelected = -1;
	}
};
