#include "Inventory.hpp"
#include "Hero.hpp"
#include <iostream>
using namespace std;

/*deleteArmor*/
void Inventory::deleteArmor(int number,int&Money){
	list<Armor>::iterator it;
	int counter=1;
	for(it=Armors.begin();it!=Armors.end();it++){
		if(counter==number){
			Money=it->getValue();
			it=Armors.erase(it);
			it--;
			break;
		}
		counter++;
	}
}

/*deleteSpell*/
void Inventory::deleteSpell(int number,int&Money){
	list<Spell>::iterator it;
	int counter=1;
	for(it=Spells.begin();it!=Spells.end();it++){
		if(counter==number){
			Money=it->getValue();
			it=Spells.erase(it);
			it--;
			break;
		}
		counter++;
	}
}
/*deleteWeapon*/
void Inventory::deleteWeapon(int number,int&Money,Hero& hero){
	list<Weapon>::iterator it;
	int counter=1;
	for(it=Weapons.begin();it!=Weapons.end();it++){
		if(counter==number){
			if(hero.Lhand==&(*it))
				hero.Lhand=nullptr;
			if(hero.Rhand==&(*it))
				hero.Rhand=nullptr;
			Money=it->getValue();
			it=Weapons.erase(it);
			it--;
			break;
		}
		counter++;
	}
}

/*deletePotion*/
void Inventory::deletePotion(int number,int&Money){
	list<Potion>::iterator it;
	int counter=1;
	for(it=Potions.begin();it!=Potions.end();it++){
		if(counter==number){
			Money=it->getValue();
			it=Potions.erase(it);
			it--;
			break;
		}
		counter++;
	}
}

/*printSpells*/
void Inventory::printSpells(void){
	int i=0;
	list<Spell>::iterator it;
	cout<<"Spells are:"<<endl;
	for(it=Spells.begin();it!=Spells.end();it++){ //for every spell
		cout<<"<------"<<++i<<"------>"<<endl;
		it->printSpell(); //call the print function for the spell
		cout<<endl; //leave one line empty
	}
}

/*printWeapons*/
void Inventory::printWeapons(void){
	int i=0;
	list<Weapon>::iterator it;
	cout<<"Weapons are:"<<endl;
	for(it=Weapons.begin();it!=Weapons.end();it++){ //for every weapon
		cout<<"<------"<<++i<<"------>"<<endl;
		it->printWeapon(); //call the print function for the weapon
		cout<<endl; //leave one line empty
	}
}

/*printArmors*/
void Inventory::printArmors(void){
	int i=0;
	list<Armor>::iterator it;
	cout<<"Armors are:"<<endl;
	for(it=Armors.begin();it!=Armors.end();it++){ //for every Armor
		cout<<"<------"<<++i<<"------>"<<endl;
		it->printArmor(); //call the print function for the Armor
		cout<<endl; //leave one line empty
	}
}

/*printPotions*/
void Inventory::printPotions(void){
	int i=0;
	list<Potion>::iterator it;
	cout<<"Potions are:"<<endl;
	for(it=Potions.begin();it!=Potions.end();it++){ //for every spell
		cout<<"<------"<<++i<<"------>"<<endl;
		it->printPotion(); //call the print function for the spell
		cout<<endl; //leave one line empty
	}
}

/*checkInventory*/
void Inventory::checkInventory(Hero&hero){
	int ch,ch1;

	cout<<"What do you want to see?"<<endl
		<<"1)Weapons"<<endl
		<<"2)Armors"<<endl
		<<"3)Potions"<<endl
		<<"4)Spells"<<endl;
		cin>>ch;
	switch(ch){
		case 1:printWeapons();
			   cout<<"If you  want to equip give weapon's number else 0 to exit."<<endl;
			   cin>>ch1;
			   if(ch1==0)
			    break;
			   hero.weaponEquip(ch1);
			   break;
		case 2:printArmors();
			   cout<<"If you  want to equip give armor's number else 0 to exit."<<endl;
			   cin>>ch1;
			   if(ch1==0)
			   	break;
			   hero.armorEquip(ch1);
			   break;
		case 3:printPotions();
			   cout<<"If you want to use a Potion give it's number else 0 to exit."<<endl;
			   cin>>ch1;
			   if(ch1==0)
			   	break;
			   //call use potion
			   break;
	    case 4:printSpells();
	    	   break;
	    default:cout<<"Wrong option try again."<<endl;
	    //check if you have to use break;
	}

}


/*addWeapon*/
void Inventory::addWeapon(Weapon weapon){
	Weapons.push_back(weapon);
}

/*addArmor*/
void Inventory::addArmor(Armor armor){
	Armors.push_back(armor);
}

/*addPotion*/
void Inventory::addPotion(Potion potion){
	Potions.push_back(potion);
}

/*addSpell*/
void Inventory::addSpell(Spell spell){
	Spells.push_back(spell);
}


/*addWeapon
void Inventory::addWeapon(string Name,int MinLevel){
	Weapon weapon(Name,MinLevel);
	Weapons.push_back(weapon);
}

/*addArmor
void Inventory::addArmor(string Name,int MinLevel){
	Armor armor(Name,MinLevel);
	Armors.push_back(armor);
}

/*addPotion
void Inventory::addPotion(string Name,int MinLevel,string WtIncrease){
	Potion potion(Name,MinLevel,WtIncrease);
	Potions.push_back(potion);
}

/*addSpell
void Inventory::addSpell(string Name,int MinLevel){
	Spell spell(Name,MinLevel);
	Spells.push_back(spell);
}
*/