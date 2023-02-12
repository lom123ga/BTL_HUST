#include "GSPlay.h"
#include <fstream>
#include "../Application.h"

GSPlay::GSPlay()
{
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
	WConnect->getWindow()->setMouseCursorVisible(false);
}

void GSPlay::Init()
{
	WConnect->getWindow()->setMouseCursorVisible(true);
	GUI->Init();

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
	sf::Texture* texture = ASSET->getTexture("/add1");
	m_background.setTexture(*texture);

	m_background.setPosition(screenWidth / 2, screenHeight / 2);
	m_background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_background.setScale(1.f * screenWidth / m_background.getTexture()->getSize().x, 1.f * screenHeight / m_background.getTexture()->getSize().y);

	out.open("../Data/FileData/COIN.txt");
	textbox.setCharacterSize(50);
	textbox.setFillColor(sf::Color::Black);
	textbox.setPosition(sf::Vector2f(350, 240));
	textbox.setFont(*ASSET->getFont("font"));
	is_selected = true;
	t_time = 0;
}

void GSPlay::Update(float deltaTime)
{

	for (auto button : m_listButton) {
		button->Update(deltaTime);
	}
	t_time += deltaTime;
	if (t_time >= 0.12) {
		UpdateText();
		t_time -= 0.1;
	}

}

void GSPlay::UpdateText() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && out.is_open()) {
		is_selected = false;
		out << text.str();
		out.close();
		out.open("../Data/FileData/DATABASE.txt");
		out.close();
	}
	else {
		int num = -1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
			num = '0';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
			num = 1 + '0';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
			num = 2 + '0';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
			num = 3 + '0';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
			num = 4 + '0';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
			num = 5 + '0';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
			num = 6 + '0';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
			num = 7 + '0';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
			num = 8 + '0';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
			num = 9 + '0';
		}
		if (num != -1) inputLogic(num);
	}
}

void GSPlay::Render(sf::RenderWindow* window)
{
	window->setView(window->getDefaultView());
	window->draw(m_background);
	for (auto it : m_listButton) {
		it->Render(window);
	}
	window->draw(textbox);
}

void GSPlay::deleteLastChar()
{
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++) {
		newT += t[i];
	}
	text.str("");
	text << newT;
	textbox.setString(text.str() + "_");
}

void GSPlay::inputLogic(int charTyped)
{
	// If the key pressed isn't delete, or the two selection keys, then append the text with the char:
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY && text.str().length() < 14) {
		text << static_cast<char>(charTyped);
	}
	// If the key is delete, then delete the char:
	else if (charTyped == DELETE_KEY) {
		if (text.str().length() > 0) {
			deleteLastChar();
		}
	}
	// Set the textbox text:
	textbox.setString(text.str() + "_");
}
