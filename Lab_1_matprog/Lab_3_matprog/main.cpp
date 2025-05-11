#include <iostream>
#include <Windows.h>
#include "permutation.h"
#include "Salesman.h"
#include <vector>
#define INF 0x7fffffff

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<vector<int>>matrix = {
		{INF, 22, 32, INF, 11},
		{11, INF, 26, 57, 73},
		{13, 33, INF, 86, 60},
		{28, 47, 44, INF, 33},
		{82, 77, 52, 24, INF}
	};
	std::cout << "\n-- Задача коммивояжера -- ";
	std::cout << "\n-- количество  городов: " << 5;
	std::cout << "\n-- матрица расстояний : ";
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\n';
		for (int j = 0; j < 5; j++) {
			if (matrix[i][j] != INF) std::cout << matrix[i][j] << " ";
			else std::cout << "INF" << " ";
		}
	}
	vector<int> res(5);
	int dist = SalesMan::salesman(5, matrix, res);
	std::cout << "\n-- оптимальный маршрут: ";
	for (int i = 0; i < 5; i++) std::cout << res[i] + 1 << "-->"; std::cout << res[0] + 1;
	std::cout << "\n-- длина маршрута     : " << dist;
}