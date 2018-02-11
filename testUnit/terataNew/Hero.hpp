#ifndef HERO
#define HERO

//#include "../Living.hpp"
#include "Living.hpp"
#include "Inventory.hpp"
#include <list>
using namespace std;

class Hero:public Living{
	private:
		int currMagicPower;
		int maxMagicPower;
		int strength;
		int dexterity;
		int agility;
		int money;
		int experience;
	
	public:
		Weapon *Rhand;
		Weapon *Lhand;
		Armor *MyArmor;
		Spell *MySpell;
		Inventory inventory;

	public:
		/*constructor*/
		Hero(string,int,int,int);

		/*Accessors*/
		int getCurrMagicPower() const { return currMagicPower; }
		int getMaxMagicPower() const { return maxMagicPower; }
		int getStrength() const { return strength; }
		int getDexterity() const { return dexterity; }
		int getAgility() const { return agility; }
		int getMoney() const { return money; }
		int getExperience() const { return experience; }
		void printHero() const;


		/*Mutators*/
		void levelUp();
		void reduceMagicPower(int magicPowerToSub) { currMagicPower -= magicPowerToSub; }
		void updateExperience(int experienceGained) { experience += experienceGained; }
		void reduceMoney(int moneyLosted) { money -= moneyLosted; }
		void increaseMoney(int moneyGained) { money += moneyGained; }
		void increaseMagicPower(int);
		void increaseStrength(int strengthToIncrease) { strength += strengthToIncrease; }
		void increaseDexterity(int dexterityToIncrease) { dexterity += dexterityToIncrease; }
		void increaseAgility(int agilityToIncrease) { agility += agilityToIncrease; }
		virtual void increaseAttributes(){}

		void regenerateHealthPowerAfterLosing(void);
		void reduceMoneyAfterLosing(void);
		void attackToHero(int DamageValue);
		void weaponEquip(int position);
		void armorEquip(int position);
		void regenerateMagicPowerAfterRound(int round);

		void findAndUsePotion(int position);
		void spellEquip(int position);
};

#endif