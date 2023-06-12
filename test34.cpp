#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<ctype.h>
#include<string>
#include<map>
#include<utility>
using namespace std;

pair<int, int> find_saddle_point(vector<vector<int>>& A) {
    int m = A.size();
    int n = A[0].size();
    vector<int> rowMin(m);
    vector<int> colMax(n);
    for (int i = 0; i < m; i++) {
        rowMin[i] = *min_element(A[i].begin(), A[i].end());
    }
    for (int j = 0; j < n; j++) {
        colMax[j] = A[0][j];
        for (int i = 1; i < m; i++) {
            colMax[j] = max(colMax[j], A[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == rowMin[i] && A[i][j] == colMax[j]) {
                return { i, j };
            }
        }
    }
    return { -1, -1 };
}


int main()
{
    vector<vector<int>> A{
        {1,2545,3,4,5,6},
        {12,2554,23,24,5,6},
        {12,2555,3,24,5,6},
        {21,288,3,24,5,6},
        {21,256,23,4,5,6},
        {21,25454,3,4,5,6},
    };
    pair<int, int> ans = find_saddle_point(A);
    cout << ans.first << "  " << ans.second << endl;
}