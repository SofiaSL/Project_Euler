#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void next(std::vector<bool> &v){
	for(auto it = v.begin(); it != v.end(); ++it) {
		if(*it == 0) {
			*it = 1;
			break;
		} else {
			*it = 0;
		}
	}
	return;
}

bool cmp(double x, std::pair<double, std::vector<bool>> p) {
	return x < p.first;
}

int main() {
	std::vector<uint64_t> p1 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};
	std::vector<uint64_t> p2 = {79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181};
	
	std::vector<double> logs1;
	std::vector<double> logs2;
	
	for(auto n : p1) {
		logs1.push_back(std::log(n));
	}
	for(auto n : p2) {
		logs2.push_back(std::log(n));
	}
	double sqrt = 0.0;
	for(auto n : p1) {
		sqrt += std::log(n);
	}
	for(auto n : p2) {
		sqrt += std::log (n);
	}
	sqrt *= 0.5;
	
	std::vector<std::pair<double, std::vector<bool>>> subset1;
	std::vector<std::pair<double, std::vector<bool>>> subset2;
	
	std::vector<bool> iterator (21,false);
	
	while(iterator != std::vector<bool> (21, true)) {
		double sum1 = 0;
		double sum2 = 0;
		for(int n = 0; n != 21; ++n) {
			if(iterator[n]) {
				sum1 += logs1[n];
				sum2 += logs2[n];
			}
		}
		subset1.push_back(std::make_pair (sum1, iterator));
		subset2.push_back(std::make_pair (sum2, iterator));
		next(iterator);
	}
	
	std::sort(subset1.begin(), subset1.end());
	std::sort(subset2.begin(), subset2.end());

	double min = 1.0;
	for(auto p : subset1) {
		auto iter = std::upper_bound(subset2.begin(), subset2.end(), sqrt - p.first, cmp);
		--iter;
		if(sqrt - p.first - (*iter).first < min) {
			min = sqrt - p.first - (*iter).first;
			std::cout << min << "\n";
			for(int b = 0; b != 21; ++b) {
				if(p.second[b]) std::cout << p1[b] << "*";
				if((*iter).second[b]) std::cout << p2[b] << "*";
			}
			std::cout << "\n";
		}
	}
	return 0;
}