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
		cout << "*\t 1) ���������� ��� ���������� � ����" << endl;
		cout << "*\t 2) ������� ������ ���������" << endl;
		cout << "*\t 3) ������� ������ ��������� �� �������" << endl;
		cout << "*\t 4) �������� ��� ����� ����� ������ �����������(����� �� �������)" << endl;
		cout << "*\t 5) �����(������� �� �������) ���������� ���������" << endl;
		cout << "*\t 6) �����(������� �� �������) ��������� �� �������" << endl;
		cout << "*\t 7) ��������� ����" << endl;
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
			cout << "������� ��� ���������, ���������� hp, ����� � �����" << endl;
			cout << "* ���: ";
			cin >> typ_of_character;
			cout << "\n* Hp: ";
			cin >> hp;
			cout << "\n* �����: ";
			cin >> armor;
			cout << "\n* ����: ";
			cin >> damage;
			addNewCharacter(game, typ_of_character, hp, armor, damage);
			cout << "\n�� ������� �������� ��������� ����.\n--> ��� ��������������:";
			game[game.getCountCharacters() - 1]->print();
		}
			break;
		case 3:
		{
			string typ_of_character;
			float hp, armor, damage;
			size_t index;
			cout << "������� ������, �� �������� ���������� �������� ���������" << endl;
			cin >> index;
			cout << "������� ��� ���������, ���������� hp, ����� � �����" << endl;
			cout << "* ���: ";
			cin >> typ_of_character;
			cout << "\n* Hp: ";
			cin >> hp;
			cout << "\n* �����: ";
			cin >> armor;
			cout << "\n* ����: ";
			cin >> damage;
			addNewCharacterInIndex(game, index, typ_of_character, hp, armor, damage);
			cout << "\n�� ������� �������� ��������� ���� �� ������� "<< index <<".\n--> ��� ��������������:";
			game[index]->print();
		}
			break;
		case 4:
		{
			if (game.getCountCharacters() < 2) {
				cout << "������� ���� ����������!\t �������� ��� ������." << endl;
				break;
			}
			cout << "������� ������� ���� ����������, ����� �������� ����� ���" << endl;
			size_t index1, index2;
			cout << "������ ������� ���������" << endl;
			cin >> index1;
			cout << "������ ������� ���������" << endl;
			cin >> index2;
			game::Character& person1 = *game[index1];
			game::Character& person2 = *game[index2];
			size_t move = 1;
			while (true)
			{
				if (!(person1.getLife() && person2.getLife())) {
					cout << "___���� �� ���������� �����___" << endl;
					break;
				}
				if (move == 1) cout << "����� ������ �������� \n" << endl;
				else if (move == 2) cout << "����� ������ �������� \n" << endl;
				else if (move == 0){
					cout << "��� ��������!" << endl;
					break;
				}
				else cout << "���-�� ����� �� ���. ��� �������." << endl;
				size_t n;
				
				cout << "1) ��������� ����������" << endl;
				cout << "2) ��������� ������ � ���������" << endl;
				cout << "3) ���������� ���������� ���������� � ���������" << endl;
				cout << "4) ��������� ���" << endl;
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
					cout << "������ ������ ���! �������� ��� ���!" << endl;
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
			cout << "�� ������� ������� ��������� �� ������� "<< game.getCountCharacters() <<".\n" << endl;
		}
			break;
		case 6:
		{
			size_t index;
			cout << "������� ������ ���������, ������� ���������� �������" << endl;
			cin >> index;
			game.deleteCharacterInIndex(index);
			cout << "�� ������� ������� ��������� �� ������� " << index << ".\n" << endl;
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