#pragma once
#include "AppStateBase.h"
#include "../AppObjects/UI.h"
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class GSPlay : public AppStateBase {
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void deleteLastChar();
	void inputLogic(int charTyped);
	void UpdateText();
private:
	sf::Text textbox;

	std::ostringstream text;
	ofstream out;
	list<AppButton*> m_listButton;
	sf::View* m_view;
	int m_currentScore;
	float m_currentTime;
	sf::Sprite m_background;
	bool first = true;
	bool is_selected = true;
	float t_time;
};