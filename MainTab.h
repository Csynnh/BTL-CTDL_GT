#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
class MainTab {
protected:
	int selectedItemIndex;
	Font bold;
	Font semiBold;
	Font regular;
	int curentState;// ID của các page
public:
	MainTab() {}// hàm mặc định
	MainTab(int num) // hàm mặc định có tham số
	{
		selectedItemIndex = num;
		curentState = num;
	}
	virtual void draw(RenderWindow& window) = 0; // phương thức ảo để vẽ
	virtual void HandleMouseClick(int x, int y) = 0;
	virtual void Click(int x, int y) = 0;
	virtual int GetState() = 0;
	virtual int GetCurrentState() = 0;
	virtual void SetCurrentState(int state) = 0;
};