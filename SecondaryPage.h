#pragma once
#include "TextContainer.h"
#include "BlockContainer.h"
class SecondaryPage
{
	int id_Flim;
	TextContainer m_text;
	BlockContainer m_image;

public:
	SecondaryPage(int id) : id_Flim(id), m_text("textContent"), m_image("image")
	{
		DrawContent();
	}
	void DrawContent();
	void Render(RenderWindow &ref);
	void Hover(int PosX, int PosY);
	void Blur(int PosX, int PosY);
	void hoverDate(int Posx,int PosY);
};
