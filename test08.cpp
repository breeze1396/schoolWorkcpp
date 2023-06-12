#include <queue>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

Node* createList(int n)
{
    Node* head = new Node{ -1 },
        * newNode{},
        * p = head;
    for (int i = 0; i < 10; i++)
    {
        newNode = new Node{ i * n };
        p->next = newNode;
        p = p->next;
    }
    newNode->next = head;
    return head;
}

void printNode(Node* head)
{
    Node* p = head;
    do {
        cout << p->val << ' ';
        p = p->next;
    } while (p != head);
    cout << endl;
}

Node* merge(Node* a, Node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    Node* dummy = new Node(0);
    Node* cur = dummy;
    Node* pa = a, * pb = b;

    cur->next = pa;
    cur = cur->next;
    pa = pa->next;
    cur->next = pb;
    cur = cur->next;
    pb = pb->next;

    while (pa != a || pb != b) {
        if (pa != a) {
            cur->next = pa;
            cur = cur->next;
            pa = pa->next;
        }
        if (pb != b) {
            cur->next = pb;
            cur = cur->next;
            pb = pb->next;
        }
    }
    cur->next = dummy->next;
    delete dummy;
    return cur->next;
}

int main()
{
    Node* list1= createList(1);
    Node* list2= createList(2);
    printNode(list1);
    printNode(list2);

    Node* list3 = merge(list1, list2);
    printNode(list3);

}