#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

void addListNode(ListNode* head, int n)
{
    ListNode* p = head;
    ListNode* newNode = new ListNode;
    while (p->next)
    {
        p = p->next;
    }
    newNode->val = n;
    newNode->next = nullptr;
    p->next = newNode;
}

void printNode(ListNode* head)
{
    ListNode* p = head->next;
    while (p)
    {
        std::cout << p->val << ' ';
        p = p->next;
    }
    std::cout << endl;
}

void deleteRange(ListNode* head, int min, int max) {
    ListNode* prev = head;
    ListNode* p = head->next;
    while (p != NULL) {
        if (p->val > min && p->val < max) {
            prev->next = p->next;
            free(p);
            p = prev->next;
        }
        else {
            prev = p;
            p = p->next;
        }
    }
}

void deleteNode(ListNode* f, int a) {
    ListNode* prev = NULL;
    ListNode* p = f;
    while (p != NULL && p->val != a) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) {
        printf("Error: Node with value %d not found.\n", a);
    }
    else {
        if (prev == NULL) {
            f = p->next;
        }
        else {
            prev->next = p->next;
        }
        free(p);
    }
}


int main()
{
    cout << "list:" << endl;
    ListNode list1{}, list2{};
    for (int i = 1; i < 10; i++)
    {
        addListNode(&list1, i * 2);
        //addListNode(&list, i * 2 + rand()%100);
    }

    for (int i = 1; i < 10; i++)
    {
        //addListNode(&list, i * 2);
        addListNode(&list2, rand() % 100);
    }

    /*printNode(&list1);
    cout << "删除10-16之间的数：" << endl;
    deleteRange(&list1, 10, 16);
    printNode(&list1);
    cout << "----------------------" << endl;
    
    for (int i = 1; i < 10; i++)
    {
        //addListNode(&list, i * 2);
        addListNode(&list2,  rand()%100);
    }
    printNode(&list2);
    cout << "删除30-60之间的数：" << endl;
    deleteRange(&list2, 30, 60);
    printNode(&list2);
    cout << "----------------------" << endl;*/
    printNode(&list1);
    deleteNode(&list1, 8);
    printNode(&list1);
    printNode(&list2);
    deleteNode(&list2, 8);
    printNode(&list2);

}