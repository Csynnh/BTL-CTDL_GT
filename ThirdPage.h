#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "MainTab.h"
#include "dataBase.h"
class ThirdPage : public MainTab
{
private:
	int price = 0;
	vector<int> seats;
	BlockContainer m_blocks;
	TextContainer m_texts;
	TextContainer seatInfo;

public:
	ThirdPage(int num);
	~ThirdPage();
	void draw(RenderWindow& window);
	pair<int,int> getSeat() const {
		return { seats.size(), price };
	}
	int seatSelected(int x, int y);
	void seatColorUpdate(vector<int> seatIndex);
	string seatName(int seatIndex);
	void seatUpdate(vector<int> seats);
	void HandleMouseClick(int x, int y);
	void Click(int x, int y);
	int GetState();
	int GetCurrentState();
	void SetCurrentState(int state);

	friend class FourthPage;
};