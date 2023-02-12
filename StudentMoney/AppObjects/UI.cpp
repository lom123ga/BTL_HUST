#include "UI.h"

UI::UI()
{
	m_Heart.resize(4);
	m_Coin = 0;
	m_numHp = 4;
}

UI::~UI()
{

}

void UI::Init()
{
	m_pHp = sf::Vector2f(20, 30);
	m_pCoin = sf::Vector2f(20, 62);

	for (int i = 0; i < 4; i++) {
		m_Heart[i] = new Animation(*ASSET->getTexture("heart"),sf::Vector2i(1,1),0.1f);
		m_Heart[i]->setModeEndFrame(true);
		m_Heart[i]->setPosition(m_pHp.x + i*32,m_pHp.y);
	}
	m_Score = new sf::Text;
	m_Score->setFont(*ASSET->getFont("T1"));
	m_Score->setString("SCORE : " + std::to_string(m_Coin));
	m_Score->setFillColor(sf::Color::Black);
	m_Score->setPosition(m_pCoin);
}

void UI::Update(float deltaTime)
{
	m_Score->setString("SCORE : " + std::to_string(m_Coin));
	for (int i = 0; i < 4; i++) {
		m_Heart[i]->Update(deltaTime);
	}
}

void UI::Render(sf::RenderWindow* window)
{
	window->draw(*m_Score);
	for (int i = 0; i < m_numHp; i++) {
		window->draw(*m_Heart[i]);
	}
}
