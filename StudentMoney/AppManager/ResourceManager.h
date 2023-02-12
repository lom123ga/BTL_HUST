#pragma once
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include "../AppConfig.h"
#include "../AppObjects/Animation.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../AppObjects/AppButton.h"
#include <fstream>

using namespace std;

#define ASSET ResourceManager::GetInstance()

class ResourceManager :public CSingleton<ResourceManager> {
public:
	ResourceManager();
	~ResourceManager();

	void addTexture(std::string name);
	void removeTexture(std::string name);
	sf::Texture* getTexture(std::string name);

	void addFont(std::string name);
	void removeFont(std::string name);
	sf::Font* getFont(std::string name);

	void addSound(std::string name);
	void removeSound(std::string name);
	sf::Sound* getSound(std::string name);

	void addMusic(std::string name);
	void removeMusic(std::string name);
	sf::Music* getMusic(std::string name);

	void playMusic(std::string name);
	void playSound(std::string name);
	void setAllowSound(bool allow);

	vector<pair<string, pair<int, pair<string, int>>>> readRecordFile(string data);


private:
	std::map<std::string, sf::Texture*> m_MapTexture;
	std::map<std::string, sf::Font*> m_MapFont;
	std::map<std::string, sf::Sound*> m_MapSound;
	std::map<std::string, sf::Music*> m_MapMusic;

	std::string m_Path;
	std::string m_TexturePath;
	std::string m_FontPath;
	std::string m_SoundPath;

	bool m_allowSound;
};