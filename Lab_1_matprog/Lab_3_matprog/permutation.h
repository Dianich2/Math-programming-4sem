#pragma once
#include <vector>
#include <iostream>
namespace permutations {
	struct permutation {
		const static bool L = true;
		const static bool R = false;
		short n;
		long long np;
		std::vector<int> sset;
		std::vector<bool> dart;
		permutation(short n = 1);
		void reset();
		long long getfirst();
		long long getnext();
		int ntx(short i);
		long long count();
	};
}