#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
#include "ThirdPage.h"
#include "MainTab.h"
#include "dataBase.h"
class FourthPage : public MainTab
{
private:
	int selectedItemIndex;
	pair<int, int> m_seats;
	BlockContainer m_blocks;
	TextContainer m_texts;
	BlockContainer b_payment;
	TextContainer t_payment;
	BlockContainer b_offer;
	TextContainer t_offer;

	bool isOfferSelected = false;
	bool isPaymentSelected = false;

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
	void setSeat(const ThirdPage& temp) {
		m_seats = temp.getSeat();
	}
	void selectOffer();
	void resetOffer();
	void HandleChoseOffer(int x, int y);
	void selectPayment();
	void resetPayment();
	void HandleChosePayment(int x, int y);
	void HandleMouseClick(int x, int y);
	void Click(int x, int y);
	int GetState();
	int GetCurrentState();
	void SetCurrentState(int state);
};
