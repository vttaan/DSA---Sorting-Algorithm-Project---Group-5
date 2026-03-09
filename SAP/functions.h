#pragma once
#include <string>


void RunAlgorithmSort(const std::string& algorithm, int*& a, int dataSize, 
	long long& comparisonsCount, float& runningTime);

void selectionSort(int a[], int n, long long& comparisonsCount);
void insertionSort(int a[], int n, long long& comparisonsCount);
void binaryInsertionSort(int a[], int n, long long& comparisonsCount);

void bubbleSort(int a[], int n, long long& comparisonsCount);
void shellSortKnuth(int a[], int n, long long& comparisonsCount);
void shakerSort(int a[], int n, long long& comparisonsCount);

void heapSort(int arr[], int n, long long& comparisonsCount);
void mergeSort(int arr[], int left, int right, long long& comparisonsCount);
void quickSort(int arr[], int low, int high, long long& comparisonsCount);

void countingSort(int a[], int n, long long& count_compare);
void radixSort(int a[], int n, long long& comparisonsCount);
void flashSort(int a[], int n, long long& comparisonsCount);