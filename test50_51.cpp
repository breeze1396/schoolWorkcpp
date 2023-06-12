#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <stack>
#include<stdlib.h>
using namespace std;

void bidirectional_bubble_sort(vector<int>& A) {
    int start = 0;
    int end = A.size() - 1;
    while (start < end) {
        for (int i = start; i < end; i++) {
            if (A[i] > A[i + 1]) swap(A[i], A[i + 1]);
        }
        end--;
        for (int i = end; i > start; i--) {
            if (A[i] < A[i - 1]) swap(A[i], A[i - 1]);
        }
        start++;
    }
}

int partition(vector<int>& A, int start, int end) {
    int pivot = A[end];
    int i = start;
    for (int j = start; j < end; j++) {
        if (A[j] < pivot) {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[end]);
    return i;
}
void quicksort(vector<int>& A) {
    stack<int> s;
    s.push(0);
    s.push(A.size() - 1);
    while (!s.empty()) {
        int end = s.top();
        s.pop();
        int start = s.top();
        s.pop();
        int pivot_index = partition(A, start, end);
        if (pivot_index - 1 > start) {
            s.push(start);
            s.push(pivot_index - 1);
        }
        if (pivot_index + 1 < end) {
            s.push(pivot_index + 1);
            s.push(end);
        }
    }
}

int main() {
   /* vector<int> A;
    for (int i = 0; i < 10; i++)
        A.emplace_back(rand()%50+1);
    cout << "A:" << endl;;
    for (int x : A) {
        cout << x << " ";
    }
    cout << endl;
    quicksort(A);

    for (int x : A) {
        cout << x << " ";
    }
    cout << endl;*/

    vector<int> B;
    for (int i = 0; i < 10; i++)
        B.emplace_back(rand()%30);
    cout << "B: "<<endl;
    for (int x : B) {
        cout << x << " ";
    }
    cout << endl;
    bidirectional_bubble_sort(B);
    for (int x : B) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
