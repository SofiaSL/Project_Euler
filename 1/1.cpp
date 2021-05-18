// 3*333*334/2+5*199*200/2-15*66*67/2
#include <iostream>

int main() {
	unsigned sum = 0;
	for(unsigned i = 0; i != 1000; ++i) {
		if(i % 3 == 0 || i % 5 == 0) sum += i;
	}
	std::cout << sum << "\n";
}