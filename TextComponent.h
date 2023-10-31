#pragma once
#include <iostream>
#include "I_Component.h"
using namespace std;
class TextComponent : public I_Component
{
private:
    Text m_text;

public:
    TextComponent(string text, Font& font, unsigned int size, Color color = Color::Black, float xPosotion = 1, float yPosotion = 1);
    ~TextComponent() {}
    void Render(RenderWindow& ref);
};

