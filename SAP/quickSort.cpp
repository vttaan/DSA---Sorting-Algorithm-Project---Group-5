#include "quickSort.h"

int partition(int arr[], int low, int high, long long &countCompare) {


    int pivot = arr[high];

    int i = low - 1;

    
    for (int j = low; j <= high - 1;++countCompare, j++) {
        if (++countCompare && arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(int arr[], int low, int high, long long &countCompare) {
	
    if (++countCompare && low < high) {

        
        int pi = partition(arr, low, high, countCompare);


        quickSort(arr, low, pi - 1, countCompare);
        quickSort(arr, pi + 1, high, countCompare);
    }
	
}


/*
int n;
const int max_len = 6e5;
int arr[max_len];
int main() {
	string fileName = "outputquickSort.txt";
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
	float runningTime = 0;
	quickSort(arr, 0, n-1, countCompare, runningTime);

	for (int i = 0; i < n; ++i) {
		fout << arr[i] << " ";
	}
	cout << countCompare << " " << runningTime;
	fin.close();
	fout.close();
	return 0;
}
*/






