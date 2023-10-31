#include "I_Component.h"
#include "TextComponent.h" 
#include <iostream>
#include <vector>
using namespace std;
using namespace std;
#pragma once
class TextContainer
{
    string m_name;
    vector<shared_ptr<I_Component>> m_components;

public:
    TextContainer(string name);
    ~TextContainer() {}
    void AddTextContainer(string text, Font& font, unsigned int size, Color color, float xPosotion = 1, float yPosotion = 1);
    void Render(RenderWindow& ref);
};

