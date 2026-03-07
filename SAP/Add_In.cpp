#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>

#include "DataGenerator.h"
#include "functions.h"

using namespace std;

void printComparisonForAlgorithms(long long firstComparisonsCount, long long secondComparisonsCount, float firstRunningTime, float secondRunningTime) {
	cout << "----------------------------\n";
	cout << "Running time: " << firstRunningTime << " | " << secondRunningTime << "\n";
	cout << "Comparisons: " << firstComparisonsCount << " | " << secondComparisonsCount << "\n";
}


void printRunningTime_and_Comparision(long long comparisonsCount, float runningTime, int outputOrderType) {
	cout << "----------------------------\n";
	if (outputOrderType == 3) {
		cout << "Running time: " << runningTime << '\n';
		cout << "Comparisions: " << comparisonsCount << '\n';
	}
	else if (outputOrderType == 1) cout << "Running time: " << runningTime << '\n';
	else cout << "Comparisions: " << comparisonsCount << '\n';
}

void printModeAndAlgorithm(string mode, string algorithm1, string algorithm2) {
	if (mode == "-a") {
		cout << "ALGORITHM MODE\n";
		cout << "Algorithm: " << algorithm1 << '\n';
	}
	else if (mode == "-c") {
		cout << "COMPARISON MODE\n";
		cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << '\n';
	}
}

void writeToFile(string filename, int* a, int n) {
	ofstream fout(filename);
	fout << n << '\n';
	for (int i = 0; i < n; i++) fout << a[i] << ' ';
	fout << '\n';
	fout.close();
}

bool checkNums(const string& input) {
	for (int i = 0; i < input.size(); i++) if (input[i] < '0' || input[i] > '9') return false;
	return true;
}


int findDataType(const string& orderData) {
	if (orderData.empty()) return -1;
	if (orderData == "-rand") return 0;
	if (orderData == "-nsorted") return 1;
	if (orderData == "-sorted") return 2;
	if (orderData == "-rev") return 3;

	return -1;
}

int findOutputOrder(const string& outputOrder) {
	if (outputOrder == "-time") return 1;
	if (outputOrder == "-comp") return 2;
	if (outputOrder == "-both") return 3;
	return 0;
}

void readFileToArr(const string& filename, int*& a, int& dataSize) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "Error";
		return;
	}

	fin >> dataSize;
	a = new int[dataSize];

	for (int i = 0; i < dataSize; i++) fin >> a[i];

	fin.close();
}
