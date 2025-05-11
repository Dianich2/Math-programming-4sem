#include <iostream>
#include <Windows.h>
#include "Combi.h"
#include "boat.h"
using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char mas[][2] = { "A", "B", "C", "D", "E"};
	cout << "��������� ��������� ���� �����������:\n";
	cout << "�������� ���������:\n{";
	for (int i = 0; i < 5; i++) {
		cout << mas[i] << (i < 4 ? ", ": "");
	}
	cout << '}';
	cout << "��������� ���� �����������  \n";
	combi::subset s1(5);
	int n1 = s1.getfirst();

	while (n1 >= 0) {
		cout << '{';
		for (int i = 0; i < n1; i++) {
			cout << mas[s1.ntx(i)] << (i < n1 - 1 ? ", " : "");
		}
		cout << "}\n";
		n1 = s1.getnext();
	}
	cout << "�����: " << s1.count() << "\n\n";

  cout << "��������� ���������:\n";
	cout << "�������� ���������:\n{";
	for (int i = 0; i < 5; i++) {
		cout << mas[i] << (i < 4 ? ", " : "");
	}
	cout << '}';
	combi::xcombination s2(5, 2);
	int n2 = s2.getfirst();
	cout << "��������� ���� ��������� �� " << s2.n << " �� " << s2.m << '\n';

	while (n2 >= 0) {
		cout << s2.nc << " : { ";
		for (int i = 0; i < n2; i++) {
			cout << mas[s2.ntx(i)] << (i < n2 - 1 ? ", " : "");
		}
		cout << "}\n";
		n2 = s2.getnext();
	}
	cout << "�����: " << s2.count() << "\n\n";

	cout << "��������� ������������:\n";
	cout << "�������� ���������:\n{";
	for (int i = 0; i < 5; i++) {
		cout << mas[i] << (i < 4 ? ", " : "");
	}
	cout << '}';
	combi::permutation s3(5);
	long long n3 = s3.getfirst();
	cout << "\n��������� ���� ������������\n";

	while (n3 >= 0) {
		cout << s3.np << " : { ";
		for (int i = 0; i < s3.n; i++) {
			cout << mas[s3.ntx(i)] << (i < s3.n - 1 ? ", " : "");
		}
		cout << "}\n";
		n3 = s3.getnext();
	}
	cout << "�����: " << s3.count() << "\n\n";

	cout << "��������� ����������\n";
	cout << "�������� ���������:\n{";
	for (int i = 0; i < 5; i++) {
		cout << mas[i] << (i < 4 ? ", " : "");
	}
	cout << '}';
	combi::accomodation s4(5, 2);
	long long n4 = s4.getfirst();
	cout << "\n��������� ���� ���������� �� " << s4.n << " �� " << s4.m << '\n';

	while (n4 >= 0) {
		cout << s4.na << " : { ";
		for (int i = 0; i < 2; i++) {
			cout << mas[s4.ntx(i)] << (i < s4.m - 1 ? ", " : "");
		}
		cout << "}\n";
		n4 = s4.getnext();
	}
	cout << "�����: " << s4.count() << "\n\n";

	int Weight = 1500;
	int countOfPlaces = 5;
	int countOfContainers = 35;
	std::vector<int> weightsOfContainers(countOfContainers);
	std::vector<int> costsOfContainers(countOfContainers);
	for (int i = 0; i < countOfContainers; i++) {
		weightsOfContainers[i] = 100 + (rand() % (900 - 100 + 1));
		costsOfContainers[i] = 10 + (rand() % (150 - 10 + 1));
	}
	std::vector<int> resultContainers(countOfPlaces);
	int cc = boatfuncs::boat(Weight, countOfPlaces, 25, weightsOfContainers, costsOfContainers, resultContainers);

	cout << "- ������ � ���������� ����������� �� �����\n";
	cout << "- ����� ���������� �����������    : " << 25 << '\n';
	cout << "- ���������� ���� ��� ����������� : " << countOfPlaces << '\n';
	cout << "- ����������� �� ���������� ����  : " << Weight << '\n';
	cout << "- ��� �����������                 : \n";
	for (int i = 0; i < countOfContainers; i++) cout << weightsOfContainers[i] << " ";
	cout << "\n- ����� �� ���������              : \n";
	for (int i = 0; i < countOfContainers; i++) cout << costsOfContainers[i] << " ";
	cout << "\n- ������� ���������� (0,1,...,m-1): \n";
	for (int i = 0; i < countOfPlaces; i++) cout << resultContainers[i] << " ";
	cout << "\n- ����� �� ���������              : " << cc;
	cout << "\n- ����� ��� ��������� ����������� : ";
	int s = 0; for (int i = 0; i < countOfPlaces; i++) s += weightsOfContainers[resultContainers[i]]; cout << s << "\n\n";

	int maxcc = 0;
	clock_t t1, t2;
	countOfPlaces = 6;
	std::cout << std::endl << "-- ������ �� ����������� �������� ����� -- ";
	std::cout << std::endl << "-  ����������� �� ����    : " << Weight;
	std::cout << std::endl << "-  ���������� ����        : " << countOfPlaces;
	std::cout << std::endl << "-- ���������� ------ ����������������� -- ";
	std::cout << std::endl << "�����������    ����������  \n";
	resultContainers.resize(countOfPlaces);
	for (int i = 25; i <= 35; i++)
	{
		t1 = clock();
		int maxcc = boatfuncs::boat(Weight, countOfPlaces, i, weightsOfContainers, costsOfContainers, resultContainers);
		t2 = clock();
		cout << "    " << i << "            " << (t2 - t1) << '\n';
	}
}