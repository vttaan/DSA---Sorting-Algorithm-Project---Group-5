#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>

#include "DataGenerator.h"
#include "functions.h"
#include "AddIn.h"

using namespace std;


void handleOutputOrderComparisonMode(int isReadFile, int*& a, int*& b, int dataSize, int& dataType, string firstAlgorithm, string secondAlgorithm, string input, string orderData)
{
	long long firstComparisonsCount = 0, secondComparisonsCount = 0;
	float firstRunningTime = 0, secondRunningTime = 0;
	// COMMAND 4:
	if (isReadFile == 1) {
		RunAlgorithmSort(firstAlgorithm, a, dataSize, firstComparisonsCount, firstRunningTime);
		RunAlgorithmSort(secondAlgorithm, b, dataSize, secondComparisonsCount, secondRunningTime);
		cout << "Input file: " << input << '\n';
		cout << "Input size: " << dataSize << '\n';

		printComparisonForAlgorithms(firstComparisonsCount, secondComparisonsCount, firstRunningTime, secondRunningTime);
	}

	// COMMAND 5
	else {
		vector<string> typeData = { "Randomize", "Nearly Sorted", "Sorted", "Reversed" };
		a = new int[dataSize];
		b = new int[dataSize];
		dataType = findDataType(orderData);

		cout << "Input size: " << dataSize << '\n';
		cout << "Input order: " << typeData[dataType] << '\n';
		
		GenerateData(a, dataSize, dataType);
		for (int i = 0; i < dataSize; i++) b[i] = a[i];

		writeToFile("input.txt", a, dataSize);

		RunAlgorithmSort(firstAlgorithm, a, dataSize, firstComparisonsCount, firstRunningTime);
		RunAlgorithmSort(secondAlgorithm, b, dataSize, secondComparisonsCount, secondRunningTime);

		printComparisonForAlgorithms(firstComparisonsCount, secondComparisonsCount, firstRunningTime, secondRunningTime);

	}
}

void ComparisonMode(string firstAlgorithm, string secondAlgorithm, string input, int& dataSize, string orderData) {
	int dataType = 0;
	int* a;
	int* b;

	int isReadFile = 0;

	if (dataSize < 0) {
		readFileToArr(input, a, dataSize);
		readFileToArr(input, b, dataSize);
		isReadFile = 1;
	}

	handleOutputOrderComparisonMode(isReadFile, a, b, dataSize, dataType, firstAlgorithm, secondAlgorithm, input, orderData);
	delete[] a;
	delete[] b;
}
