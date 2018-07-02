#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Quizma
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;

		sf::Music music;
		sf::Music music1;
		sf::Music music2;
		sf::Music music3;
		sf::SoundBuffer buffer;
		sf::Sound sound;
		sf::Font font;
		sf::Text text;
		sf::Text texts;

		std::ifstream questionFile;
		std::vector<std::string> question;

		std::ifstream answerFile;
		std::vector<std::string> answers;

	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Games
	{
	public:
		Games(int width, int height, std::string title);

	private:

		// Updates run at 60 per second.
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};
}