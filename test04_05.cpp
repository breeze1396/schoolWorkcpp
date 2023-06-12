#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

vector<int> merge(vector<int>& A, vector<int>& B) {
    int m = A.size(), n = B.size();
    vector<int> result;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (A[i] < B[j]) {
            result.push_back(A[i]);
            i++;
        }
        else {
            result.push_back(B[j]);
            j++;
        }
    }
    while (i < m) {
        result.push_back(A[i]);
        i++;
    }
    while (j < n) {
        result.push_back(B[j]);
        j++;
    }
    return result;
}

void merge1(vector<int>& A, vector<int>& B) {
    int m = A.size();
    int n = B.size();
    for (int i = 0; i < n; i++)
        A.push_back(0);
    for (int i = m - 1; i >= 0; i--) {
        A[i + n] = A[i];
    }
    int i = n, j = 0, k = 0;
    while (i < m + n && j < n) {
        if (A[i] < B[j]) {
            A[k] = A[i];
            i++;
        }
        else {
            A[k] = B[j];
            j++;
        }
        k++;
    }
    while (j < n) {
        A[k] = B[j];
        j++;
        k++;
    }
}

int main()
{
    /*vector<int> a1{ 1,2,3,7,8,9,11,16 },
        a2{ 2,3,6,10,12,123,456,789 },
        a3{ };
    a3 = merge(a1, a2);*/
    vector<int> a1{ 1,2,3,7,8,9,11,16 },
        a2{ 2,3,6,10,12,123,456,789 };

    merge1(a1, a2);
    for (auto a : a1)
    {
        cout << a << ' ';
    }
    cout << endl;
    return 0;

}