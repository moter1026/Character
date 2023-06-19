#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "character/character-item.h"



game::Knight::Knight(float hp, float armor, float damage)
{
	this->_hp = hp;
	this->_armor = armor;
	this->_damage = damage;
}

float game::Knight::calculationOfDamageToOther(Character& character, float damage)
{
	return 0.0f;
}

float game::Knight::calculationOfDamageToMe(Character& character, float damage)
{
	return 0.0f;
}

bool game::Knight::ability()
{
	return false;
}

game::Assasin::Assasin(float hp, float armor, float damage)
{
	this->_hp = hp;
	this->_armor = armor;
	this->_damage = damage;
}

float game::Assasin::calculationOfDamageToOther(Character& character, float damage)
{
	return 0.0f;
}

float game::Assasin::calculationOfDamageToMe(Character& character, float damage)
{
	return 0.0f;
}

bool game::Assasin::ability()
{
	return false;
}

game::Berserk::Berserk(float hp, float armor, float damage)
{
	this->_hp = hp;
	this->_armor = armor;
	this->_damage = damage;
}

float game::Berserk::calculationOfDamageToOther(Character& character, float damage)
{
	return 0.0f;
}

float game::Berserk::calculationOfDamageToMe(Character& character, float damage)
{
	return 0.0f;
}

bool game::Berserk::ability()
{
	return false;
}
