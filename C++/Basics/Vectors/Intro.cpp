#include <numeric>
#include <vector>
#include <iostream>

// https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/

// Tip for vectors in structs
#include <vector>

struct Foo {
	/*     We must use either copy initialization or list initialization.
      	 *     CTAD is not allowed (so we must explicitly specify the element type).
	 *     direct initialization not allowed for member default initializers    
	 */
	std::vector<int> v{std::vector<int>(8)};
};

int main() {
	// Value init (uses default constructor)
	std::vector<int> empty{};

	// List construction (uses list constructor)
	std::vector<int> primes{2, 3, 5, 7, 11}; // this is list init
	std::vector vowels {'a', 'e', 'i', 'o', 'u'}; // Uses CTA (C++17) to deduce
						      // element type char.
	
	std::cout << "The first prime number is: " << primes[0] << '\n';
	std::cout << "The second prime number is: " << primes[1] << '\n';

	// Arrays are contiguous in memory
	std::cout << "An int is " << sizeof(int) << " bytes\n";
	std::cout << &(primes[0]) << '\n';
	std::cout << &(primes[1]) << '\n';
	std::cout << &(primes[2]) << '\n';

	// Constructing a vector of a specific length
	std::vector<int> data(10); // vector of 10 elements, value-init to 0
				   // this is direct init
	
	// List constructors take precedence over other constructors
	// Normally, when a class type defintion matches more than one constructor
	// i.e [10] or [0,0,0,0,0,0,0,0,0,0] the match is ambiguous and a comp error results
	
	// However, in C++, a matching list constructor takes precedence.
	// tl;dr unless you want the former case, use the direct init method

	// Const and Constexpr std::vector
	const std::vector<int> prime{2, 3, 5, 7, 11};

	// One of the biggest downsides of std::vector is that it can't be a constexpr
	// if you need a constexpr array, use std::array
	
	// Quiz
	// Question 1
	std::vector hell = {1, 4, 9, 16, 25};

	// Question 3
	// std::vector<int> daily_temp(365);
	std::vector<double> daily_temp(365);

	// Question 4
	// Without std::vector
	int x,y,z;
	std::cout << "Enter 3 integers: ";
	std::cin >> x >> y >> z;
	std::cout << "The sum is: " << x+y+z;
	std::cout << "\nThe product is: " << x*y*z << std::endl;

	std::vector<int> values{x, y, z};
	std::cout << "The sum is: " << std::reduce(values.begin(), values.end());
	// This is valid for C++17 upwards. std::reduce also takes into account the type!
	// More examples can be found here: https://stackoverflow.com/questions/3221812/how-to-sum-up-elements-of-a-stdvector
	
	std::cout << "\nThe product is: " << std::accumulate(std::begin(values), std::end(values),
		       1.0, std::multiplies<int>()) << std::endl; // C++98

	// Anothr important way is:
	int multi = 1;
	for (const auto& e: values)
		multi *= e;

	std::cout << multi << std::endl;

	return 0;
}

/* Subscript out of bounds
 * operator[] doesn't do any kind of bounds checking, meaning it doesn't check to see whether
 * the index is within the bounds of 0 to N-1. Passing an invalid index to operator[] will
 * return undefined behavior.
 *
 * Arrays are one of the few container types that allow for random access, meaning any element
 * in the container can be accessed directly. Random access to array elements is typically efficient,
 * and makes arrays very easy to use. This is a primary reason why arrays are often preferred over
 * other containers.
 *
 */
