#include "boat.h"

namespace boatfuncs {
	int calculateWeight(combi::xcombination s, std::vector<int> weightsOfContainers) {
		int rc = 0;
		for (int i = 0; i < s.m; i++) {
			rc += weightsOfContainers[s.ntx(i)];
		}
		return rc;
	}

	int calculateCost(combi::xcombination s, std::vector<int> costsOfContainers) {
		int rc = 0;
		for (int i = 0; i < s.m; i++) {
			rc += costsOfContainers[s.ntx(i)];
		}
		return rc;
	}

	void copyNecessaryContainers(short m, std::vector<int> &destination, std::vector<int> source) {
		for (int i = 0; i < m; i++) {
			destination[i] = source[i];
		}
	}

	int boat(int Weigth, int countOfPlaces,
		int countOfContainers, std::vector<int> weightsOfContainers,
		std::vector<int> costsOfContainers, std::vector<int> &resultContainers
	) {
		combi::xcombination xc(countOfContainers, countOfPlaces);
		int rc = 0;
		int i = xc.getfirst();
		int cc = 0;
		while (i > 0) {
			if (boatfuncs::calculateWeight(xc, weightsOfContainers) <= Weigth) {
				if ((cc = boatfuncs::calculateCost(xc, costsOfContainers)) > rc) {
					rc = cc;
					boatfuncs::copyNecessaryContainers(countOfPlaces, resultContainers, xc.sset);
				}
			}
			i = xc.getnext();
		}
		return rc;
	}
}