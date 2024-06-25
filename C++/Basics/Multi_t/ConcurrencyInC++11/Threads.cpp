#include <iostream>
#include <thread>

void func(int x) {
	std::cout << "Inside thread " << x << std::endl;
}

int main() {
	std::thread th(&func, 100);
	th.join();
	std::cout << "Outside thread" << std::endl;
	return 0;
}
