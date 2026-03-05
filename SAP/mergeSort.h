#include<iostream>
#include<fstream>
#include<string>
#include <chrono>
using namespace std;

void merge(int arr[], int left, int mid, int right, long long &countCompare);
void mergeSort(int arr[], int left, int right, long long &countCompare);