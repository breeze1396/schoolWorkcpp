#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<stdio.h>
using namespace std;

void merge(vector<int>& A, vector<int>& B) {
    int m = A.size(),
        n = B.size();
    for (int i = 0; i < n; i++)
        A.push_back(0);

    int i = m - 1, j = 0, k = m + n - 1;

    while (i >= 0 && j < n) {
        if (A[i] > B[j]) {
            A[k--] = A[i--];
        }
        else {
            A[k--] = B[j++];
        }
    }

    while (i >= 0) {
        A[k--] = A[i--];
    }

    while (j < n) {
        A[k--] = B[j++];
    }
}


void print(vector<int> a, int m)
{
    for (size_t i = 0; i < m; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> a{ 1,3,5,9,69 };
    vector<int> b{ 62,36,13,3,2 };
    merge(a, b);
    print(a, 10);
}
