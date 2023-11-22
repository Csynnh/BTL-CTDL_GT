#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "MainTab.h"
#include "dataBase.h"
class FourthPage : public MainTab
{
private:
	vector<int> seats;
	int selectedItemIndex;
	Font bold;
	Font semiBold;
	Font regular;
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
	FourthPage(int num);
	~FourthPage();
	void draw(RenderWindow& window);
	bool prevButtonIsPressed(RenderWindow& window, Vector2i mousePos);
	bool nextButtonIsPressed(RenderWindow& window, Vector2i mousePos);
//	void seatUpdate(vector<int> seats);
//	void resetSeatText(vector<int> seats);
	//	bool isSeatSelected(RenderWindow& window);
	//	vector<int> seatSelected(RenderWindow& window);

	void ChoseCode(BlockContainer& a, TextContainer& b);
	void ResetCode(BlockContainer& a, TextContainer& b);
	void ChoseMethod(BlockContainer& a, TextContainer& b);
	void ResetMethod(BlockContainer& a, TextContainer& b);
	void HandleChoseCode(int xMouse, int yMouse);
	void HandleChoseMethod(int xMouse, int yMouse);
	void HandleMouseClick(int x, int y);
	void Click(int x, int y);
	int GetState();
	int GetCurrentState();
	void SetCurrentState(int state);
};
