#include <iostream>

class NVec {
	public:
		int x,y;
		NVec() {};
		NVec(int a, int b): x(a), y(b) {} // Another way of formulating constructors
		NVec operator + (const NVec&);
};

NVec NVec::operator+  (const NVec& param) {
	NVec temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}

int main() {
	NVec foo(3,1);
	NVec bar(1,2);

	NVec result = foo + bar;
	std::cout << result.x << ',' << result.y << '\n';
	return 0;
}
