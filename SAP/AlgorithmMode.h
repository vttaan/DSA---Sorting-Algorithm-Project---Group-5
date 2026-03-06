#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>

#include "DataGenerator.h"
#include "functions.h"
#include "Add_In.h"

using namespace std;


void handleOutputOrderAlgorithmMode(int isReadFile, int* a, int dataSize, int dataType, long long comparisonsCount,
	float runningTime, string algorithm, string outputOrder, string input, string orderData,
	int outputOrderType);

void AlgorithmMode(string algorithm, string input, string orderData, string outputOrder);