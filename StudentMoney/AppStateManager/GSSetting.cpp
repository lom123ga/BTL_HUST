#include "GSSetting.h"
#include "../Application.h"

GSSetting::GSSetting()
{
}

GSSetting::~GSSetting()
{
}

void GSSetting::Exit()
{
}

void GSSetting::Pause()
{
}

void GSSetting::Resume()
{
}

void GSSetting::Init()
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


	name[0].setString("Activity      : ");
	name[1].setString("Price          : ");
	name[2].setString("Note          : ");
	name[3].setString("Day (1-30) : ");
	name[0].setCharacterSize(40);
	name[1].setCharacterSize(40);
	name[2].setCharacterSize(40);
	name[3].setCharacterSize(40);
	name[0].setFillColor(sf::Color::Black);
	name[1].setFillColor(sf::Color::Black);
	name[2].setFillColor(sf::Color::Black);
	name[3].setFillColor(sf::Color::Black);
	name[0].setFont(*ASSET->getFont("font"));
	name[1].setFont(*ASSET->getFont("font"));
	name[2].setFont(*ASSET->getFont("font"));
	name[3].setFont(*ASSET->getFont("font"));
	name[0].setPosition(sf::Vector2f(screenWidth / 2 - 400, screenHeight / 2 - 150));
	name[1].setPosition(sf::Vector2f(screenWidth / 2 - 400, screenHeight / 2 - 50));
	name[2].setPosition(sf::Vector2f(screenWidth / 2 - 400, screenHeight / 2 + 50));
	name[3].setPosition(sf::Vector2f(screenWidth / 2 - 400, screenHeight / 2 + 150));

	data[0] = new Textbox(40, sf::Color::Black, true);
	data[1] = new Textbox(40, sf::Color::Black, true);
	data[2] = new Textbox(40, sf::Color::Black, true);
	data[3] = new Textbox(40, sf::Color::Black, true);
	data[0]->setFont(*ASSET->getFont("font"));
	data[1]->setFont(*ASSET->getFont("font"));
	data[2]->setFont(*ASSET->getFont("font"));
	data[3]->setFont(*ASSET->getFont("font"));
	data[0]->setPosition(sf::Vector2f(screenWidth / 2 - 100, screenHeight / 2 - 150));
	data[1]->setPosition(sf::Vector2f(screenWidth / 2 - 100, screenHeight / 2 - 50));
	data[2]->setPosition(sf::Vector2f(screenWidth / 2 - 100, screenHeight / 2 + 50));
	data[3]->setPosition(sf::Vector2f(screenWidth / 2 - 100, screenHeight / 2 + 150));


	out.open("../Data/FileData/DATABASE.txt", ios::app);

}

void GSSetting::Update(float deltaTime)
{
	for (auto button : m_listButton) {
		button->Update(deltaTime);
	}
	t_time += deltaTime;
	if (t_time >= 0.13) {
		for (int i = 0; i < 4; i++) {
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
	for (int i = 0; i < 4; i++) {
		if (is_selectec[i] == false) cont++;
	}

	if (cont != 4) kt = false;

	if (cont == 4 && kt == false) {
		kt = true;
		setData();
		ifstream in("../Data/FileData/COIN.txt",ios::out || ios::app);
		string sin;
		in >> sin;
		in.close();
		long long sum = 0;
		if (sin.length() != 0)
		{
			if (sin[0] == '-') {
				sin.erase(0);
				sum = stoi(sin);
				sum = -sum;
			}

			else sum = stoi(sin);
		}
		long long sum1 = 0;
		if (data[1]->getText() != "")
		sum1 = stoi(data[1]->getText());
		sum -= sum1;
		if (sum < 0) sin = to_string(-sum), sin = '-' + sin;
		else sin = to_string(sum);
		out.open("../Data/FileData/COIN.txt");
		out << sin;
		out.close();
		if (sum <= 100000) GSMC->ChangeState(STATE_INFO);
	}
}

void GSSetting::Render(sf::RenderWindow* window)
{
	window->draw(m_background);
	//window->draw(m_title);
	for (auto button : m_listButton) {
		button->Render(window);
	}
	for (int i = 0; i < 4; i++) {
		window->draw(name[i]);
	}
	for (int i = 0; i < 4; i++) {
		data[i]->drawTo(*window);
	}
}

void GSSetting::setData()
{
	for (int i = 0; i < 4; i++) { out << data[i]->getText() << "\n"; }
	out.close();
}
