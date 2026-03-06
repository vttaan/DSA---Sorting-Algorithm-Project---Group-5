#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>

#include "DataGenerator.h"
#include "functions.h"
#include "AlgorithmMode.h"
#include "ComparisonMode.h"

using namespace std;

long long comparisonsCount = 0;
float runningTime = 0.0;

int main(int argc, char* argv[])
{
	if (argc == 1) return 0;
	string mode = argv[1];
	if (mode == "-a")
	{
		string algorithm = argv[2];
		string input = argv[3];
		string dataOrder = "";
		string outputOrder;
		if (checkNums(input) == false) outputOrder = argv[4];
		else {
			int isOutputOrder;
			isOutputOrder = findOutputOrder(argv[4]);
			if (isOutputOrder != 0) outputOrder = argv[4];
			else {
				dataOrder = argv[4];
				outputOrder = argv[5];
			}
		}
		printModeAndAlgorithm(mode, algorithm, "");

		AlgorithmMode(algorithm, input, dataOrder, outputOrder, comparisonsCount, runningTime);
		
	}
	else if (mode == "-c")
	{
		int dataSize = -1;
		string firstAlgorithm = argv[2], secondAlgorithm = argv[3], input = argv[4], dataOrder = "";
		printModeAndAlgorithm(mode, firstAlgorithm, secondAlgorithm);
		if (argc == 5)
		{
			ComparisonMode(firstAlgorithm, secondAlgorithm, input, dataSize, dataOrder);
		}
		else if (argc == 6)
		{
			dataOrder = argv[5];
			dataSize = stoi(input);
			ComparisonMode(firstAlgorithm, secondAlgorithm, input, dataSize, dataOrder);
		}
	}
	return 0;
}