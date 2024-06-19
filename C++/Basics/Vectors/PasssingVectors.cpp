#include <iostream>
#include <vector>

void passByRef(const std::vector<int>& arr) { // we must explicitly specify <int> here
	std::cout << arr[0] << '\n';
}

template <typename T>
void passByRef(const std::vector<T>& arr) {
	std::cout << arr[0] << '\n';
}

// We can also create a function template that will accept any type of object:
template <typename T>
void passByRef(const T& arr) {
	// If you need to assert the size of the array, you can check that using .size()
	// A better option would be to avoid using std::vector in cases where you need to assert
	// array length, and use a type that supports constexpr instead, like std::array
	std::cout << arr[0] << '\n';
}

int main() {
	std::vector primes{2,3,5,7,11};
	passByRef(primes);

	std::vector dbl{1.1, 2.2, 3.3};
	// passByRef(dbl); compile error, as double not convertible to std::vector<int>
	// suppose we want to automatically determine the type? In c++17 or newer, we can!
	passByRef(dbl);

	return 0;
}

/* In C++, we can create overloaded functions with the same implementation for each set of parameter
 * types we want to support is a maintenance headache, and violates DRY principle.
 *
 * The template system was designed to simplify the process of creating functions that are able
 * to work with different data types.
 *
 * "A template is a model that serves as a pattern for creating similar objects"
 *
 * C++ supports 3 different kinds of template parameters:
 * 	- Type template parameters,
 * 	- Non-type template parameters,
 * 	- Template template parameters --> BY FAR THE MOST COMMON
 *
 */
