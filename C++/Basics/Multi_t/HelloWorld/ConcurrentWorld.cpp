#include <iostream>
#include <thread>  // Declarations for the multi-threading
		   // support in the Standard C++ library
		   // are in new headers

/* Every thread has to have an initial function, which is where the new
 * thread of execution begins. For the initial thread in an application,
 * this is main(), but for every other thread it's specified in the
 * constructor of a std::thread
 */
void hello() {
	std::cout << "Hello Concurrent World\n";
}

/* After the new thread is launched, the initial thread continues 
 * execution. If it didn't wait for the new thread to finish, it 
 * would merrily continue to the end of main() and end the program,
 * before the new thread has a chance to run. This is why
 * we use .join(), which causes the calling thread to wait for the
 * thread associated with the std::thread object, t.
 */
int main() {
	std::thread t(hello);
	t.join();
}


