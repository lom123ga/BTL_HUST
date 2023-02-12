#pragma once
#include "AppStateBase.h"
#include "TextBox.h"
#include <fstream>

#include<vector>

class GSEnd : public AppStateBase {
public:
	GSEnd();
	virtual ~GSEnd();

	void Exit();
	void Pause();
	void Resume();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	list<AppButton*> m_listButton;
	sf::Text m_title;
	sf::Sprite m_background;
	Textbox* data[2];
	sf::Text name[2];
	bool is_selectec[2] = { true,true };
	ofstream out;

	vector<pair<string, pair<int, pair<string, int>>>> users;

	float t_time = 0;
	bool kt = false;
};