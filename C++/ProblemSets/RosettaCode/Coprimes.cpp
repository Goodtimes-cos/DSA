#include <iostream>
#include <utility>
#include <vector>

int gcd(int x, int y) { // Euclid's algorithm
	if (x > y) {
		return gcd(x-y, y);
	} else if (y > x) {
		return gcd(x, y-x);
	} else {
		return y;
	}
}

int main() {
	typedef std::pair<int, int> IntPair; // typedef allows you to define a new name for an
					   // existing datatype 
	
	// Interesting way to insert things into C++ vectors!
	std::vector<IntPair> pairs;
	pairs.push_back(std::make_pair(21, 15));

	pairs.insert(pairs.end(), {std::make_pair(17,23), std::make_pair(36,12), std::make_pair(18, 29),
			std::make_pair(60, 15)});
	
	std::cout << "Pair (21, 15): " << gcd(std::get<0>(pairs[0]), std::get<1>(pairs[0])) << '\n';
	std::cout << "Pair (17, 23): " << gcd(std::get<0>(pairs[1]), std::get<1>(pairs[1])) << '\n';
	std::cout << "Pair (36, 12): " << gcd(std::get<0>(pairs[2]), std::get<1>(pairs[2])) << '\n';
	std::cout << "Pair (18, 29): " << gcd(std::get<0>(pairs[3]), std::get<1>(pairs[3])) << '\n';
	std::cout << "Pair (60, 15): " << gcd(std::get<0>(pairs[4]), std::get<1>(pairs[4])) << '\n';

	return 0;
}

// For the greatest common divisor, we can either use
// 	- Euclid's algorithm
// 	- Euclidean algorithm
