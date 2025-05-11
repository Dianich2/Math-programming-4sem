#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <tchar.h>
#include <random>
#include <string>
#include <chrono>
#include "Levenshtein.h"
#include "LCS.h"

std::string generateRandomString(int length) {
  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  std::string resultString = "";
  srand(time(NULL));
  for (int i = 0; i < length; i++) {
    resultString += alphabet[(((double)rand() / (double)RAND_MAX) * 51)];
  }
  return resultString;
}

int _tmain(int argc, _TCHAR* argv[])
{
  setlocale(LC_ALL, "rus");
  clock_t t1 = 0, t2 = 0, t3, t4;
  std::string s1 = generateRandomString(300);
  std::string s2 = generateRandomString(200);
  std::cout << s1 << '\n';
  std::cout << s2 << '\n';
  std::cout << '\n';
  std::cout << "\n-- ���������� ����������� -----\n";
  std::cout << "\n--����� --- �������� -- ���.�������. ---\n";
  for (int i = 10; i >= 0; i--)
  {
    auto start1 = std::chrono::high_resolution_clock::now(); levenshtein_r(i, s1, i, s2); auto end1 = std::chrono::high_resolution_clock::now();
    auto start2 = std::chrono::high_resolution_clock::now(); levenshtein(i, s1, i, s2); auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration1 = end1 - start1;
    std::chrono::duration<double, std::micro> duration2 = end2 - start2;
    std::cout << std::right << std::setw(2) << i << "/" << std::setw(2) << i
      << "        " << std::left << std::setw(10) << duration1.count()
      << "   " << std::setw(10) << duration2.count() << std::endl;
  }
  
  char x[] = "TOUEXAZ";
  char y[] = "HIEHXZ";
  char z[100] = ""; char z2[250] = "";

  std::cout << "\n-- ���������� ����� LCS ��� X � Y(��������)";
  std::cout << "\n-- ������������������ X: " << x;
  std::cout << "\n-- ������������������ Y: " << y;
  int s = lcs(
    strlen(x),  // �����   ������������������  X   
    "TOUEXAZ",       // ������������������ X
    strlen(y),  // �����   ������������������  Y
    "HIEHXZ"       // ������������������ Y
  );
  std::cout << "\n-- ����� LCS: " << s << '\n';
  int l = lcsd(x, y, z);
  std::cout << "\n-- ���������� ����� �������������������� - LCS(������������ ����������������)\n";
  std::cout << "\n������������������ X: " << x;
  std::cout << "\n������������������ Y: " << y;
  std::cout << "\n                LCS: " << z;
  std::cout << "\n          ����� LCS: " << l << '\n';

  char s3[] = "uNcNshZichvjwyujlu";
  char s4[] = "urWRYhgyRdepfsmiyp";
  auto start1 = std::chrono::high_resolution_clock::now();
  int f = lcs(strlen(s3), s3, strlen(s4), s4);
  auto end1 = std::chrono::high_resolution_clock::now();
  auto start2 = std::chrono::high_resolution_clock::now();
  int k = lcsd(s3, s4, z2);
  auto end2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::micro> duration1 = end1 - start1;
  std::chrono::duration<double, std::micro> duration2 = end2 - start2;
  std::cout << "������ 1 " << s3 << '\n';
  std::cout << "������ 2 " << s4 << '\n';
  std::cout << "����� �������� " << duration1.count() << '\n';
  std::cout << "����� �� " << duration2.count() << '\n';
  return 0;
}
