/*
*Tran Tuan Phat
* 25127227
* 25C10
*/
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<fstream>
#include<vector>
using namespace std;

struct Product {
    int id;
    string name;
    double price;
    string expiration_date[11];
};

void InputFile(const char*pCA,const char*pSA,const int&n){
    const char pathCA[] = "readfile.txt";
    const char pathSA[] = "docfile.txt";
    ifstream FInCA, FInSA;
    FInCA.open(pathCA, ios::beg);
    FInSA.open(pathSA, ios::beg);
    int m = 0,nCorrect = 0;
    FInCA >> m;
    FInSA >> nCorrect;
    if (m = nCorrect) {
        char* pCA = new char[n];
        char* pSA = new char[n];
        for (int i = 0; i < n; i++) {
            FInCA >> pCA[i];
            FInSA >> pSA[i];

        }
    }
}
void countevenoddelements(const vector<vector<int>>& arr) {
    if (arr.empty()) return;

    cout << "P2.1: Count even/odd" << endl;
    for (int i = 0; i < arr.size(); ++i) {
        int count = 0;

        if (i % 2 == 0) { 
            for (int element : arr[i]) {
                if (element % 2 == 0)
                    count++;
            }
            cout << "ROW " << i << " Count even elements: " << count << endl;
        }
        else { 
            for (int element : arr[i]) {
                if (element % 2 != 0)
                    count++;
            }
            cout << "ROW " << i << " Count odd elements: " << count << endl;
        }
    }
}
vector<vector<int>> CountEven(const vector<vector<int>>& inputArr) {
    if (inputArr.empty() || inputArr[0].empty()) {
        return {};
    }
    int R = inputArr.size();
    int C = inputArr[0].size();
    vector<vector<int>> outputArr(R, vector<int>(C, 0));
    int dr[] = { -1,-1,-1, 0,0, 1,1,1 };
    int dc[] = { -1, 0, 1,-1,1,-1,0,1 };
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int even_count = 0;
            for (int k = 0; k < 8; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];

                if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
                    if (inputArr[ni][nj] % 2 == 0)
                        even_count++;
                }
            }
            outputArr[i][j] = even_count;
        }
    }
    return outputArr;
}
void Print2Darray(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Original array:" << endl;
    Print2Darray(arr);
    cout << endl;
    countevenoddelements(arr);
    cout << endl;
    vector<vector<int>> evenNeighbor = CountEven(arr);
    cout << "Even neighbors count:" << endl;
    Print2Darray(evenNeighbor);
    return 0;


}