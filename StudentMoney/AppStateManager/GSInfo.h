#pragma once
#include "AppStateBase.h"
class GSInfo : public AppStateBase {
public:
	GSInfo();
	virtual ~GSInfo();

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
	std::list<sf::Text*> m_infor;
};