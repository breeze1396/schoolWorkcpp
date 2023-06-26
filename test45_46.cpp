#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include<iomanip>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void output_keys(vector<string>& hash_table) 
{
    vector<string> keys;
    for (string key : hash_table) {
        if (!key.empty()) keys.push_back(key);
    }
    sort(keys.begin(), keys.end(), [](string& a, string& b) { return a < b; });
    for (string key : keys) cout << key << endl;
}

//删除一个指定结点的算法。
int hash_function(string key, int table_size) {
    int hash = 0;
    for (char c : key) {
        hash = (hash * 31 + c) % table_size;
    }
    return hash;
}

void delete_node(vector<string>& hash_table, string key) {
    int index = hash_function(key,hash_table.size());
   
    while (!hash_table[index].empty() && hash_table[index] != key) {
        index = (index + 1) % hash_table.size();
    }
    if (hash_table[index] == key) {
        hash_table[index] = "DELETED";
        index = (index + 1) % hash_table.size();
        while (!hash_table[index].empty()) {
            string temp = hash_table[index];
            hash_table[index] = "";
            int new_index = hash_function(temp, hash_table.size());
            while (!hash_table[new_index].empty() && hash_table[new_index] != "DELETED") {
                new_index = (new_index + 1) % hash_table.size();
            }
            hash_table[new_index] = temp;
            index = (index + 1) % hash_table.size();
        }
    }
}

int main()
{
    /*vector<string> hash_table = { "apple", "banana", "cherry", "date" };
    output_keys(hash_table);*/

    vector<string> hash_table(10);
    hash_table[0] = "apple";
    hash_table[1] = "banana";
    hash_table[2] = "cherry";
    delete_node(hash_table, "apple");
    for (string key : hash_table) {
        if (key == "") continue;
        cout << key << endl;
    }

    /*vector<string> hash_table(10);
    hash_table[hash_function("apple")] = "apple";
    hash_table[hash_function("banana")] = "banana";
    hash_table[hash_function("cherry")] = "cherry";
    delete_node(hash_table, "apple");
    for (string key : hash_table) {
        if (key == "")
            continue;
        cout << key << endl;
    }*/

    return 0;
}
