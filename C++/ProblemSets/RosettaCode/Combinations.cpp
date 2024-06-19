#include <iostream>
#include <vector>
// Imports from comb
#include <algorithm>
#include <string>

// Passing by value, horrifically inefficient!
void gen_combinatorials_myversion(std::vector<int> nums, int n, int k) {
	if (n == k) {
		for (int i=0; i < n; i++) {
			std::cout << nums[i];
		}
		std::cout << '\n';
	} else {
		// Partial solution!
		for (int i=0; i<n; i++) {
			std::vector<int> new_nums = nums;
			// Generating new vector, horrifically inefficient!
		     	new_nums.erase(new_nums.begin() + i);	
			gen_combinatorials_myversion(new_nums, n-1, k);
		}
	}
}

/* So at the moment we try to generate almost a tree, i.e
 * 			  1 2 3 4
 * 		1 2 3	   1 3 4          1 2 4
 * 	23   13    12   34   14   13    24  14  12
 *
 * 	But, this generates duplicates. It's also extremely inefficient from an implementation
 * 	standpoint!
 *
 *
 */

// This is the version found on Rosetta code

void comb(int N, int K) {
	std::string bitmask(K, 1); // Initializes a string bitmask of length K, comprised of 1s?
				   // Note, not the char '1'
	std::cout << bitmask; // Why can't I print this shit?
	bitmask.resize(N, 0); // Resizes the string to be of size N, filling any gaps with the
			      // char 0
	// std::cout << bitmask;
	
	do {
		for (int i=0; i<N; ++i) {
			if (bitmask[i]) std::cout << " " << i; // (i.e if we have a 1?)
		}
		std::cout << std::endl;
	} while (std::prev_permutation(bitmask.begin(), bitmask.end()));
	// The main bit I assume, transforms the range [first, last) into the previous
	// permutation. Returns true if such permutation exists, otherwise transforms range into
	// the last permutation (like std::sort followed by std::reverse) and returns false 
}

// This is another version which seems to be a drastic improvement on my inital attempt
//
// To get all K-element combinations, you first pick initial element with all possible
// combinations of K-1 people produced from elements that succeed the initial element
//
std::vector<int> people;
std::vector<int> combination;

void pretty_print(const std::vector<int>& v) {
	static int count = 0;
	std::cout << "combination no " << (++count) << ": [ ";
	for (int i=0; i < v.size(); ++i) { std::cout << v[i] << " "; }
	std::cout << "] " << std::endl;
}

void go(int offset, int k) {
	if (k == 0) {
		pretty_print(combination);
		return;
	}
	for (int i = offset; i <= people.size() - k; ++i) {
		combination.push_back(people[i]); // push_back -- adds an element to the end
		go(i+1, k-1);
		combination.pop_back(); // pop_back -- removes the last element
	}
}

int main() {
	// Ok, so we need to generate all combinations
	int n, k;
	std::cout << "Please enter the number of objects (n)\n"; // Cannot use endl with cin
				            			 // directly after, why?
	std::cin >> n;
	std::cout << "Please enter the sample size (k)\n";
	std::cin >> k;

	/*
	std::vector<int> numbers; // Using vectors in the first place, likely inefficient
	for (int i=0; i<n; i++) {
		numbers.insert(numbers.begin() + i, i);
	}
	*/

	// gen_combinatorials_myversion(numbers, n, k);
	// comb(5, 3);
	int N=5, K=3;
	for (int i=0; i<N; ++i) {
		people.push_back(i+1);
	}
	go(0, K);

	return 0;	
}

// Ok, so I found two good solutions

/*
https://stackoverflow.com/questions/12991758/creating-all-possible-k-combinations-of-n-items-in-c
*/
