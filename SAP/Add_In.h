#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>

#include "DataGenerator.h"
#include "functions.h"

using namespace std;

void printRunningTime_and_Comparision(long long comparisonsCount, float runningTime, int outputOrderType);

void printModeAndAlgorithm(string mode, string algorithm1, string algorithm2);

void writeToFile(string filename, int* a, int n);

bool checkNums(const string& input);


int findDataType(const string& orderData);

int findOutputOrder(const string& outputOrder);

void readFileToArr(const string& filename, int*& a, int& dataSize);
