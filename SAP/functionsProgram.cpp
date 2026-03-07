#include <iostream>
#include <fstream>
#include <chrono>
#include "functions.h"
using namespace std;

void RunAlgorithmSort(const string& algorithm, int*& a, int dataSize, long long& comparisonsCount, float& runningTime) {

	auto start = std::chrono::high_resolution_clock::now();

	if (algorithm == "selection-sort") selectionSort(a, dataSize, comparisonsCount); // func sort
	else if (algorithm == "insertion-sort") insertionSort(a, dataSize, comparisonsCount); // func sort
	else if (algorithm == "shell-sort") shellSortKnuth(a, dataSize, comparisonsCount);
	else if (algorithm == "bubble-sort") bubbleSort(a, dataSize, comparisonsCount); // func sort
	else if (algorithm == "heap-sort") heapSort(a, dataSize, comparisonsCount); // func sort
	else if (algorithm == "merge-sort") mergeSort(a, 0, dataSize - 1, comparisonsCount); // func sort
	else if (algorithm == "quick-sort") quickSort(a, 0, dataSize - 1, comparisonsCount); // func sort
	else if (algorithm == "radix-sort") radixSort(a, dataSize, comparisonsCount); // func sort
	else if (algorithm == "counting-sort") countingSort(a, dataSize, comparisonsCount); // func sort
	else if (algorithm == "binary insertion-sort") binaryInsertionSort(a, dataSize, comparisonsCount); // func sort
	else if (algorithm == "shaker-sort") shakerSort(a, dataSize, comparisonsCount); // func sort
	else if (algorithm == "flash-sort") flashSort(a, dataSize, comparisonsCount); // func sort

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = end - start;
	runningTime = static_cast<float>(elapsed.count());
}

// O(n^2)

void selectionSort(int a[], int n, long long& comparisonsCount)
{

	comparisonsCount = 0;
	for (int i = 0; i < n - 1; i++)
	{
		comparisonsCount++;
		int minVal = a[i], minId = i;
		for (int j = i; j < n; j++)
		{
			if (a[j] < minVal)
			{
				comparisonsCount++;
				minVal = a[j];
				minId = j;
			}
			comparisonsCount++;
		}
		comparisonsCount++;
		swap(a[i], a[minId]);
	}
	comparisonsCount++;
}

void insertionSort(int a[], int n, long long& comparisonsCount)
{


	comparisonsCount = 0;
	for (int j = 1; j < n; j++)
	{
		comparisonsCount++;
		int isSwap = 0;
		for (int i = j; i > 0; i--)
		{
			comparisonsCount++;
			if (a[i] > a[i - 1]) {
				swap(a[i], a[i - 1]);
				isSwap = 1;
			}
			comparisonsCount++;
		}
		comparisonsCount++;
		if (isSwap == 0) break;
	}
	comparisonsCount++;

}

pair<int, int> binarySearch(int a[], int l, int r, int val)
{
	long long comparisons = 0;
	while (l <= r)
	{
		comparisons++;
		int mid = (l + r) / 2;
		if (a[mid] == val)
		{
			comparisons++;
			return { mid + 1,comparisons };
		}
		else if (a[mid] < val)
		{
			comparisons++;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	comparisons++;
	return { l,comparisons };
}

void binaryInsertionSort(int a[], int n, long long& comparisonsCount)
{

	comparisonsCount = 0;
	for (int j = 1; j < n; j++)
	{
		comparisonsCount++;
		pair<int, int> p = binarySearch(a, 0, j - 1, a[j]);
		comparisonsCount += p.second;
		for (int i = j; i > p.first; i--)
		{
			comparisonsCount++;
			swap(a[i], a[i - 1]);
		}
		comparisonsCount++;
	}
	comparisonsCount++;

}

void bubbleSort(int a[], int n, long long& comparisonsCount) {
	comparisonsCount = 0;
	for (int i = 1; ++comparisonsCount, i <= n - 1; i++) {
		int flag = 0;
		for (int j = n - 1; ++comparisonsCount, j >= i; j--) {
			++comparisonsCount;
			if (a[j - 1] > a[j]) {
				flag = 1;
				swap(a[j - 1], a[j]);
			}
		}
		++comparisonsCount;
		if (flag == 0) break;
	}
}

void shellSortKnuth(int a[], int n, long long& comparisonsCount) {
	comparisonsCount = 0;
	int gap = 1;
	while (gap < n / 3 && ++comparisonsCount) {
		gap = 3 * gap + 1;
	}

	while (gap > 0 && ++comparisonsCount) {
		for (int i = gap; ++comparisonsCount, i < n; i++) {
			int j = i;
			while (j >= gap && ++comparisonsCount && a[j - gap] > a[j] && ++comparisonsCount) {
				swap(a[j - 1], a[j]);
				j -= gap;
			}
		}
		gap /= 3;
	}
}

void shakerSort(int a[], int n, long long& comparisonsCount) {
	comparisonsCount = 0;
	int start = 0;
	int end = n - 1;
	int lastPos = 0;

	while (start < end && ++comparisonsCount) {
		int isSwap = 0;
		for (int i = start + 1; ++comparisonsCount, i <= end; i++) {
			if (a[i - 1] > a[i] && ++comparisonsCount) {
				swap(a[i], a[i - 1]);
				isSwap = 1;
				lastPos = i;
			}
		}
		if (isSwap == 0 && ++comparisonsCount) break;

		end = lastPos;
		isSwap = 0;
		for (int i = end; ++comparisonsCount, i > start; i--) {
			if (a[i - 1] > a[i] && ++comparisonsCount) {
				isSwap = 1;
				swap(a[i - 1], a[i]);
				lastPos = i;
			}
		}
		if (isSwap == 0) break;
		start = lastPos + 1;
	}
}

//



// O(nlogn)

void heapify(int arr[], int n, int startNode, long long& comparisonsCount) {
	int largestNode = startNode;
	int leftNode = 2 * startNode + 1;
	int rightNode = 2 * startNode + 2;

	if (++comparisonsCount && leftNode < n) {
		if (++comparisonsCount && arr[leftNode] > arr[largestNode]) {
			largestNode = leftNode;
		}
	}

	if (++comparisonsCount && rightNode < n) {
		if (++comparisonsCount && arr[rightNode] > arr[largestNode]) {
			largestNode = rightNode;
		}
	}


	if (++comparisonsCount && largestNode != startNode) {
		swap(arr[largestNode], arr[startNode]);

		heapify(arr, n, largestNode, comparisonsCount);
	}
}

void heapSort(int arr[], int n, long long& comparisonsCount) {

	for (int i = n / 2 - 1; ++comparisonsCount && i >= 0; ++comparisonsCount, --i) {
		heapify(arr, n, i, comparisonsCount);
	}

	for (int i = n - 1; ++comparisonsCount && i > 0; --i) {
		swap(arr[0], arr[i]);

		heapify(arr, i, 0, comparisonsCount);
	}

}

const int max_len = 5e6;
int L[max_len], R[max_len];

void merge(int arr[], int left, int right, int mid, long long& comparisonsCount) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	for (int i = 0; ++comparisonsCount && i < n1; ++i) {
		L[i] = arr[left + i];
	}

	for (int j = 0; ++comparisonsCount && j < n2;  ++j) {
		R[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0;
	int k = left;

	while (true) {
		comparisonsCount++;
		if (!(i < n1)) break;

		comparisonsCount++;
		if (!(j < n2)) break;

		comparisonsCount++;
		if (L[i] <= R[j]) {
			arr[k] = L[i]; ++i;
		}
		else {
			arr[k] = R[j]; ++j;
		}
		++k;

	}

	while (++comparisonsCount && i < n1) {
		arr[k] = L[i];
		i++; k++;
	}


	while (++comparisonsCount && j < n2) {
		arr[k] = R[j];
		j++; k++;
	}


}

void mergeSort(int arr[], int left, int right, long long& comparisonsCount) {

	if (++comparisonsCount && left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid, comparisonsCount);
	mergeSort(arr, mid + 1, right, comparisonsCount);
	merge(arr, left, right, mid, comparisonsCount);

}

int partition(int arr[], int low, int high) {

	int mid = low + (high - low) / 2;
	if (arr[mid] < arr[low]) swap(arr[mid], arr[low]);
	if (arr[high] < arr[low]) swap(arr[high], arr[low]);
	if (arr[high] < arr[mid]) swap(arr[high], arr[mid]);

	swap(arr[mid], arr[high]);
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high, long long& comparisonsCount) {
	while (++comparisonsCount && low < high) {
		int pi = partition(arr, low, high);

		if (++comparisonsCount && (pi - low < high - pi)) {
			quickSort(arr, low, pi - 1, comparisonsCount);
			low = pi + 1;
		}
		else {
			quickSort(arr, pi + 1, high, comparisonsCount);
			high = pi - 1;
		}
	}
}


//


// O(n)

void countingSort(int a[], int n, long long& count_compare) {
	count_compare = 0;
	if (++count_compare && n <= 1) return;
	int MAX = a[0];
	int MIN = a[0];
	for (int i = 1; ++count_compare && i < n; ++i) {
		if (++count_compare && a[i] > MAX) MAX = a[i];
		if (++count_compare && a[i] < MIN) MIN = a[i];
	}
	int range = MAX - MIN + 1;
	int* count = new int[range]();
	int* output = new int[n];
	for (int i = 0; ++count_compare && i < n; ++i) {
		count[a[i] - MIN]++;
	}
	for (int i = 1; ++count_compare && i < range; ++i) {
		count[i] += count[i - 1];
	}
	for (int i = n - 1; ++count_compare && i >= 0; --i) {
		output[count[a[i] - MIN] - 1] = a[i];
		count[a[i] - MIN]--;
	}
	for (int i = 0; ++count_compare && i < n; ++i) {
		a[i] = output[i];
	}
	delete[] count;
	delete[] output;
}

void radixSort(int a[], int n, long long& comparisonsCount) {
	comparisonsCount = 0;
	if (++comparisonsCount && n <= 1) return;
	int maxVal = a[0];
	for (int i = 1; ++comparisonsCount && i < n; i++) {
		if (++comparisonsCount && a[i] > maxVal) maxVal = a[i];
	}
	for (int exp = 1; ++comparisonsCount && maxVal / exp > 0; exp *= 10) {
		int* output = new int[n];
		int count[10] = { 0 };
		for (int i = 0; ++comparisonsCount && i < n; i++) {
			count[(a[i] / exp) % 10]++;
		}
		for (int i = 1; ++comparisonsCount && i < 10; i++) {
			count[i] += count[i - 1];
		}
		for (int i = n - 1; ++comparisonsCount && i >= 0; i--) {
			output[count[(a[i] / exp) % 10] - 1] = a[i];
			count[(a[i] / exp) % 10]--;
		}
		for (int i = 0; ++comparisonsCount && i < n; i++) {
			a[i] = output[i];
		}
		delete[] output;
	}
}

void flashSort(int a[], int n, long long& comparisonsCount) {
	comparisonsCount = 0;
	if (++comparisonsCount && n <= 1) return;
	int m = 0.45 * n;
	if (++comparisonsCount && m <= 1) m = 2;
	int minVal = a[0], maxIdx = 0;
	for (int i = 1; ++comparisonsCount && i < n; i++) {
		if (++comparisonsCount && a[i] < minVal) minVal = a[i];
		if (++comparisonsCount && a[i] > a[maxIdx]) maxIdx = i;
	}

	if (++comparisonsCount && minVal == a[maxIdx]) return;
	int* L = new int[m]();
	double c1 = (double)(m - 1) / (a[maxIdx] - minVal);

	for (int i = 0; ++comparisonsCount && i < n; i++) {
		int k = (int)(c1 * (a[i] - minVal));
		L[k]++;
	}

	for (int i = 1; ++comparisonsCount && i < m; i++) {
		L[i] += L[i - 1];
	}
	int move = 0;
	int j = 0;
	int k = m - 1;

	while (++comparisonsCount && move < n - 1) {
		while (++comparisonsCount && j > L[k] - 1) {
			j++;
			k = (int)(c1 * (a[j] - minVal));
		}
		int flash = a[j];
		while (++comparisonsCount && j != L[k]) {
			k = (int)(c1 * (flash - minVal));
			int hold = a[L[k] - 1];
			a[L[k] - 1] = flash;
			flash = hold;
			L[k]--;
			move++;
		}
	}
	for (int i = 1; ++comparisonsCount && i < n; i++) {
		int hold = a[i];
		int j = i - 1;
		while (++comparisonsCount && j >= 0 && ++comparisonsCount && a[j] > hold) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = hold;
	}
	delete[] L;
}
//