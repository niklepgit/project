#ifndef FIRESPELL
#define FIRESPELL

#include "Spell.hpp"

class FireSpell:public Spell{
	public:
		/*constructor*/
		FireSpell(string Name,int MinLevel):Spell(Name,MinLevel){}

		/*castSpell*/
		void castSpell(Monster& monster);

		/*undoSpell*/
		void undoSpell(Monster& monster){
			monster.increaseDefense(monster.undoSpellDefense-monster.getDefense());
		}

		/*destructor*/

		/*printTypeOfSpell*/
		void printTypeOfSpell(){
			cout<<"Type of Spell:FireSpell"<<endl;
		}
};

#endif