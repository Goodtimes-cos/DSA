#include <iostream>

// `this` represents a pointer to the object whose member function is being executed. It's
// used within a class's member function to refer to the object itself.

// A static data member of a class, otherwise known as "class variable", has only one common variable
// for all the objects of that same class

// Static variables have the same properties as non-member variables, but they enjoy class scope.

class Pokemon {
	public:
		int hp;
		Pokemon(int init_hp): hp(init_hp) {}
		bool isitme(Pokemon& param);
};

bool Pokemon::isitme(Pokemon& param) {
	if (&param == this) return true;
	else return false;
}

int main() {
	const Pokemon pikachu(10);
	// pikachu.hp = 20; -> not valid, cannot modify data members
}
