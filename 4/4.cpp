// compile with std=c++17 for the std::lcm function
#include <iostream>
#include <numeric>

int main() {
	unsigned lcm = 1;
	for(unsigned i = 1; i <= 20; ++i) {
		lcm = std::lcm(lcm, i);
	}
	std::cout << lcm << "\n";
	return 0;
}