#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include"n.h"
#include<vector>
#include<map>
using namespace std;
void countingSort(int a[], int n, long long& count_compare) {
    count_compare = 0;
    if (++count_compare && n <= 1) return;
    int k = a[0];
    for (int i = 1; ++count_compare && i < n; ++i) {
        if (++count_compare && k < a[i]) k = a[i];
    }
    int* C = new int[k + 1]();
    int* S = new int[n];
    for (int i = 0; ++count_compare && i < n; ++i) {
        C[a[i]]++;
    }
    for (int j = 1; ++count_compare && j <= k; ++j) {
        C[j] += C[j - 1];
    }
    for (int i = n - 1; ++count_compare && i >= 0; --i) {
        S[C[a[i]] - 1] = a[i];
        C[a[i]]--;
    }
    for (int i = 0; ++count_compare && i < n; ++i) {
        a[i] = S[i];
    }
    delete[] C;
    delete[] S;
}
void countingSortImprovement(int a[], int n, long long& count_compare) {
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

void radixSort(int a[], int n,long long &count_compare) {
    count_compare = 0;
    if (++count_compare && n <= 1) return;
    int maxVal = a[0];
    for (int i = 1; ++count_compare && i < n; i++) {
        if (++count_compare && a[i] > maxVal) maxVal = a[i];
    }
    for (int exp = 1; ++count_compare && maxVal / exp > 0; exp *= 10) {
        int* output = new int[n];
        int count[10] = { 0 };
        for (int i = 0; ++count_compare && i < n; i++) {
            count[(a[i] / exp) % 10]++;
        }
        for (int i = 1; ++count_compare && i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; ++count_compare && i >= 0; i--) {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }
        for (int i = 0; ++count_compare && i < n; i++) {
            a[i] = output[i];
        }
        delete[] output;
    }
}
void flashSort(int a[], int n, long long&count_compare) {
    count_compare = 0;
    if (++count_compare && n <= 1) return;
    int m = 0.45 * n;
    if (++count_compare && m <= 1) m = 2;
    int minVal = a[0], maxIdx = 0;
    for (int i = 1; ++count_compare && i < n; i++) {
        if (++count_compare && a[i] < minVal) minVal = a[i];
        if (++count_compare && a[i] > a[maxIdx]) maxIdx = i;
    }

    if (++count_compare && minVal == a[maxIdx]) return;
    int* L = new int[m]();
    double c1 = (double)(m - 1) / (a[maxIdx] - minVal);

    for (int i = 0; ++count_compare && i < n; i++) {
        int k = (int)(c1 * (a[i] - minVal));
        L[k]++;
    }

    for (int i = 1; ++count_compare && i < m; i++) {
        L[i] += L[i - 1];
    }
    int move = 0;
    int j = 0;
    int k = m - 1;

    while (++count_compare && move < n - 1) {
        while (++count_compare && j > L[k] - 1) {
            j++;
            k = (int)(c1 * (a[j] - minVal));
        }
        int flash = a[j];
        while (++count_compare && j != L[k]) {
            k = (int)(c1 * (flash - minVal));
            int hold = a[L[k] - 1];
            a[L[k] - 1] = flash;
            flash = hold;
            L[k]--;
            move++;
        }
    }
    for (int i = 1; ++count_compare && i < n; i++) {
        int hold = a[i];
        int j = i - 1;
        while (++count_compare && j >= 0 && ++count_compare && a[j] > hold) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = hold;
    }
    delete[] L;
}