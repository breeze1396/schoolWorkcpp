#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<ctype.h>
#include<stdio.h>
using namespace std;

struct Node {
    char val;
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
            addNode(list, rand() % 10 + '0');
            addNode(list, rand() % 26 + 'a');
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

void splitList(Node* head, Node* head1, Node* head2) {
    Node* p = head->next;
    Node* p1 = head1;
    Node* p2 = head2;
    while (p != nullptr) {
        if (isalpha(p->val)) {
            p1->next = p;
            p1 = p;
        }
        else if (isdigit(p->val)) {
            p2->next = p;
            p2 = p;
        }
        p = p->next;
    }
    p1->next = NULL;
    p2->next = NULL;
}

int main()
{
    Node l1{' '},
         l2{' '},
        * l3{};

    l3 = crateList();
    printNode(l3);

    splitList(l3, &l1, &l2);
    printNode(&l1);
    printNode(&l2);


   

    return 0;
}
