#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>

#include "DataGenerator.h"
#include "functions.h"
#include "AlgorithmMode.h"
#include "Comparisions.h"

using namespace std;


int main(int argc, char* argv[])
{
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

		AlgorithmMode(algorithm, input, dataOrder, outputOrder);
		
	}
	else if (mode == "-c")
	{
		//
	}
	return 0;
}