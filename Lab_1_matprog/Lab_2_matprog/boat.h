#pragma once
#include "Combi.h"
#include <vector>
namespace boatfuncs {
	int boat(int Weigth, int countOfPlaces,
		int countOfContainers, std::vector<int> weightsOfContainers,
		std::vector<int> costsOfContainers, std::vector<int> &resultContainers
	);
}