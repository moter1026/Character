#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>
#include "character/character-item.h"


int game::GetRandomNumber(int min, int max) {
// Установить генератор случайных чисел
srand(time(NULL));

// Получить случайное число - формула
int num = min + rand() % (max - min + 1);

return num;
}


game::Knight::Knight(float hp, float armor, float damage)
{
	this->_hp = hp;
	this->_armor = armor;
	this->_damage = damage;
	this->_life = true;
}

float game::Knight::calculationOfDamageToOther()
{
	return this->_damage;
}

float game::Knight::calculationOfDamageToMe(Character& character, float damage)
{
	if (game::GetRandomNumber(0, 100) >= 100 - this->_probabilityMinimizeDamage) {
		return damage / 2;
		std::cout << "Сработало пассивное умение. Полученный урон уменьшен вдвое!" << std::endl;
	}
	return damage;
}

bool game::Knight::ability()
{
	if (this->_countAfterAbility == 0)
	{
		++(this->_countAfterAbility);
		this->_armor *= 2;
		this->_damage *= 0.85;
		return true;
	}
	//std::cout << "Данный персонаж не может применять своё умение больше 1 раза" << std::endl;
	else if (this->_countAfterAbility == 2) {
		this->_countAfterAbility = 0;
		return false;
	}
	++(this->_countAfterAbility);
	return false;
}

float game::Knight::attack()
{
	/*int abil;
	std::cout << "Если хотите применить `умение` персонажа, нажмите 1, в противном случае отличное от 1 число";
	std::cin >> abil;
	if (abil == 1)this->ability();*/
	return game::Knight::calculationOfDamageToOther();
}

void game::Knight::getAttack(game::Character& character, float damage)
{	
	if		(this->_armor > 0 && damage <= this->_armor)	this->_armor -= damage;
	else if (this->_armor > 0 && damage >= this->_armor) {	this->_hp += this->_armor - damage; 
															this->_armor = 0; }
	else if (this->_armor == 0 && this->_hp > damage)		this->_hp -= damage;
	else if (this->_armor == 0 && this->_hp <= damage) {	this->_hp = 0;
															this->_life = false; }
}

void game::Knight::print()
{
	std::cout << std::endl;
	std::cout<< "\t-Рыцарь-" << std::endl;
	std::cout<< "->\tЗдоровья:" << this->_hp << std::endl;
	std::cout<< "->\tЩит:" << this->_armor << std::endl;
	std::cout<< "->\tНаносимый урон:" << this->_damage << std::endl;
	std::cout<< "->\tУмение было применено " <<this->_countAfterAbility<< " хода назад" << std::endl;
	std::cout<< std::endl;
}

game::Assasin::Assasin(float hp, float armor, float damage)
{
	this->_hp = hp;
	this->_armor = armor;
	this->_damage = damage;
	this->_life = true;
}

float game::Assasin::calculationOfDamageToOther()
{
	return this->_damage;
}

float game::Assasin::calculationOfDamageToMe(Character& character, float damage)
{
	if (game::GetRandomNumber(0, 100) >= 100 - this->_probabilityDodge) {
		return 0;
		std::cout << "*\tСработало пассивное умение. Вы увернулись от атаки!" << std::endl;
	}
	return damage;
}

bool game::Assasin::ability()
{
	if (this->_countAfterAbility == 0)
	{
		++(this->_countAfterAbility);
		return true;
	}
	else if (this->_countAfterAbility == 2) {
		this->_countAfterAbility = 0;
		return false;
	}
	++(this->_countAfterAbility);
	return false;
}

float game::Assasin::attack()
{
	return game::Assasin::calculationOfDamageToOther();
}

void game::Assasin::getAttack(game::Character& character, float damage)
{
	if (this->_armor > 0 && damage <= this->_armor)	this->_armor -= damage;
	else if (this->_armor > 0 && damage >= this->_armor) {
		this->_hp += this->_armor - damage;
		this->_armor = 0;
	}
	else if (this->_armor == 0 && this->_hp > damage)		this->_hp -= damage;
	else if (this->_armor == 0 && this->_hp <= damage) {
		this->_hp = 0;
		this->_life = false;
	}
}

void game::Assasin::print()
{
	std::cout << std::endl;
	std::cout << "\t-Ассасин-" << std::endl;
	std::cout << "->\tЗдоровья:" << this->_hp << std::endl;
	std::cout << "->\tЩит:" << this->_armor << std::endl;
	std::cout << "->\tНаносимый урон:" << this->_damage << std::endl;
	std::cout << "->\tУмение было применено " << this->_countAfterAbility << " хода назад" << std::endl;
	std::cout << std::endl;
}

game::Berserk::Berserk(float hp, float armor, float damage)
{
	this->_hp = hp;
	this->_armor = armor;
	this->_damage = damage;
	this->_life = true;
}

float game::Berserk::calculationOfDamageToOther()
{
	if (game::GetRandomNumber(0, 100) >= 100 - this->_probability3XDamage) {
		return this->_damage * 3;
		std::cout << "*\tСработало пассивное умение. Вы нанесли в три раза больше урона!" << std::endl;
	}
	return this->_damage;
}

float game::Berserk::calculationOfDamageToMe(Character& character, float damage)
{
	return damage;
}

bool game::Berserk::ability()
{
	if (this->_countAfterAbility == 0)
	{
		++(this->_countAfterAbility);
		this->_damage *= 1.1;
		this->_armor *= 0.85;
		//Сделаю вероятность утроенного урона ещё меньше при применении умкения
		if (game::GetRandomNumber(0, 100) >= 100 - this->_probability3XDamage + 5) {
			return this->_damage * 3;
			std::cout << "*\tСработало пассивное умение. Вы нанесли в три раза больше урона!" << std::endl;
		}
		return true;
	}
	//std::cout << "Данный персонаж не может применять своё умение больше 1 раза" << std::endl;
	else if (this->_countAfterAbility == 2) {
		this->_countAfterAbility = 0;
		return false;
	}
	++(this->_countAfterAbility);
	return false;
}

float game::Berserk::attack()
{
	return  game::Berserk::calculationOfDamageToOther();
}

void game::Berserk::getAttack(game::Character& character, float damage)
{
	if (this->_armor > 0 && damage <= this->_armor)	this->_armor -= damage;
	else if (this->_armor > 0 && damage >= this->_armor) {
		this->_hp += this->_armor - damage;
		this->_armor = 0;
	}
	else if (this->_armor == 0 && this->_hp > damage)		this->_hp -= damage;
	else if (this->_armor == 0 && this->_hp <= damage) {
		this->_hp = 0;
		this->_life = false;
	}
}

void game::Berserk::print()
{
	std::cout << std::endl;
	std::cout << "\t-Берсерк-" << std::endl;
	std::cout << "->\tЗдоровья:" << this->_hp << std::endl;
	std::cout << "->\tЩит:" << this->_armor << std::endl;
	std::cout << "->\tНаносимый урон:" << this->_damage << std::endl;
	std::cout << "->\tУмение было применено " << this->_countAfterAbility << " хода назад" << std::endl;
	std::cout << std::endl;
}


