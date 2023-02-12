#include "GSMenu.h"

GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	AppButton* button;

	//Enter Play Button
	button = new AppButton();
	button->Init("add");
	button->setOnClick([]() {GSMC->PushState(StateTypes::STATE_PLAY); });
	button->setSize(sf::Vector2f(260, 120));
	button->setPosition(screenWidth / 2 - 3 * screenWidth / 12, screenHeight - screenHeight / 2);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//Setting Button
	button = new AppButton();
	button->Init("sub");
	button->setOnClick([]() {GSMC->PushState(StateTypes::STATE_SETTING); });
	button->setSize(sf::Vector2f(240, 120));
	button->setPosition(screenWidth / 2  + 3 * screenWidth / 12, screenHeight - screenHeight / 2);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//Info Button
	button = new AppButton();
	button->Init("show");
	button->setOnClick([]() {GSMC->PushState(StateTypes::STATE_END); });
	button->setSize(sf::Vector2f(260, 130));
	button->setPosition(screenWidth / 2 - 3*screenWidth / 12, screenHeight - screenHeight / 6);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//Exit Button
	button = new AppButton();
	button->Init("exit");
	button->setOnClick([]() {WConnect->getWindow()->close(); });
	button->setSize(sf::Vector2f(240, 120));
	button->setPosition(screenWidth / 2 + 3 * screenWidth / 12, screenHeight - screenHeight / 6);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//Background
	sf::Texture* texture = ASSET->getTexture("./qlct1");
	m_background.setTexture(*texture);

	m_background.setPosition(screenWidth / 2, screenHeight / 2);
	m_background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_background.setScale(1.f * screenWidth / m_background.getTexture()->getSize().x, 1.f * screenHeight / m_background.getTexture()->getSize().y);

}

void GSMenu::Update(float deltaTime)
{
	WConnect->getWindow()->setMouseCursorVisible(true);
	for (auto button : m_listButton) {
		button->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->setView(window->getDefaultView());
	window->draw(m_background);
	window->draw(m_title);
	for (auto button : m_listButton) {
		button->Render(window);
	}
}
