#pragma once
//INITIAL GAME SCREEN
#include <sstream>
#include <fstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "GameState2.hpp"
#include "GameOverState.hpp"
#include <iostream>

namespace Quizma
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

		void GameState::Init()
		{
			/*// FOR QUESTIONS
			this->_data->text.setString(this->_data->question[rand() % 8]);

			// set the character size
			this->_data->text.setCharacterSize(50);
			this->_data->text.setFillColor(sf::Color::White);
			this->_data->text.setPosition(625, 175);


			// FOR ANSWERS
			this->_data->texts.setString(this->_data->answers[0]);
			this->_data->texts.setString(this->_data->answers[1]);*/

			// set the character size
			this->_data->texts.setCharacterSize(50);
			this->_data->texts.setFillColor(sf::Color::Black);
			this->_data->texts.setPosition(300,450);

			this->_data->assets.LoadTexture("Game Background", GAME_SCREEN_1_FILEPATH);
			this->_data->assets.LoadTexture("Next Page Image", NEXT_PAGE_FILEPATH);
			this->_data->assets.LoadTexture("Question Box Image", QUESTION_BOX);
			this->_data->assets.LoadTexture("Option Box 1 Image", OPTION_BOX);
			this->_data->assets.LoadTexture("Option Box 2 Image", OPTION_BOX);
			this->_data->assets.LoadTexture("Option Box 3 Image", OPTION_BOX);
			this->_data->assets.LoadTexture("Option Box 4 Image", OPTION_BOX);
			this->_data->assets.LoadTexture("Quit Image", QUIT_FILEPATH);

			_background.setTexture(this->_data->assets.GetTexture("Game Background"));
			_nextPage.setTexture(this->_data->assets.GetTexture("Next Page Image"));

			_optionsBox1.setTexture(this->_data->assets.GetTexture("Option Box 1 Image"));
			_optionsBox2.setTexture(this->_data->assets.GetTexture("Option Box 2 Image"));
			_optionsBox3.setTexture(this->_data->assets.GetTexture("Option Box 3 Image"));
			_optionsBox4.setTexture(this->_data->assets.GetTexture("Option Box 4 Image"));
			_questionBox.setTexture(this->_data->assets.GetTexture("Question Box Image"));
			_Quit.setTexture(this->_data->assets.GetTexture("Quit Image"));

			_questionBox.setScale(sf::Vector2f(0.20f, 0.15f));
			_optionsBox1.setScale(0.75, 0.75);
			_optionsBox2.setScale(0.75, 0.75);
			_optionsBox3.setScale(0.75, 0.75);
			_optionsBox4.setScale(0.75, 0.75);

			_questionBox.setPosition((SCREEN_WIDTH / 2) - (_questionBox.getGlobalBounds().width / 2), _questionBox.getGlobalBounds().height / 3);
			_optionsBox1.setPosition(150, 400);
			_optionsBox2.setPosition(1250, 400);
			_optionsBox3.setPosition(150, 600);
			_optionsBox4.setPosition(1250, 600);

			_background.setColor(sf::Color::White);
			_optionsBox1.setColor(sf::Color::Black);
			_optionsBox2.setColor(sf::Color::Black);
			_optionsBox3.setColor(sf::Color::Black);
			_optionsBox4.setColor(sf::Color::Black);

			_nextPage.setPosition(1500, 950);
			_Quit.setPosition(1700, 950);

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

					//this->_data->machine.AddState(StateRef(new GameState(_data)), true);
				}

				//for option 1 is clicked
				if (this->_data->input.IsSpriteClicked(this->_optionsBox1, sf::Mouse::Left, this->_data->window))
				{
					this->_data->sound.setBuffer(this->_data->buffer);
					this->_data->sound.play();
					_optionsBox1.setColor(sf::Color::Yellow);

					//go to next question
					//this->_data->machine.AddState(StateRef(new GameState(_data)), true);
				}

				//for option 2 is clicked
				if (this->_data->input.IsSpriteClicked(this->_optionsBox2, sf::Mouse::Left, this->_data->window))
				{
					this->_data->sound.setBuffer(this->_data->buffer);
					this->_data->sound.play();
					_optionsBox2.setColor(sf::Color::Yellow);
					//go to next question
					//this->_data->machine.AddState(StateRef(new GameState(_data)), true);
				}

				//for option 3 is clicked
				if (this->_data->input.IsSpriteClicked(this->_optionsBox3, sf::Mouse::Left, this->_data->window))
				{
					this->_data->sound.setBuffer(this->_data->buffer);
					this->_data->sound.play();
					_optionsBox3.setColor(sf::Color::Yellow);
					//go to next question
					//this->_data->machine.AddState(StateRef(new GameState(_data)), true);

				}

				//for option 4 is clicked
				if (this->_data->input.IsSpriteClicked(this->_optionsBox4, sf::Mouse::Left, this->_data->window))
				{
					this->_data->sound.setBuffer(this->_data->buffer);
					this->_data->sound.play();
					_optionsBox4.setColor(sf::Color::Yellow);
					//go to next question
					//this->_data->machine.AddState(StateRef(new GameState(_data)), true);

				}

				//for exiting 
				if (this->_data->input.IsSpriteClicked(this->_Quit, sf::Mouse::Left, this->_data->window))
				{
					this->_data->sound.setBuffer(this->_data->buffer);
					this->_data->sound.play();
					this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
				}

			}
		}

		void GameState::Update(float dt)
		{

		}

		void GameState::Draw(float dt)
		{
			this->_data->window.clear();

			this->_data->window.draw(this->_background);
			this->_data->window.draw(this->_questionBox);
			this->_data->window.draw(this->_nextPage);
			this->_data->window.draw(this->_optionsBox1);
			this->_data->window.draw(this->_optionsBox2);
			this->_data->window.draw(this->_optionsBox3);
			this->_data->window.draw(this->_optionsBox4);
			/*this->_data->window.draw(this->_data->text);
			this->_data->window.draw(this->_data->texts);*/
			this->_data->window.draw(this->_Quit);

			this->_data->window.display();
		}
}