#include<iostream>
#include<list>
#include<algorithm>

int algorithm(int length, int *values);

int main() {
    int n;
    int *values;
    std::cin >> n;
    // std::cin >> values;
    algorithm(n, values);
    return 0;
}