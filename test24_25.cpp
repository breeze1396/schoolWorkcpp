#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void find_first_in_a_notin_b(string& x, string& y)
{
    unordered_set<char> hashset;
    for (auto c : y) {
        hashset.insert(c);
    }
    for (auto c : x) {
        if (hashset.find(c) == hashset.end()) {
            cout << c << endl;
            break;
        }
    }
}

string& find_in_a_notin_b(string& x, string& y)
{
    unordered_set<char> hashset;
    static string s;
    for (auto c : y) {
        hashset.insert(c);
    }
    for (auto c : x) {
        if (hashset.find(c) == hashset.end()) {
            s += c;
        }
    }
    return s;
}

int main()
{
    string x = "qwerttyuuafzwerxtcfyvgubhinjomk",
        y = "wesrdtvyg",
        z = find_in_a_notin_b(x, y);
    cout << z << endl;
}

