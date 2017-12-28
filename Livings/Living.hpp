#ifndef LIVING
#define LIVING

#include <string>

class Living{
	private:
		string name;
		int level;
		int healthPower;

	public:
		/*constructor*/
		Living(string Name);

		// Accessors
		int getLevel() const { return level; }

		// Mutators
		void levelUp() { level++; }

};

#endif