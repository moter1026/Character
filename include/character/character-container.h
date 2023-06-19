#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "character-item.h"
#pragma once


namespace game {
	class Game {
	private:
		std::vector<std::shared_ptr<game::Character>> _all_character;
	public:
		Game();
		Game(game::Game& cont);
		float getCountCharacters() const noexcept;
		void setCharacter();
		void setCharacterInIndex();
		void deleteCharacter();
		game::Character& operator[](size_t index);
	};
}