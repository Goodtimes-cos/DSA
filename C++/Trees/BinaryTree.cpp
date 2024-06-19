#include <iostream>
#include 

struct Node {
	int val;
	// Node *child1, *child2;	
	std::vector <node> children;
};



int main() {
	Node root, child1, child2;
	root.val = 20;
	child1.val = 10;
	root.child1 = &child1;
	root.child2 = &child2;

	std::cout << root.child1->val << std::endl; // I had to chang .val to ->val, as it's a pointer
						    // does -> dereference?
	return 0;
}
