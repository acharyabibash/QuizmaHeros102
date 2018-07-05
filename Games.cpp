#include "Games.hpp"
#include "SplashState.hpp"
#include <fstream>
#include "DEFINITIONS.hpp"

namespace Quizma
{
	Games::Games(int width, int height, std::string title)
	{
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);
		_data->machine.AddState(StateRef(new SplashState(this->_data)));
		_data->music.openFromFile("glasgowkiss.wav");
		_data->music1.openFromFile("buu.wav");
		_data->music2.openFromFile("L Theme.wav");
		_data->music3.openFromFile("vegeta.wav");
		_data->buffer.loadFromFile("Choose.wav");

		_data->font.loadFromFile("CENTAUR.ttf");
		_data->text.setFont(this->_data->font);
		_data->texts.setFont(this->_data->font);

		std::ifstream questionFile(QUESTION_FILEPATH);

		if (questionFile.is_open()) {
			while (!questionFile.eof())
			{
				std::string questionTemp;
				std::getline(questionFile, questionTemp);
				this->_data->question.push_back(questionTemp);
			}
		}

		std::ifstream answerFile(ANSWERS_FILEPATH);

		if (answerFile.is_open()) {
			while (!answerFile.eof())
			{
				std::string answerTemp;
				std::getline(answerFile, answerTemp);
				this->_data->answers.push_back(answerTemp);
			}
		}

		

		this->Run();
	}

	void Games::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen()) //main game loop
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.05f)
			{
				frameTime = 0.05f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}
	}
	
}