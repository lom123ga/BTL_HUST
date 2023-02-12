#include "AppButton.h"

AppButton::AppButton()
{
    m_isHandling = false;
}

AppButton::~AppButton()
{
}

void AppButton::Init(std::string name)
{
	sf::Texture* texture;
	texture = ASSET->getTexture(name);
	this->setTexture(texture);
	this->setSize(sf::Vector2f(100, 100));
}

void AppButton::Update(float deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		HandleTouchEvent();
	}
}

void AppButton::Render(sf::RenderWindow* window)
{
	window->draw(*this);
}

void AppButton::HandleTouchEvent()
{
	m_isHandling = false;
	if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))) {
		m_bottonClickFunc();
		m_isHandling = true;
	}
}

bool AppButton::isHandle()
{
	return m_isHandling;
}

void AppButton::setOnClick(void(*Func)())
{
	m_bottonClickFunc = Func;
}
