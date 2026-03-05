#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
using namespace std;
int partition(int arr[], int low, int high, long long& countCompare);
void quickSort(int arr[], int low, int high, long long& countCompare, float& runningTime);