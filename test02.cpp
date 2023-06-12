#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};


ListNode* ReserveLink(ListNode* h) {
    ListNode* HeadNext, * HeadPre, * firstNode;
    HeadNext = h->next->next;
    HeadPre = h->next;
    firstNode = h->next;//保存第一个结点的引用
    while (HeadNext != h)
    {
        ListNode* tempNode = HeadNext->next;
        HeadNext->next = HeadPre;
        HeadPre = HeadNext;
        if (tempNode == h)
        {
            h->next = HeadPre;
        }
        HeadNext = tempNode;
    }
    //将最初的第一个结点，指向现在的头结点
    firstNode->next = h;
    return h;
}

void addListNode(ListNode* head, int n)
{
    ListNode* p = head;
    ListNode* newNode = new ListNode{n, head};
    while (p->next != head && head->next != head)
    {
        p = p->next;
    }
    p->next = newNode;
}

void printNode(ListNode* head)
{
    ListNode* p = head;
    while (p->next != head)
    {
        cout << p->val << ' ';
        p = p->next;
    }
    cout << p->val << ' ';
    cout << endl;
}


int main()
{
    ListNode list{0, &list};
    //没有头指针
    for (int i = 1; i < 10; i++)
    {
        addListNode(&list, i * 2);
        //addListNode(&list, i * 2 + rand()%100);
    }

    printNode(&list);
    ReserveLink(&list);
    printNode(&list);
}