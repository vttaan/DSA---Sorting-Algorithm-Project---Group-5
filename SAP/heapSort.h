#include<iostream>
#include<fstream>
#include<string>
#include <chrono>
using namespace std;

void heapify(int arr[], int n , int startNode, long long &countCompare);
void heapSort(int arr[], int n, long long &countCompare);