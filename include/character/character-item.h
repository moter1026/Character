#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h> // нужен для вызова функции time()
#pragma once

namespace game {
	int GetRandomNumber(int min, int max);

	class Character {
	protected:
		float _hp;
		float _armor;
		float _damage;
		bool _life;
		int _countAfterAbility = 0;
		bool _ability = false;
		virtual float calculationOfDamageToOther() = 0;
		virtual float calculationOfDamageToMe(Character& character, float damage) = 0;
	public:
		virtual bool ability() = 0;
		virtual float attack() = 0;
		bool getLife() { return this->_life; };
		virtual void getAttack(game::Character& character, float damage) = 0;
		virtual void print() = 0;

		float getHP() const noexcept { return this->_hp; };
		float getArmor() const noexcept { return this->_armor; };
		float getDamage() const noexcept { return this->_damage; };

		virtual ~Character() = default;
	};

	class Knight : public Character {
	private:
		int _probabilityMinimizeDamage = 35;
		float _old_damage;
	public:
		Knight() = default;
		Knight(float hp, float armor, float damage);

		float calculationOfDamageToOther()override;
		float calculationOfDamageToMe(Character& character, float damage)override;

		std::shared_ptr<Character> clone() const  { return std::make_shared<Knight>(this->_hp, this->_armor, this->_damage); };

		bool ability() override;
		float attack() override;
		void getAttack(game::Character& character, float damage) override;
		void print()override;
	};
	class Assasin : public Character {
	private:
		int _probabilityDodge = 20;
	public:
		Assasin() = default;
		Assasin(float hp, float armor, float damage);

		float calculationOfDamageToOther()override;
		float calculationOfDamageToMe(Character& character, float damage)override;
		
		std::shared_ptr<Character> clone() const  { return std::make_shared<Assasin>(this->_hp, this->_armor, this->_damage); };
		
		bool ability()override;
		float attack() override;
		void getAttack(game::Character& character, float damage) override;
		void print()override;
	};
	class Berserk : public Character {
	private: 
		float _old_damage;
		//float _old_armor;
		int _probability3XDamage = 10;
	public:
		Berserk() = default;
		Berserk(float hp, float armor, float damage);

		float calculationOfDamageToOther()override;
		float calculationOfDamageToMe(Character& character, float damage)override;
		
		std::shared_ptr<Character> clone() const  { return std::make_shared<Berserk>(this->_hp, this->_armor, this->_damage); };
		
		bool ability()override;
		float attack() override;
		void getAttack(game::Character& character, float damage) override;
		void print()override;
	};
}
