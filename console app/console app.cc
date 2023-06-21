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
		cout << "*\t 1) ���������� ��� ���������� � ���" << endl;
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
			break;
		case 5:
		{
			game.deleteCharacter();
			cout << "�� ������� ������� ��������� �� ������� "<< game.getCountCharacters() <<".\n" << endl;
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