#pragma once
#include <SFML/Graphics.hpp>
#include "AppConfig.h"
#include "AppStateManager/AppStateMachine.h"
#include "AppManager/ResourceManager.h"

#define APP Application::GetInstance()

class Application :public CSingleton < Application> {
private:
	// variable :

	sf::RenderWindow* m_window;
	// function :

	void Init();
	void Update(float deltaTime);
	void Render();

public:
	sf::Event event;

	// function :
	void Run();
	sf::Event getEvent();
	~Application();
};