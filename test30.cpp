#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareStrings(string s1, string s2) {
    return s1 < s2;
}

void sortStrings(vector<string>& strings) {
    sort(strings.begin(), strings.end(), compareStrings);
}

int main() {
    vector<string> strings = { "hello", "world", "apple", "banana" };
    sortStrings(strings);
    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl;
    }
    return 0;
}
