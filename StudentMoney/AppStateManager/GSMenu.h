#pragma once
#include "AppStateBase.h"
class GSMenu : public AppStateBase {
public:
	GSMenu();
	virtual ~GSMenu();

	void Exit();
	void Pause();
	void Resume();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	list<AppButton*> m_listButton;
	sf::Sprite m_background;
	sf::Text m_title;
};