#pragma once
//ACTUAL CONTENTS OF THE INITIAL PHASE AND PROCEEDINGS OF THE GAME ITSELF
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState2.hpp"
#include "GameOverState.hpp"
#include <iostream>

namespace Quizma
{
	GameState2::GameState2(GameDataRef data) : _data(data)
	{

	}

	void GameState2::Init()
	{
		this->_data->assets.LoadTexture("Game Background", GAME_SCREEN_2_FILEPATH);
		this->_data->assets.LoadTexture("Quit Image", QUIT_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		_Quit.setTexture(this->_data->assets.GetTexture("Quit Image"));

		_Quit.setPosition(1500,850);
	}

	void GameState2::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_Quit, sf::Mouse::Left, this->_data->window))
			{
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
			}

		}
	}

	void GameState2::Update(float dt)
	{

	}

	void GameState2::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_Quit);

		this->_data->window.display();
	}


}