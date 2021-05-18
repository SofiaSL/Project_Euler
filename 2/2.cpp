// this isn't a performing implementation of the fibonacci function because 
// the number of function calls increases exponentially in n
#include <iostream>

unsigned fib(unsigned n) {
	if(n == 0) return 1;
	if(n == 1) return 2;
	return fib(n - 1) + fib(n - 2);
}

int main() {
	unsigned sum = 0;
	for(unsigned n = 0; fib(n) < 4'000'000; ++n) {
		if(fib(n) % 2 == 0) sum += fib(n);
	}
	std::cout << sum << "\n";
	return 0;
}