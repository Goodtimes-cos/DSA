#include <iostream>
#include <vector>

std::vector<int> generate() { // return by value
	// We're intentionally using a named object here so mandatory copy elision doesn't apply
	std::vector arr1 {1,2,3,4,5}; // copies {1,2,3,4,5} into arr1
	return arr1;
}

int main() {
	std::vector arr1 {1,2,3,4,5};
	std::vector arr2 {arr1}; // Copies arr1 to arr2	i
	
	arr1[0] = 6; // We can continue to use arr1
	arr2[0] = 7; // And, we can continue to use arr2

	std::cout << arr1[0] << " " << arr2[0] << '\n';

	std::vector arr3 { generate() }; // the return value of generate() dies
					 // at the end of the expression
	arr3[0] = 7;			 // There's no way to use the return value of generate() here
					 // we only have access to arr3
		
	// Move semantics is an optimization that allows us, under certain circumstances, to
	// inexpensively transfer ownership of some data members from one object to another.
	// ---> Data members that can't be moved are copied instead


	return 0;
}

/* The term copy semantics refers to the rules that determine how copies of objects are made. 
 * When we say a type supports copy semantics, we mean that objects of that type are copyable, 
 * because the rules for making such copies have been defined. When we say copy semantics are 
 * being invoked, that means we’ve done something that will make a copy of an object.
 */
