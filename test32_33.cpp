#include <iostream>
#include <vector>
#include<stack>
#include <algorithm>

using namespace std;

bool check_parentheses(string expression) {
    stack<char> s;
    for (char c : expression) {
        if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            if (s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}


int main() {
   /* vector<int> A = { 1, 0, 2, 0, 3, 0, 4 };
    auto it = remove(A.begin(), A.end(), 0);
    fill(it, A.end(), 0);
    for (auto i : A) {
        cout << i << " ";
    }
    cout << endl;*/

    cout << check_parentheses("()()()()()(())");
}