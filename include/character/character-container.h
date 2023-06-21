#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "character-item.h"
#pragma once

namespace game {
	using itemCharacter = std::shared_ptr<game::Character>;

	class Game {
	private:
		std::vector<itemCharacter> _all_character;
		std::string _name_of_game;
	public:
		//Game() = default;
		Game(std::string nameOfGame);
		std::string getNameOfGame() const noexcept;
		int getCountCharacters() const noexcept;
		void setCharacter(itemCharacter character);
		void setCharacterInIndex(size_t index, itemCharacter character);
		void deleteCharacter();
		void deleteCharacterInIndex(size_t index);
		itemCharacter operator[](size_t index);
	};
	std::ostream& operator <<(std::ostream& stream, game::Game& game);
	
}