#include <iostream>
#include <vector>
#include <thread>

// int accum = 0; Global variable, this is badness

void square(int x) {
	accum += x*x;
}

int main() {
	std::vector<std::thread> ths; // A vector of threads
	for (int i=1; i <= 20; i++) {
		ths.push_back(std::thread(&square, i)); // Push this thread to the back
							// it's a pointer to vector square, with parameter
							// i? Is the second parameter a list of parameters?
	}
	// Wait, so this is the sum of the squares?

	for (auto& th : ths) {
		th.join();
	}
	/* Before moving on, note that C++11 offers more terse iteration syntax of the vector class.
	 * We use the auto keyword, instead of specifying type thread. We use & to retrieve a reference
	 * and not a copy of the object, since `join` changes the nature of the object.
	 */ 

	std::cout << "accum = " << accum << std::endl;
	return 0;
}

/* Why is this sometimes showing incorrect answer? This is because of the race condition. When the
 * compiler processes accum += x*x;, reading the current value of accum and setting the updated
 * value is not an atomic event.
 */
