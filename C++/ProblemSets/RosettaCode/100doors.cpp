#include <iostream>

/*
int main() {
	int C[100] = { };
	
	for (int i=0; i < 100; i++) {
		int j=0;
		while (j < 100) {
			if (C[j+i] == 0) {
				C[j+i] = 1;
			} else {
				C[j+i] = 0;
			}
			j = j+i;
		}
	}
	return 0;
}
*/

int main() {
	bool is_open[100] = { false };
	for(int pass = 0; pass < 100; ++pass)
		for(int door = pass; door < 100; door += pass+1)
			is_open[door] = !is_open[door];	

	for (int door = 0; door < 100; ++door)
		std::cout << "door #" << door+1 << (is_open[door]? " is open." : " is closed.") << std::endl;

	return 0;
}
