#include "GSInfo.h"

GSInfo::GSInfo()
{
}

GSInfo::~GSInfo()
{
}

void GSInfo::Exit()
{
}

void GSInfo::Pause()
{
}

void GSInfo::Resume()
{
}

void GSInfo::Init()
{
	AppButton* button;

	// Return Button
	button = new AppButton();
	button->Init("back");
	button->setOnClick([]() {GSMC->PopState(); });
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth - screenWidth / 16, screenHeight / 13);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//Background
	sf::Texture* texture = ASSET->getTexture("/base");
	m_background.setTexture(*texture);

	m_background.setPosition(screenWidth / 2, screenHeight / 2);
	m_background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_background.setScale(1.f * screenWidth / m_background.getTexture()->getSize().x, 1.f * screenHeight / m_background.getTexture()->getSize().y);

	//Title
	sf::Text* text = new sf::Text();
	text->setFont(*ASSET->getFont("font"));
	text->setFillColor(sf::Color::Black);
	text->setString("So tien con lai duoi 100.000 vnd");
	text->setPosition(sf::Vector2f(screenWidth / 6, screenHeight / 4));
	m_infor.push_back(text);

	text = new sf::Text();
	text->setFont(*ASSET->getFont("font"));
	text->setFillColor(sf::Color::Black);
	text->setString("Vui long an choi it lai");
	text->setPosition(sf::Vector2f(screenWidth / 6, screenHeight / 2));
	m_infor.push_back(text);
}

void GSInfo::Update(float deltaTime)
{
	for (auto button : m_listButton) {
		button->Update(deltaTime);
	}
}

void GSInfo::Render(sf::RenderWindow* window)
{
	window->draw(m_background);
	for (auto button : m_listButton) {
		button->Render(window);
	}
	for (auto infor : m_infor) {
		window->draw(*infor);
	}
	window->draw(m_title);
}
