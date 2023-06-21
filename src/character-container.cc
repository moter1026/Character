#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "..\include\character\character-item.h"
#include "..\include\character\character-container.h"


game::Game::Game(std::string nameOfGame)
{
	this->_name_of_game = nameOfGame;
}

std::string game::Game::getNameOfGame() const noexcept
{
	return this->_name_of_game;
}



int game::Game::getCountCharacters() const noexcept
{
	return this->_all_character.size();
}

void game::Game::setCharacter(itemCharacter character) {
	this->_all_character.insert(this->_all_character.end(), character);
}

void game::Game::setCharacterInIndex(size_t index, itemCharacter character)
{
	this->_all_character.insert(this->_all_character.begin() + index,
		character);
}

void game::Game::deleteCharacter()
{
	this->_all_character.erase(this->_all_character.begin() + this->_all_character.size() - 1);
}
void game::Game::deleteCharacterInIndex(size_t index)
{
	this->_all_character.erase(this->_all_character.begin() + index);

}
game::itemCharacter game::Game::operator[](size_t index)
{
	return this->_all_character.at(index); 
}

std::ostream& game::operator <<(std::ostream& stream, game::Game& game) {
	stream << "--->Название игры: " << game.getNameOfGame() << "\n\n";
	stream << "Персонажи игры: " << std::endl;
	int size = game.getCountCharacters();
	for (size_t i = 0; i < size; i++)
	{
		stream << "Index: " << i << std::endl;
		game[i]->print();
	}
	return stream;
}