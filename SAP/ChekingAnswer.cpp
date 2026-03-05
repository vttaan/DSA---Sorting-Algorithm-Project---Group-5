#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
const int max_len = 5e6;
int arrCheck[max_len];
int arrAns[max_len];
int n;
int main() {
	string fileNameIn = "input6.txt";
	string fileNameOut = "outputheapSort.txt";

	ifstream findata(fileNameIn);
	ifstream finOutAns(fileNameOut);

	if (!findata.is_open()) {
		return 0;
	}
	if (!finOutAns.is_open()) {
		return 0;
	}

	findata >> n;
	for (int i = 0; i < n; ++i) {
		findata >> arrCheck[i];
	}

	for (int i = 0; i < n; ++i) {
		finOutAns >> arrAns[i];
	}
	sort(arrCheck, arrCheck + n);
	for (int i = 0; i < n; ++i) {
		if (arrCheck[i] != arrAns[i]) {
			cout << i << arrCheck[i] << " " << arrAns[i] << endl;
			cout << "ham sai r";
			return 0;
		}
	}
	findata.close();
	finOutAns.close();
}