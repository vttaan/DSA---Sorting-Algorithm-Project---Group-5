#include "heapSort.h"
using namespace std;

void heapify(int arr[], int n, int startNode, long long &countCompare) {
	int largestNode = startNode;
	int leftNode = 2 * startNode + 1;
	int rightNode = 2 * startNode + 2;

	if (++countCompare && leftNode < n) {
		if (++countCompare && arr[leftNode] > arr[largestNode]) {
			largestNode = leftNode;
		}
	}

	if (++countCompare && rightNode < n) {
		if (++countCompare && arr[rightNode] > arr[largestNode]) {
			largestNode = rightNode;
		}
	}


	if (++countCompare && largestNode != startNode) {
		swap(arr[largestNode], arr[startNode]);

		heapify(arr, n, largestNode,countCompare);
	}
}

void heapSort(int arr[], int n, long long &countCompare) {

	for (int i = n / 2 - 1; ++countCompare && i >= 0; ++countCompare, --i) {
		heapify(arr, n, i,countCompare);
	}

	for (int i = n - 1; ++countCompare && i > 0; --i) {
		swap(arr[0], arr[i]);

		heapify(arr, i, 0, countCompare);
	}

}

/*
int n;
const int max_len = 6e5;
long long countCompare = 0;
int arr[max_len];
int main() {
	string fileName = "outputheapSort.txt";
	ifstream fin("input6.txt");
	ofstream fout(fileName);

	if (!fin.is_open()) {
		return 0;
	}

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> arr[i];
	}
	heapSort(arr, n, countCompare);

	for (int i = 0; i < n; ++i) {
		fout << arr[i] << " ";
	}
	fin.close();
	fout.close();
	return 0;
}
*/



