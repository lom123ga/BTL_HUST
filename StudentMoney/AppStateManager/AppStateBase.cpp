#include "AppStateBase.h"
#include "GSMenu.h"
#include "GSInfo.h"
#include "GSPlay.h"
#include "GSSetting.h"
#include "GSEnd.h"

AppStateBase::AppStateBase()
{
}

AppStateBase::~AppStateBase()
{
}

AppStateBase* AppStateBase::CreateState(StateTypes st)
{
	AppStateBase* gs = nullptr;
	switch (st)
	{
	case STATE_INVALID:
		break;
	case STATE_INTRO:
		//gs = new GSIntro();
		break;
	case STATE_MENU:
		gs = new GSMenu();
		break;
	case STATE_INFO:
		gs = new GSInfo();
		break;
	case STATE_PLAY:
		gs = new GSPlay();
		break;
	case STATE_PAUSE:
		//gs = new GSPause();
		break;
	case STATE_SETTING:
		gs = new GSSetting();
		break;
	case STATE_END:
		gs = new GSEnd();
		break;
	default:
		break;
	}
	return gs;
}
