#include "Application.h"
#include "AppStateManager/AppStateBase.h"

void Application::Init()
{
    event = sf::Event();
    m_window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), "Money Student Manager", sf::Style::Close);
    m_window->setFramerateLimit(144);
    m_window->setVerticalSyncEnabled(false);
    AppStateMachine::GetInstance()->ChangeState(StateTypes::STATE_MENU);
    WConnect->setWindow(m_window);
    srand(time(NULL));
}

void Application::Update(float deltaTime)
{
    if (AppStateMachine::GetInstance()->NeedToChangeState()) {
        AppStateMachine::GetInstance()->PerformStateChange();
    }
    AppStateMachine::GetInstance()->currentState()->Update(deltaTime);

}

void Application::Run()
{
    Init();
    sf::Clock clock;
    float deltaTime = 0.f;
    while (m_window->isOpen()) {
        deltaTime = clock.restart().asSeconds();
        while (m_window->pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                m_window->close();
        }
        Update(deltaTime);
        Render();
    }
}

sf::Event Application::getEvent()
{
    return event;
}

void Application::Render()
{
    m_window->clear();
    AppStateMachine::GetInstance()->currentState()->Render(m_window);
    m_window->display();
}

Application::~Application()
{
	if (m_window != nullptr) delete m_window;
}
