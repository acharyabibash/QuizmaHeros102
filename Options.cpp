#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "Options.hpp"
#include "MainMenuState.hpp"
#include <iostream>

namespace Quizma
{
	Options::Options(GameDataRef data) : _data(data)
	{

	}

	void Options::Init()
	{
		this->_data->assets.LoadTexture("Game Background", OPTONS_SCREEN_FILEPATH);
		this->_data->assets.LoadTexture("Option 1 Image", OPTIONS_ON);
		this->_data->assets.LoadTexture("Option 2 Image", OPTIONS_OFF);
		this->_data->assets.LoadTexture("Option Back", OPTIONS_BACK);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		_option_1.setTexture(this->_data->assets.GetTexture("Option 1 Image"));
		_option_2.setTexture(this->_data->assets.GetTexture("Option 2 Image"));
		_option_back.setTexture(this->_data->assets.GetTexture("Option Back"));

		_option_1.setPosition((SCREEN_WIDTH / 2) - (_option_1.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_option_1.getGlobalBounds().height / 2));
		_option_2.setPosition((SCREEN_WIDTH / 2) - (_option_2.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.5) - (_option_2.getGlobalBounds().height / 2));
		_option_back.setPosition(1500, 900);
	}

	void Options::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_option_1, sf::Mouse::Left, this->_data->window))
			{
				//Music Plays!!
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->music.play();
			}

			else if (this->_data->input.IsSpriteClicked(this->_option_2, sf::Mouse::Left, this->_data->window))
			{
				//Music Dies!!
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->music.pause();
			}

			else if (this->_data->input.IsSpriteClicked(this->_option_back, sf::Mouse::Left, this->_data->window))
			{
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}

		}
	}

	void Options::Update(float dt)
	{

	}

	void Options::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_option_1);
		this->_data->window.draw(this->_option_2);
		this->_data->window.draw(this->_option_back);

		this->_data->window.display();
	}


}