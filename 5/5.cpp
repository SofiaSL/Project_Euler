#include <iostream>
#include <numeric>

int main() {
	unsigned sum_sq = 0; // sum of the first hundred squares
	for(unsigned i = 1; i <= 100; ++i) {
		sum_sq += i * i;
	}
	unsigned sum = 0; // sum of the first hundred naturals
	for(unsigned i = 1; i <= 100; ++i) {
		sum += i;
	}
	std::cout << sum * sum - sum_sq << "\n";
	return 0;
}