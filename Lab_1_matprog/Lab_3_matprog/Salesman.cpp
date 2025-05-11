#include "Salesman.h"
#define INF 0x7fffffff

namespace SalesMan {
	int calculateDistance(int n, std::vector<std::vector<int>> distance, std::vector<int> result, bool &t) {
		int sum = 0;
		for (int i = 1; i < n; i++) {
			if (distance[result[i - 1]][result[i]] == INF) {
				t = false;
				return 0;
			}
			sum += distance[result[i - 1]][result[i]];
		}
		if (distance[result[n - 1]][result[0]] == INF) {
			t = false;
			return 0;
		}
		sum += distance[result[n - 1]][result[0]];
		return sum;
	}
	int salesman(int n, std::vector<std::vector<int>> distance, std::vector<int>& result) {
		permutations::permutation p(n);
		int res = 10000000;
		int k = p.getfirst();
		while (k >= 0) {
			bool t = true;
			int sum = calculateDistance(n, distance, p.sset, t);
			if (t) {
				if (sum < res) {
					res = sum;
					for (int i = 0; i < n; i++) {
						result[i] = p.sset[i];
					}
				}
			}
			k = p.getnext();
		}
		return res;
	}
}