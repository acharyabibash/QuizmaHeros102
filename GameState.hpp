#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Games.hpp"

namespace Quizma
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);


	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _nextPage;
	};
}
