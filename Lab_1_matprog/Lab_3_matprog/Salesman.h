#pragma once
#include "permutation.h"
#include <vector>

namespace SalesMan{
	int salesman(int n, std::vector<std::vector<int>> distance, std::vector<int> &result);
}