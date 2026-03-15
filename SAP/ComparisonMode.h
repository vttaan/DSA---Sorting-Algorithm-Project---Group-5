#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>

#include "DataGenerator.h"
#include "functions.h"
#include "AddIn.h"

using namespace std;

void handleOutputOrderComparisonMode(int isReadFile, int*& a, int*& b,
	int dataSize, int& dataType, string firstAlgorithm, string secondAlgorithm, string input, string orderData);

void ComparisonMode(string firstAlgorithm, string secondAlgorithm, string input, int& dataSize, string orderData);
