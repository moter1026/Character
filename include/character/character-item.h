#include <iostream>
#include <string>
#include <vector>
#include <memory>
#pragma once

namespace game {
	class Character {
	protected:
		float _hp;
		float _armor;
		float _damage;
	public:
		Character() = default;
		virtual float calculationOfDamageToOther(Character& character, float damage) = 0;
		virtual float calculationOfDamageToMe(Character& character, float damage) = 0;
		virtual std::shared_ptr<Character> clone() const { return std::make_shared<Character>(); };
		virtual bool ability() = 0;

		float getHP() const noexcept { return this->_hp; };
		float getArmor() const noexcept { return this->_armor; };
		float getDamage() const noexcept { return this->_damage; };

		virtual ~Character() = default;
	};

	class Knight : public Character {
	public:
		Knight() = default;
		Knight(float hp, float armor, float damage);
		float calculationOfDamageToOther(Character& character, float damage)override;
		float calculationOfDamageToMe(Character& character, float damage)override;
		std::shared_ptr<Character> clone() const override { return std::make_shared<Knight>(this->_hp, this->_armor, this->_damage); };
		bool ability()override;
	};
	class Assasin : public Character {
	public:
		Assasin() = default;
		Assasin(float hp, float armor, float damage);
		float calculationOfDamageToOther(Character& character, float damage)override;
		float calculationOfDamageToMe(Character& character, float damage)override;
		std::shared_ptr<Character> clone() const override { return std::make_shared<Assasin>(this->_hp, this->_armor, this->_damage); };
		bool ability()override;
	};
	class Berserk : public Character {
	public:
		Berserk() = default;
		Berserk(float hp, float armor, float damage);
		float calculationOfDamageToOther(Character& character, float damage)override;
		float calculationOfDamageToMe(Character& character, float damage)override;
		std::shared_ptr<Character> clone() const override { return std::make_shared<Berserk>(this->_hp, this->_armor, this->_damage); };
		bool ability()override;
	};
}
