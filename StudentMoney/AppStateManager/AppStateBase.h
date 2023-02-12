#pragma once
#include <SFML/Graphics.hpp>
#include "../AppManager/ResourceManager.h"
#include "AppStateMachine.h"

class AppStateBase {
public:
	AppStateBase();
	virtual ~AppStateBase();
	static AppStateBase* CreateState(StateTypes st);

	virtual void Exit() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;

};