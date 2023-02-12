#pragma once
#include "../AppManager/Singleton.h"
#include <iostream>
#include <list>

class AppStateBase;

enum StateTypes
{
	STATE_INVALID = 0,
	STATE_INTRO,
	STATE_MENU,
	STATE_INFO,
	STATE_PLAY,
	STATE_PAUSE,
	STATE_SETTING,
	STATE_END,
};
#define	GSMC AppStateMachine::GetInstance()
class AppStateMachine :public CSingleton<AppStateMachine> {
public:
	AppStateMachine();
	~AppStateMachine();
	void ChangeState(AppStateBase* state);
	void ChangeState(StateTypes st);
	void PushState(StateTypes st);
	void PopState();

	void PerformStateChange();

	AppStateBase* currentState();
	AppStateBase* nextState();
	bool NeedToChangeState();
	bool HasState();

private:
	std::list < AppStateBase* >	m_StateStack;
	AppStateBase* m_ActiveState;
	AppStateBase* m_NextState;
};