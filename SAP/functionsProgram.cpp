#include <iostream>
#include <fstream>
#include <chrono>
#include "functions.h"
using namespace std;

void RunAlgorithmSort(const string& algorithm, int*& a, int dataSize, long long& comparisonsCount, float& runningTime) {
	if (algorithm == "selection-sort"); // func sort
	if (algorithm == "insertion-sort"); // func sort
	if (algorithm == "shell-sort"); // func sort
	if (algorithm == "bubble-sort"); // func sort
	if (algorithm == "heap-sort"); // func sort
	if (algorithm == "merge-sort"); // func sort
	if (algorithm == "quick-sort"); // func sort
	if (algorithm == "radix-sort"); // func sort
	if (algorithm == "counting-sort"); // func sort
	if (algorithm == "binary insertion-sort"); // func sort
	if (algorithm == "shaker-sort"); // func sort
	if (algorithm == "flash-sort"); // func sort
}

void bubbleSort(int a[], int n, long long& comp, float& runningTime) {
	comp = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 1; ++comp, i <= n - 1; i++) {
		int flag = 0;
		for (int j = n - 1; ++comp, j >= i; j--) {
			++comp;
			if (a[j - 1] > a[j]) {
				flag = 1;
				swap(a[j - 1], a[j]);
			}
		}
		++comp;
		if (flag == 0) break;
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = end - start;
	runningTime = static_cast<float>(elapsed.count());
}