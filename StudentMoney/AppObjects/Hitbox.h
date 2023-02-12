#pragma once
#include "../AppManager/ResourceManager.h"
enum TAG
{
	NONE
};
class HitBox :public sf::RectangleShape {
public:
	HitBox(sf::Vector2i size);
	~HitBox();
	void Init(sf::Vector2f velocity);

	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f velocity);
	TAG getTag() { return m_Tag; };
	void SetTag(TAG tag) { m_Tag = tag; }

	bool isAlive() { return m_isAlive; }
	void setAlive(bool alive) { m_isAlive = alive; }
	void setCanFall(bool canfall) { m_canFall = canfall; }
	bool getCanFall() { return m_canFall; }
	void setCanJump(bool canjump) { m_canJump = canjump; }
	void setCanL(bool canl) { m_moveL = canl; }
	void setCanR(bool canr) { m_moveR = canr; }
	bool getCanJump() { return m_canJump; }
	bool getCanL() { return m_moveL; }
	bool getCanR() { return m_moveR; }
	bool getAttack() { return m_attack; }
	void setAttack(bool attack) { m_attack = attack; }
	void setHP(int hp) { m_HP = hp; }
	int getHP() { return m_HP; }
private:
	sf::Vector2f m_Velocity;
	bool m_isAlive;
	bool m_canFall;
	bool m_moveL;
	bool m_moveR;
	bool m_canJump;
	bool m_attack;
	int m_HP;
	TAG m_Tag;
};