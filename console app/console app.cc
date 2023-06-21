#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>
#include <windows.h>
#include "character/character-item.h"
#include "character/character-container.h"

using namespace std;

void addNewCharacter(game::Game& game, string character, float hp, float armor, float damage) {
	if (_stricmp("knight",character.c_str()) == 0)
	{
		game.setCharacter(std::make_shared<game::Knight>(hp, armor, damage));
	}
	else if (_stricmp("assasin", character.c_str()) == 0)
	{
		game.setCharacter(std::make_shared<game::Assasin>(hp, armor, damage));
	}
	else if (_stricmp("berserk", character.c_str()) == 0)
	{
		game.setCharacter(std::make_shared<game::Berserk>(hp, armor, damage));
	}
}
void addNewCharacterInIndex(game::Game& game, size_t index, string character, float hp, float armor, float damage) {
	if (_stricmp("knight",character.c_str()) == 0)
	{
		game.setCharacterInIndex(index, std::make_shared<game::Knight>(hp,armor, damage));
	}
	else if (_stricmp("assasin", character.c_str()) == 0)
	{
		game.setCharacterInIndex(index, std::make_shared<game::Assasin>(hp, armor, damage));
	}
	else if (_stricmp("berserk", character.c_str()) == 0)
	{
		game.setCharacterInIndex(index, std::make_shared<game::Berserk>(hp, armor, damage));
	}
}

void mainMenu(game::Game game) {
	size_t item_menu;
	while (true)
	{
		cout << "*\t 1) Посмотреть всю информацию о игр" << endl;
		cout << "*\t 2) Создать нового персонажа" << endl;
		cout << "*\t 3) Создать нового персонажа по индексу" << endl;
		cout << "*\t 4) Устроить бой между двумя живыми персонажеми(выбор по индексу)" << endl;
		cout << "*\t 5) Убить(удалить из массива) последнего персонажа" << endl;
		cout << "*\t 6) Убить(удалить из массива) персонажа по индексу" << endl;
		cout << "*\t 7) завершить игру" << endl;
		cout << endl;
		cin >> item_menu;
		switch (item_menu)
		{
		case 1:
			cout << game << endl;
			break;
		case 2:
		{
			string typ_of_character;
			float hp, armor, damage;
			cout << "Введите тип персонажа, количество hp, брони и урона" << endl;
			cout << "* Тип: ";
			cin >> typ_of_character;
			cout << "\n* Hp: ";
			cin >> hp;
			cout << "\n* Броня: ";
			cin >> armor;
			cout << "\n* Урон: ";
			cin >> damage;
			addNewCharacter(game, typ_of_character, hp, armor, damage);
			cout << "\nВы успешно добавили персонажа игры.\n--> Его характеристики:";
			game[game.getCountCharacters() - 1]->print();
		}
			break;
		case 3:
		{
			string typ_of_character;
			float hp, armor, damage;
			size_t index;
			cout << "Введите индекс, по которому необходимо вставить персонажа" << endl;
			cin >> index;
			cout << "Введите тип персонажа, количество hp, брони и урона" << endl;
			cout << "* Тип: ";
			cin >> typ_of_character;
			cout << "\n* Hp: ";
			cin >> hp;
			cout << "\n* Броня: ";
			cin >> armor;
			cout << "\n* Урон: ";
			cin >> damage;
			addNewCharacterInIndex(game, index, typ_of_character, hp, armor, damage);
			cout << "\nВы успешно добавили персонажа игры по индексу "<< index <<".\n--> Его характеристики:";
			game[index]->print();
		}
			break;
		case 4:
			break;
		case 5:
		{
			game.deleteCharacter();
			cout << "Вы успешно удалили персонажа по индексу "<< game.getCountCharacters() <<".\n" << endl;
		}
			break;
		case 6:
			break;
		case 7:
			return;
			break;
		default:
			break;
		}
	}
	
}

int main() {
	try
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		string name_of_game = "Me-e-e-ga FIGHT";
		mainMenu(game::Game(name_of_game));
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
	return 0;
}