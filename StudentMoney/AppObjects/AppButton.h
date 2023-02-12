#pragma once
#include "../AppManager/WindowConnector.h"
#include "../AppManager/ResourceManager.h"

class AppButton : public sf::RectangleShape {
public:
	AppButton();
	~AppButton();

	void Init(std::string name);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	void HandleTouchEvent();
	bool isHandle();

	void setOnClick(void (*Func)());
private:
	void (*m_bottonClickFunc)();
	bool m_isHandling;
	float m_CurrentTime;
	float m_TimeRelease;
	std::string m_path;
};