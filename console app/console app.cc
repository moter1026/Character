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
		cout << "*\t 1) Посмотреть всю информацию о игре" << endl;
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
		{
			if (game.getCountCharacters() < 2) {
				cout << "Слишком мало персонажей!\t добавьте ещё героев." << endl;
				break;
			}
			cout << "Введите индексы двух персонажей, между которыми будет бой" << endl;
			size_t index1, index2;
			cout << "Индекс первого персонажа" << endl;
			cin >> index1;
			cout << "Индекс второго персонажа" << endl;
			cin >> index2;
			game::Character& person1 = *game[index1];
			game::Character& person2 = *game[index2];
			size_t move = 1;
			while (true)
			{
				if (!(person1.getLife() && person2.getLife())) {
					cout << "___Один из персонажей погиб___" << endl;
					break;
				}
				if (move == 1) cout << "Ходит первый персонаж \n" << endl;
				else if (move == 2) cout << "Ходит второй персонаж \n" << endl;
				else if (move == 0){
					cout << "Бой закончен!" << endl;
					break;
				}
				else cout << "Что-то пошло не так. Бой окончен." << endl;
				size_t n;
				
				cout << "1) атаковать противника" << endl;
				cout << "2) применить умение и атаковать" << endl;
				cout << "3) посмотреть актуальную информацию о персонаже" << endl;
				cout << "4) закончить бой" << endl;
				cin >> n;
				switch (n)
				{
				case 1:
				{
					if (move == 1)
					{
						float damage_to_other = person1.attack();
						person2.getAttack(person1, damage_to_other);
					}
					else if (move == 2)
					{
						float damage_to_other = person2.attack();
						person1.getAttack(person2, damage_to_other);
					}
				}
					break;
				case 2:
				{
					if (move == 1)
					{
						person1.ability();
						float damage_to_other = person1.attack();
						person2.getAttack(person1, damage_to_other);
					}
					else if (move == 2)
					{
						person2.ability();
						float damage_to_other = person2.attack();
						person1.getAttack(person2, damage_to_other);
					}
				}
					break;
				case 3:
				{
					if (move == 1)
					{
						person1.print();
					}
					else if (move == 2)
					{
						person2.print();
					}
					continue;
				}
					break;
				case 4:
				{
					move = 0;
				}
					break;
				default:
					cout << "Такого пункта нет! Выберите ещё раз!" << endl;
					break;
				}

				if (move == 1) {
					++move;
				}
				else if (move == 2) {
					--move;
				}
			}
		}
			break;
		case 5:
		{
			game.deleteCharacter();
			cout << "Вы успешно удалили персонажа по индексу "<< game.getCountCharacters() <<".\n" << endl;
		}
			break;
		case 6:
		{
			size_t index;
			cout << "Введите индекс персонажа, который необходимо удалить" << endl;
			cin >> index;
			game.deleteCharacterInIndex(index);
			cout << "Вы успешно удалили персонажа по индексу " << index << ".\n" << endl;
		}
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