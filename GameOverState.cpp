#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "Games.hpp"

#include <iostream>

namespace Quizma
{
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{

	}

	void GameOverState::Init()
	{
		this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Over", GAME_OVER_IMAGE);

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
		_gameOver.setTexture(this->_data->assets.GetTexture("Game Over"));

		_gameOver.setPosition((SCREEN_WIDTH / 2) - (_gameOver.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_gameOver.getGlobalBounds().height / 2));
	}

	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void GameOverState::Update(float dt)
	{
		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			// Close the application
			this->_data->window.close();
		}
	}

	void GameOverState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_gameOver);
		this->_data->window.display();
	}
}