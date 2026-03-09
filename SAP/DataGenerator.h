#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;

template <class T>
void Swap(T& a, T& b);

//-------------------------------------------------

// Function to generate an array with random data
void GenerateRandomData(int a[], int n);

// Function to generate an array with ascending order data
void GenerateSortedData(int a[], int n);

// Function to generate an array with descending order data
void GenerateReverseData(int a[], int n);

// Function to generate an array with nearly sorted data
void GenerateNearlySortedData(int a[], int n);

void GenerateData(int a[], int n, int dataType);