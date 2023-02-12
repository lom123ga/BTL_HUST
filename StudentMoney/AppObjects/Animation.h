#pragma once
#include <SFML/Graphics.hpp>

class Animation : public sf::Sprite {
private:
	// variable:
	sf::Vector2i m_frameNum;
	sf::Vector2i m_currentFrame;
	sf::Vector2i m_rectPos;
	sf::Vector2i m_rectSize;

	sf::IntRect m_rect;

	float m_frameTime;
	float m_currentTime;

	bool m_modeStopAtEndFrame;
	// function:

public:
	// variable:

	// function:
	Animation();
	Animation(sf::Texture& texture, sf::Vector2i frameNum, float frameTime);
	void CalRectSize();
	void CalRectPos();
	void ApplyRect();
	sf::Vector2i GetRectSize();
	void Update(float deltaTime);
	//void Reset(sf::Texture& texture, sf::Vector2i frameNum, float frameTime);
	void Reset();
	bool Play(float deltaTime);

	void setModeEndFrame(bool stop);
	sf::Vector2i getFrameNum() { return m_frameNum; }
	sf::Vector2i getCurrentFrame() { return m_currentFrame; }
};