#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>

#include "DataGenerator.h"
#include "functions.h"
#include "Add_In.h"

using namespace std;


void handleOutputOrderAlgorithmMode(int isReadFile, int*& a, int dataSize, int& dataType, long long comparisonsCount,
	float runningTime, string algorithm, string outputOrder, string input, string orderData,
	int outputOrderType)
{
	// COMMAND 1:
	if (isReadFile == 1) {
		RunAlgorithmSort(algorithm, a, dataSize, comparisonsCount, runningTime);
		writeToFile("output.txt", a, dataSize);
		cout << "Input file: " << input << '\n';
		cout << "Input size: " << dataSize << '\n';

		printRunningTime_and_Comparision(comparisonsCount, runningTime, outputOrderType);
	}

	// COMMAND 2 AND 3:
	else {
		vector<string> typeData = { "Randomize", "Nearly Sorted", "Sorted", "Reversed" };
		dataSize = stoi(input);
		a = new int[dataSize];
		dataType = findDataType(orderData);

		cout << "Input size: " << dataSize << '\n';

		// COMMAND 3:
		if (dataType == -1) {
			for (int i = 0; i < 4; i++) {
				cout << '\n';
				cout << "Input order: " << typeData[i] << '\n';


				GenerateData(a, dataSize, i);

				if (i == 0) writeToFile("input_1.txt", a, dataSize);
				if (i == 1) writeToFile("input_2.txt", a, dataSize);
				if (i == 2) writeToFile("input_3.txt", a, dataSize);
				if (i == 3) writeToFile("input_4.txt", a, dataSize);

				RunAlgorithmSort(algorithm, a, dataSize, comparisonsCount, runningTime);

				printRunningTime_and_Comparision(comparisonsCount, runningTime, outputOrderType);
			}
		}
		// COMMAND 2:
		else {
			cout << "Input order: " << typeData[dataType] << '\n';


			GenerateData(a, dataSize, dataType);

			writeToFile("input.txt", a, dataSize);

			RunAlgorithmSort(algorithm, a, dataSize, comparisonsCount, runningTime);

			printRunningTime_and_Comparision(comparisonsCount, runningTime, outputOrderType);

			writeToFile("output.txt", a, dataSize);
		}
	}
}

void AlgorithmMode(string algorithm, string input, string orderData, string outputOrder) {
	int dataSize = -1;
	int dataType = 0;
	int outputOrderType = findOutputOrder(outputOrder);
	int* a;
	long long comparisonsCount = 0;
	float runningTime = 0.0;
	int isReadFile = 0;

	if (checkNums(input) == false) {
		readFileToArr(input, a, dataSize);
		isReadFile = 1;
	}

	handleOutputOrderAlgorithmMode(isReadFile, a, dataSize, dataType, comparisonsCount, runningTime,
		algorithm, outputOrder, input, orderData, outputOrderType);

}