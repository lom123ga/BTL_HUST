#include "GSEnd.h"
#include "../Application.h"

GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	AppButton* button;
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

	name[0].setString("Start : ");
	name[1].setString("End : ");
	name[0].setCharacterSize(50);
	name[1].setCharacterSize(50);
	name[0].setFillColor(sf::Color::Black);
	name[1].setFillColor(sf::Color::Black);

	name[0].setFont(*ASSET->getFont("font"));
	name[1].setFont(*ASSET->getFont("font"));

	name[0].setPosition(sf::Vector2f(screenWidth / 2 - 400, screenHeight / 2 - 150));
	name[1].setPosition(sf::Vector2f(screenWidth / 2 - 400, screenHeight / 2 - 50));
	

	data[0] = new Textbox(50, sf::Color::Black, true);
	data[1] = new Textbox(50, sf::Color::Black, true);
	
	data[0]->setFont(*ASSET->getFont("font"));
	data[1]->setFont(*ASSET->getFont("font"));
	
	data[0]->setPosition(sf::Vector2f(screenWidth / 2 - 100, screenHeight / 2 - 150));

	data[1]->setPosition(sf::Vector2f(screenWidth / 2 - 100, screenHeight / 2 - 50));



	out.open("../Data/FileData/DATABASE.txt", ios::app);

}

void GSEnd::Update(float deltaTime)
{
	WConnect->getWindow()->setMouseCursorVisible(true);
	for (auto button : m_listButton) {
		button->Update(deltaTime);
	}

	t_time += deltaTime;
	if (t_time >= 0.13) {
		for (int i = 0; i < 2; i++) {
			if (is_selectec[i] == true && APP->getEvent().type == sf::Event::TextEntered) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					is_selectec[i] = false;
					data[i]->setSelected(false);
				}
				else data[i]->typedOn(APP->getEvent());
				break;
			}
		}
		t_time -= 0.09;
	}
	int cont = 0;
	for (int i = 0; i < 2; i++) {
		if (is_selectec[i] == false) cont++;
	}

	if (cont != 2) kt = false;
	if (cont == 2 && kt == false) {
		kt = true;
		users = ASSET->readRecordFile("DATABASE.txt");

		ofstream out("../Data/FileData/SAO_KE/" + data[0]->getText() + "-" + data[1]->getText() + ".txt" );
		int st = 1; int ed = 30;
		if (data[0]->getText() != "") st = stoi(data[0]->getText());
		if (data[1]->getText() != "") ed = stoi(data[1]->getText());
		long long sum = 0;
		for (auto x : users) {
			if (x.second.second.second >= st && x.second.second.second <= ed) {
				string dt = "";
				sum += x.second.first;
				dt = x.first + " " + to_string(x.second.first) + " " + x.second.second.first + " " + to_string(x.second.second.second);
				out << dt << endl;
			}
		}
		out << "Tong tien tieu : " << to_string(sum) << endl;
		out.close();
	}
}

void GSEnd::Render(sf::RenderWindow* window)
{
	window->setView(window->getDefaultView());
	window->draw(m_background);
	//window->draw(m_title);
	for (auto button : m_listButton) {
		button->Render(window);
	}
	
	for (int i = 0; i < 2; i++) {
		window->draw(name[i]);
	}
	for (int i = 0; i < 2; i++) {
		data[i]->drawTo(*window);
	}
}
