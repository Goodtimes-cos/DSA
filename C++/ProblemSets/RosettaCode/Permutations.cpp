#include <algorithm>
#include <iostream>
#include <string>

// Experiment of permutations!
// https://en.cppreference.com/w/cpp/algorithm/prev_permutation
// https://en.cppreference.com/w/cpp/algorithm/next_permutation
int main() {
	std::string s = "12345";

	do {
		std::cout << s << ' ';
	} while (std::prev_permutation(s.begin(), s.end()));
	// while(std::next_permutation(s.begin(), s.end()));
	std::cout << s << '\n';
	return 0;
}
