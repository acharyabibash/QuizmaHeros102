#pragma once
//ACTUAL CONTENTS OF THE INITIAL PHASE AND PROCEEDINGS OF THE GAME ITSELF
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "GameState2.hpp"
#include <iostream>

namespace Quizma
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		this->_data->assets.LoadTexture("Game Background", GAME_SCREEN_1_FILEPATH);
		this->_data->assets.LoadTexture("Next Page Image", NEXT_PAGE_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		_nextPage.setTexture(this->_data->assets.GetTexture("Next Page Image"));

		_nextPage.setPosition(1500, 850);
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_nextPage, sf::Mouse::Left, this->_data->window))
			{
				// Go to the next page
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new GameState2(_data)), true);
			}

		}
	}

	void GameState::Update(float dt)
	{

	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_nextPage);

		this->_data->window.display();
	}


}