#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
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
    Node* newNode = new Node{n, nullptr};
    while (p->next)
    {
        p = p->next;
    }
    newNode->val = n;
    newNode->next = nullptr;
    p->next = newNode;
}
Node* crateList(int mode, int num = 10, int x = 1)
{
    Node* list = new Node{-1, nullptr};
    if (mode == 1) {
        for (int i = 1; i < num; i++)
        {
            addNode(list, rand() % 100 * x);
        }
    }
    else
    {
        for (int i = 1; i < num+1; i++)
        {
            addNode(list, i * x);
        }
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


void moveElements(Node* la, Node* lb, int index, int len)
{
    Node* pa = la,
        * pb = lb;

    for (int i = 0; i < index-2; ++i)
    {
        pa = pa->next;
        pb = pb->next;
    }
    Node* start = pa;
    for (size_t i = 0; i < len; i++)
    {
        pa = pa->next;
    }
    Node* end = pa;
    //放在la上
    pa = start;
    start = pa->next;
    pa->next = end->next;
    //放在lb上
    end->next = pb->next;
    pb->next = start;
}

void insertAfterX(Node * head, int x, int m) {
    Node* p = head->next;
    while (p != nullptr && p->val != x) {
        p = p->next;
    }
    if (p == nullptr) {
        printf("Error: Node with value %d not found.\n", x);
        return;
    }
    for (int i = 0; i < m; i++) {
        Node* newNode = new Node(0, p->next);
        p->next = newNode;
        p = newNode;
    }
}

void insertBeforeI(Node * head, int i, int x) {
    Node* prev = NULL;
    Node* p = head;
    for (int j = 1; j < i; j++) {
        prev = p;
        p = p->next;
    }
    Node* newNode = new Node(x);
    if (prev == NULL) {
        newNode->next = head;
        head = newNode;
    }
    else {
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

void deleteI(Node * head, int i) {
    Node* prev = NULL;
    Node* p = head;
    for (int j = 1; j < i; j++) {
        prev = p;
        p = p->next;
    }
    if (prev == NULL) {
        head = p->next;
    }
    else {
        prev->next = p->next;
    }
    free(p);
}


int main()
{
    Node* l1{}, 
        * l2{};
    l1 = crateList(2, 10, 1);
    //l2 = crateList(2, 10, 100);
    //cout << "两条链表初始值：" << endl;
    //printNode(l1);
    //printNode(l2);
    //moveElements(l1->next, l2->next, 3, 4);//假装没有头节点
    //cout << "moveElement后：" << endl;
    //printNode(l1);
    //printNode(l2);
    //cout << "---------------" << endl;
    //cout << "insertAfterX后：" << endl;
    //insertAfterX(l1, 8, 5);
    //printNode(l1);
    printNode(l1);
    insertBeforeI(l1->next, 6, 11111);
    deleteI(l1->next, 6); //假设没有头节点
    printNode(l1);

    return 0;
}
