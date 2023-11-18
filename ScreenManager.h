#pragma once
#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "MainTab.h"
#include "FirstPage.h"
#include "SecondTab.h"
#include "ThirdTab.h"
#include "SecondaryPage.h"
enum eScreen
{
	// enum để chạy các page
	TAB_FIRST = 1,
	TAB_SECOND,
	TAB_THRIS,
	TAB_FIRST_PHIM1 = 11,
	TAB_END
};
class ScreenManager {
private:
	MainTab** maintablist; // Khai báo mảng con trỏ để quản lý
	int size = 4; // xem tất cả các page có bao nhiu để khai báo size
	eScreen current = TAB_FIRST; // mặc định khi chạy là firstTab
public:
	ScreenManager()
	{
		// đưa tên các file để chạy
		maintablist = new MainTab * [size];
		maintablist[0] = new FirstPage(TAB_FIRST);
		maintablist[1] = new SecondTab(TAB_SECOND);
		maintablist[2] = new ThirdTab(TAB_THRIS);
		//maintablist[3] = new SecondaryPage(TAB_FIRST_PHIM1);
	}
	// giải phóng vùng nhớ
	~ScreenManager()
	{
		for (int i = 0; i < size; i++) {
			delete maintablist[i];
		}
	}

	void updateCurrentState(); // cập nhật lại trạng thái hiện tại
	void draw(RenderWindow& window); // vẽ
	void HandleMouseClick(int x, int y); // sự kiện các tab
	void Click(int x, int y); // sự kiện các phim
};