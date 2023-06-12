#include <queue>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct Node {
    int val;
    int index;
    int listIndex;
    Node(int val, int index, int listIndex) : 
        val(val), index(index), listIndex(listIndex) {}
};

struct cmp {
    bool operator()(Node a, Node b) {
        return a.val > b.val;
    }
};

vector<int> mergeKLists(vector<vector<int>>& lists) {
    priority_queue<Node, vector<Node>, cmp> pq;
    for (int i = 0; i < lists.size(); i++) {
        if (!lists[i].empty()) {
            pq.push(Node(lists[i][0], 0, i));
        }
    }
    vector<int> result;
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        result.push_back(node.val);
        if (node.index + 1 < lists[node.listIndex].size()) {
            pq.push(Node(lists[node.listIndex][node.index + 1], node.index + 1, node.listIndex));
        }
    }
    return result;
}

int main()
{
    vector<int> a1, a2, a3, a4, a5, a6{};
    vector< vector<int>> a;

    for (size_t i = 1; i < 2; i++)
    {
        a1.push_back(i * i);
        a2.push_back(i * 2+2);
        a3.push_back(i * 3+3);
        a4.push_back(i * 10+4);
        a5.push_back(i * 100+5);
    }
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);
    a.push_back(a4);
    a.push_back(a5);

   a6 =  mergeKLists(a);
   for (auto n : a6)
       cout << n << ' ';
   return 0;
}