#include "BlockComponent.h"
BlockComponent::BlockComponent(string filepath, float xPosotion = 1, float yPosotion = 1, float xScale = 1, float yScale = 1, string day = "", string date = "")
{
    m_texture.loadFromFile(filepath);
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(xScale, yScale);
    m_sprite.setPosition(xPosotion, yPosotion);
}
void BlockComponent::Render(RenderWindow& ref)
{
    ref.draw(m_sprite);
}