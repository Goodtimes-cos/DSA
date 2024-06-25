#include <iostream>
#include <string>

int main() {
	double pesos, reais, soles;
	std::cout << "Enter number of Colombian Pesos: ";
	std::cin >> pesos;
	std::cout << "Enter number of Brazilian Reais: ";
	std::cin >> reais;
	std::cout << "Enter number of Peruvian Soles: ";
	std::cin >> soles;

	double p_rate, r_rate, s_rate;
	p_rate = 0.00024;
	r_rate = 0.18;
	s_rate = 0.26;

	std::cout << "US Dollars = $" << (pesos*p_rate) + (reais*r_rate) + (soles*s_rate);

	return 0;
}
