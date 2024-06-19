#include <array>
#include <functional> // for std::reference_wrapper
#include <iostream>

struct House {
	int number{};
	int stories{};
	int roomsPerStory{};
};

int main() {
	constexpr std::array<House, 3> houses_old {
		House{13, 1, 7},
		House{14, 2, 5},
		House{15, 2, 4}
	};

	// Key insight: when init std::array with struct, class, or array, not providing the element type with
	// each init, you'll need an extra pair of braces for the compiler. This is an artifact of aggregate
	// init
	constexpr std::array<House, 3> houses {
		{
			{13,4,30},
			{14,3,10},
			{15,3,40},
		}
	};

	for (const auto& house: houses) {
		std::cout << "House number " << house.number
			  << " has " << (house.stories * house.roomsPerStory)
			  << " rooms.\n";
	}

	// References aren't objects, so you cannot make an array of refeences. The elements of an array
	// must also be assignable, and references can't be reseated.

	int x{1};
	int y{2};
	int z{3};
	
	std::array<std::reference_wrapper<int>, 3>arr{x,y,z};

	arr[1].get() = 5; // modify the object in array element 1

	std::cout << arr[1] << y << '\n';
	return 0;	
}
