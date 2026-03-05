#include "mergeSort.h"
#include<chrono>
using namespace std;

const int max_len = 6e5;
int L[max_len], R[max_len];
void merge(int arr[], int left, int right, int mid, long long &countCompare) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	for (int i = 0; i < n1;++countCompare, ++i) {
		L[i] = arr[left + i];
	}

	for (int j = 0; j < n2; ++countCompare,++j) {
		R[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0;
	int k = left;

	while (true) {
		countCompare++;
		if (!(i < n1)) break;

		countCompare++; 
		if (!(j < n2)) break;

		countCompare++;
		if (L[i] <= R[j]) {
			arr[k] = L[i]; ++i;
		}
		else {
			arr[k] = R[j]; ++j;
		}
		++k;

	}

	while (++countCompare && i < n1) {
		arr[k] = L[i];
		i++; k++;
	}


	while (++countCompare && j < n2) {
		arr[k] = R[j];
		j++; k++;
	}

	
}

void mergeSort(int arr[], int left, int right, long long &countCompare) {


	
	if (++countCompare && left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid, countCompare);
	mergeSort(arr, mid + 1, right, countCompare);
	merge(arr, left, right, mid, countCompare);

}
/*
int n;

int arr[max_len];
int main() {
	string fileName = "outputmergeSort.txt";
	ifstream fin("input6.txt");
	ofstream fout(fileName);

	if (!fin.is_open()) {
		return 0;
	}

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> arr[i];
	}
	long long countCompare = 0;
	
	mergeSort(arr, 0, n-1, countCompare);

	for (int i = 0; i < n; ++i) {
		fout << arr[i] << " ";
	}
	
	fin.close();
	fout.close();
	return 0;
}

*/






