#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<ctype.h>
#include<string>
#include<map>
using namespace std;

void removeSubstring(string& s, string t) {
    string result;
    int i = 0;
    while (i < s.length()) {
        bool match = true;
        for (int j = 0; j < t.length(); j++) {
            if (s[i + j] != t[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            i += t.length();
        }
        else {
            result += s[i];
            i++;
        }
    }
    s = result;
}

void countCharacters(string s) {
    map<char, int> counts;
    for (int i = 0; i < s.length(); i++) {
        counts[s[i]]++;
    }
    for (auto it = counts.begin(); it != counts.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}

void findSubstring(string s, string t) {
    vector<int> positions;
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s.substr(i, t.length()) == t) {
            count++;
            positions.push_back(i);
        }
    }
    cout << "Count: " << count << endl;
    cout << "Positions: ";
    for (int i = 0; i < positions.size(); i++) {
        cout << positions[i] << " ";
    }
    cout << endl;
}


int main() {
    string s = "hello worldlllldadad";
    string t = "l";
    /*cout << s << endl;
    cout << "removeSubstring" << endl;
    removeSubstring(s, t);
    cout << s << endl;*/

    /*cout << "countCharacters" << endl;
    countCharacters(s);*/

    cout << s << ' ' << t << endl;
    cout << "findSubstring" << endl;
    findSubstring(s, t);
    return 0;
}