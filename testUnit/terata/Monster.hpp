#ifndef MONSTER
#define MONSTER

#include "Living.hpp"
//#include "../Living.hpp"


class Monster:public Living{
	protected:
		int minDamageRange;
		int maxDamageRange;
		int defense;
		int probability;
	public:
		/*Constructor*/
		Monster(string Name,int Level);

		/*Accessors*/
		int getDefense() const { return defense; }
		int getProbability() const { return probability; }
		int getMinDamageRange() const { return minDamageRange; }
		int getMaxDamageRange() const { return maxDamageRange; }

		/*Mutators*/
		void reduceDefense(int defenseToSub) { defense -= defenseToSub; }
		void reduceProbability(int probabilityToSub) { probability -= probabilityToSub; }
		void reduceDamageRange(int maxDamageToSub) { maxDamageRange -= maxDamageToSub; }

		/*Others*/
		void attackToMonster(int DamageValue);
		int generateHit();
};

#endif