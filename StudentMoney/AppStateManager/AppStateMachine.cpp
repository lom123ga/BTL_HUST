#include "AppStateMachine.h"
#include "AppStateBase.h"

AppStateMachine::AppStateMachine()
{
    m_ActiveState = nullptr;
    m_NextState = nullptr;
}

AppStateMachine::~AppStateMachine()
{
    while (!m_StateStack.empty()) {
        delete m_StateStack.back();
        m_StateStack.pop_back();
    }
}

void AppStateMachine::ChangeState(AppStateBase* state)
{
    m_NextState = state;
}

void AppStateMachine::ChangeState(StateTypes st)
{
    AppStateBase* gs = AppStateBase::CreateState(st);
    ChangeState(gs);
}

void AppStateMachine::PushState(StateTypes st)
{
    AppStateBase* gs = AppStateBase::CreateState(st);
    if (!m_StateStack.empty()) {
        m_StateStack.back()->Pause();
    }
    m_NextState = gs;
}

void AppStateMachine::PopState()
{
    if (!m_StateStack.empty()) {
        m_StateStack.back()->Exit();
        m_StateStack.pop_back();
    }

    if (!m_StateStack.empty()) {
        m_StateStack.back()->Resume();
    }
    m_ActiveState = m_StateStack.back();
}

void AppStateMachine::PerformStateChange()
{
    if (m_NextState != nullptr) {
        if (!m_StateStack.empty()) {
            m_StateStack.back()->Exit();
        }
        m_StateStack.push_back(m_NextState);
        m_StateStack.back()->Init();
        m_ActiveState = m_NextState;
    }
    m_NextState = nullptr;
}

AppStateBase* AppStateMachine::currentState()
{
    return m_ActiveState;
}

AppStateBase* AppStateMachine::nextState()
{
    return m_NextState;
}

bool AppStateMachine::NeedToChangeState()
{
    return m_NextState != nullptr;
}

bool AppStateMachine::HasState()
{
    return m_StateStack.size() > 0;
}
