#pragma once
#include "../AppManager/Singleton.h"
#include "../AppManager/ResourceManager.h"
#include "../AppObjects/Animation.h"
#define GUI UI::GetInstance()
class UI :public CSingleton<UI> {
public:
	UI();
	~UI();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void setHP(int HP) { m_numHp = HP; }
	void setCoin(int coin) { m_Coin = coin; }
	int getCoin() { return m_Coin; }
protected:
	sf::Vector2f m_pHp;
	sf::Vector2f m_pCoin;
	int m_numHp;
	int m_Coin;
	std::vector<Animation*> m_Heart;
	sf::Text* m_Score;
};
