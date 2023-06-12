#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<ctype.h>
#include<stdio.h>
using namespace std;

bool check_string(string s) {
    size_t ampersand_pos = s.find('&');
    size_t dollar_pos = s.find('$');
    if (ampersand_pos == string::npos || dollar_pos == string::npos) {
        return false;
    }
    string w = s.substr(0, ampersand_pos);
    string m = s.substr(ampersand_pos + 1, dollar_pos - ampersand_pos - 1);
    reverse(m.begin(), m.end());
    return w == m;
}

int main()
{
    string a = "asdf&fdsa$";
    string ans  = check_string(a) == true? "true": "false";
    cout << a << "    " << ans << endl;

     a = "1234&4321$";
     ans = check_string(a) == true ? "true" : "false";
    cout << a << "    " << ans << endl;

    a = "12345&4321$";
    ans = check_string(a) == true ? "true" : "false";
    cout << a << "    " << ans << endl;
}