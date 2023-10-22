#include<iostream>

void algorithm(long long n);

/*
int main(int argc, char **argv) {
    if (argc != 2) return -1;

    algorithm(std::atoi(argv[1]));

    return 0;
}
*/

int main() {
    long long n;
    std::cin >> n;
    algorithm(n);
    return 0;
}

void algorithm(long long n) {
    std::cout << n << " ";
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = (n * 3) + 1;
        }
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

// Notes for this problem:
/*
- Choose your data types carefully! If you submit with just "int",
then it fails for test cases 6,7,8,9,10,11!
- This platform takes input as cin, not in the main function,
- argv[1] is the argument passed into the function, not argv[0]
- We have now done some awesome stuff with c++
- We have actually now implemented a verifier for Collatz conjecture,
for N.
- The time complexity is...? Really, it depends.
*/