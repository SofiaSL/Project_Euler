// the factors() function is a bit overkill and not very performant
#include <iostream>
#include <vector>

std::vector<uint64_t> factors(uint64_t n) { // all the prime factors of n with multiplicity
	std::vector<uint64_t> out;
	for(uint64_t f = 2; f * f <= n; ++f) {
		while(n % f == 0) {
			out.push_back(f);
			n /= f;
		}
	}
	if(n != 1) out.push_back(n);
	return out;
}

int main() {
	uint64_t n = 600851475143 ; // magic constant form the problem
	auto v = factors(n);
	std::cout << v.back() << "\n";
	return 0;
}