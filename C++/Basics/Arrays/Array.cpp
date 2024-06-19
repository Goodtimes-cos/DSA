/* An array is a composite data type whose indicies are totally ordered, of uniform type, and
 * fixed size.
 *
 * The implementation of arrays is based on setting the bounds of indicies of the array, the size of the
 * array, normally by allocating a contiguous region of memory to hold the elements of the array, and
 * using simple offset calculations on the indices from the origin of the memory to access memory
 * elements.
 *
 * By contract, an associative array maps the association between index "keys" and their associated
 * values, generally using more complex hash functions on the keys of the array to map them to their
 * corresponding elements.
 *
 * Non-associative arrays may have speed and memory consumption advantages. Associate arrays have
 * greater flexibility in types used for keys.
 *
 * Common operations:
 * 	- Indexing,
 * 	- Slicing,
 * 	- Iteration over elemets,
 * 	- Iteration over associative array,
 * 	- Querying the bounds of array indices,
 * 	- Querying the indices of an associative array,
 * 	- Operations on indices,
 * 	- Sorting the contents of the array to satisy some relationship,
 * 	- Searching an array for the location of some value.
 *
 * In C++, containers provide storage for a collection of elements. Arrays allocate their elements
 * contiguously in memory, and allow fast, direct access. We've already covered std::vector, so let's look
 * into std::array and C-style arrays
 *
 * Why not use dynamic arrays for everything?
 * 	- Slightly less performant than the fixed-size arrays. In most cases, you probably won't
 * 	notice the difference,
 * 	- Only supports constexpr in limited contexts.
 *
 * When to use each? If I want to store an array of data as a member of an object, I use
 * 	- std::array if I want it to live in the object itself,
 * 	- std::vector if I want to guarantee it's heap-allocated or dynamic,
 * 	- C-style arrays if I need a quick couple objects on the stack to pass
 * 	to a function using a pointer
 */

// std::array works similarly to std::vector, but have differences
#include <array>
#include <vector>
#include <iostream>
#include <limits>

/* Nice things about this method:
 * 	- It uses the most conventional way to return data to the caller,
 * 	- It's obvious that the function is returning a value,
 * 	- We can define an array and use the function to init it in a single statement
 * 	------------------------------------------------------------------------------
 * 	- The function returns a copy of the array and all its elements, which isn't
 * 	cheap
 * 	- When we call the function, we must explicitly supply the template arguments
 * 	since there is no parameter to deduce them from.
 */
template <typename T, std::size_t N>
std::array<T, N> inputArray();

template <typename T, std::size_t N>
void refInputArray(std::array<T, N>& arr);

// CTAD doesn't currently work with function parameters, so we cannot just specify std::array here
// and let the compiler deduce the template arguments
void passByRef(const std::array<int, 5>& arr) {
	std::cout << arr[0] << '\n';
}

// We may use function templates to pass std::array of different element types or lengths
// template <typename T, std::size_t N> // not that this template parameter declaration matches the one for
				     // std::array
template <typename T, auto N>
void altPassByRef(const std::array<T, N>& arr) {
	static_assert(N != 0); // fail if this is a zero-length std::array
	
	std::cout << arr[0] << '\n';
}

int main() {
	std::array<int, 5> a {}; // preferred way as int elements are 0 initialized
	std::vector<int> b12(5);

	constexpr int len {8};
	std::array<int, len> b {}; // using a constexpr variable
	
	enum Colors {
		red,
		green,
		blue,
		max_colours
	};

	std::array<int, max_colours> c {}; // using an enumerator
	
	// arrays length cannot be defined via a non-const variable, nor runtime constants (i.e cin)
	
	/* std::array can be defined with a length of 0;
	 */

	// Aggregate init of a std::array
	std::array<int, 6> fibo {0, 1, 1, 2, 3, 5};

	// An std::array can be const or constexpr, though it's best to define as constexpr whenever
	// possible. If it's not, consider using a std::vector instead
	
	// Using CTAD, we can have the compiler deduce both the element type and the array length of a
	// std::array from a list of inits
	
	constexpr std::array a1 {9,7,5,3,1};
	
	// best practice: use class template argument deducation (CTAD) to have the compiler deduce the
	// type and length of a std::array from its initializers
	
	// in C++20, you can use std::to_array helper function to omit the length in the init, though
	// this is more expensive, as it involves the creation of a temporary std::array, so
	// should only be used in cases where the type cannot be effectively determined for inits
	
	constexpr auto myArray3 {std::to_array({9,7,5,3,1})}; // Deduce type and size
	
	constexpr std::array<int, 5> prime{2,3,5,7,11};
	std::cout << prime[3] << '\n';
	std::cout << prime[9] << '\n';

	// std::array length and indexing
	// unfortunately, the standard library containers classes use unsigned values for lengths
	// and indices. As std::array is a standard library container class, it's subject to the
	// same issues
	//
	// std::array is implemented as a template struct whose declaration looks like:
	// 	template<typename T, std::size_t N> // N is a non-type template parameter
	// 	struct array;

	// See class templates and non-type template parameters
	// How to get the length of a std::array
	
	// C++17 type and length assumption!
	constexpr std::array arr {9.0, 7.2, 5.4, 3.6, 1.8};
	std::cout << "length: " << arr.size() << '\n'; // returns length as unsigned size_type

	// unlike std::string and std::string_view, which have both a length() and size() member
	// function, std::array (and most other container types in C++) only have size().
	
	// In C++17, we can use std::size(), which returns the length as unsigned size_type
	std::cout << "length: " << std::size(arr) << '\n';

	// Finally, in C++20, we can use the std::ssize() non-member function, which returns the
	// length as a large signed integral type (usually std::ptrdiff_t)
	
	std::cout << "length: " << std::ssize(arr) << '\n';

	// Why use signed over unsigned in C++?
	/* It's shorter,
	 * It's more generic and more intuitive (i.e 1-2 = -1 not some obscure huge number),
	 * What if I want to signal an error by returning an out-of-range value?
	 */

	constexpr int length{std::size(arr)}; // ok: return value is constexpr std::size_t
					      // and can be converted to int, not a narrowing
					      // conversion

	// Warning: due to a language defect, the above functions will return a non-constexpr value when
	// called on std::array function parameter passed by (const) reference
	//
	// The defect has been addressed in C++23 by P2280, where the workaround is to make the 
	// fnction a function template where the array length is a non-type template parameter

	// To get compile-time bounds checking when we have a constexpr index, we can use the std::get()
	// function template, which takes the index as a non-type template argument:
	
	const std::array prime_2{2,3,5,7,11};
	std::cout << std::get<3>(prime_2) << '\n';
	// std::cout << std::get<9>(prime_2); returns an error

	// An std::array object can be passed to a function like any other.
	passByRef(prime);

	std::array lol{'l','o','l'};
	altPassByRef(lol);

	std::array<int, 0> lol2;
	//altPassByRef(lol2);
	
	// Always be careful to match the ono-type template parameters!
	/* In C++, we can avoid the pain of looking up the type of a non-template parameter using auto!
	 */

	/* How do we ensure that the array passed to the function is of the correct size?
	 * Simple, we may either use:
	 * 	- Assert and static_assert
	 * 	- std::get()
	 */

	// Returning a std::array
	std::array<int, 5> arr_ref{};
       	refInputArray(arr_ref);

	std::cout << "The value of element 2 is " << arr_ref[2] << '\n';

	return 0;
}

/* Returning by value is ok if:
 * 	- The array isn't huge,
 * 	- The element type is cheap to copy (or move),
 * 	- The code isn't being used in a performance-sensitive context.
 */
template <typename T, std::size_t N>
std::array<T, N> inputArray() {
	std::array<T, N> arr{};
	std::size_t index{0};

	while(index < N) {
		std::cout << "Enter value #" << index << ":";
		std::cin >> arr[index];

		if (!std::cin) { // handle bad input
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		++index;
	}
	return arr;
}	

template <typename T, std::size_t N>
void refInputArray(std::array<T, N>& arr) {
	std::size_t index{0};
	while (index < N) {
		std::cout << "Enter value #" << index << ": ";
		std::cin >> arr[index];

		if (!std::cin) { // handle bad input
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;	
		}
		++index;
	}
}
