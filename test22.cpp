#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<ctype.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int n, Node* next_ = nullptr) :
        val(n), next(next_) {}
};

void addNode(Node* head, int n)
{
    Node* p = head;
    Node* newNode = new Node{ n, nullptr };
    while (p->next)
    {
        p = p->next;
    }
    newNode->val = n;
    newNode->next = nullptr;
    p->next = newNode;
}
Node* crateList()
{
    Node* list = new Node{ -1, nullptr };
    for (int i = 1; i < 10; i++)
    {

        //addNode(list, rand() % 10 + '0');
        //addNode(list, rand() % 26 + 'a');
    }
    return list;
}

void printNode(Node* head)
{
    Node* p = head->next;
    while (p)
    {
        std::cout << p->val << ' ';
        p = p->next;
    }
    std::cout << endl;
}

int main()
{
    Node list{-1};
    vector<int> a;
    int n = 0;
    cin >> n;
    while ( n != 0)
    {
        a.push_back(n);
        cin >> n;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
        addNode(&list, a[i]);
    printNode(&list);
}
