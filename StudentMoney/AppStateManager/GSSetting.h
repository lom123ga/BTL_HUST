#pragma once
#include "AppStateBase.h"
#include "TextBox.h"
#include <sstream>
#include <fstream>

class GSSetting : public AppStateBase {
public:
	GSSetting();
	virtual ~GSSetting();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void setData();
private:
	list<AppButton*> m_listButton;
	sf::Text m_title;
	sf::Sprite m_background;
	Textbox* data[4];
	sf::Text name[4];
	bool is_selectec[4] = { true,true,true,true };
	float t_time = 0;
	ofstream out;
	bool kt = false;
};