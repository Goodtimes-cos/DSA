#include <iostream>
#include <string_view>

// What is an enum? Is it similar to a struct?
// Enum is a type with a constrained set of values, a
// struct is a way to represent a thing
enum AnimalType {
	cat,
	dog,
	chicken,
};

constexpr std::string_view animalName(AnimalType type) {
	switch (type) {
		case cat: return "cat";
		case dog: return "dog";
		case chicken: return "chicken";
		default: return "";
	}
}

constexpr int numLegs(AnimalType type) {
	switch (type) {
		case cat: return 4;
		case dog: return 4;
		case chicken: return 2;
		default: return 0;
	}
}
