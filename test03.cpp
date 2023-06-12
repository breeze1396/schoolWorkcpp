#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

struct dList
{
    int data;
    dList* prior;                     //指向前驱的指针
    dList* next;                      //指向后继的指针
};


void dlistReverse(dList* head)                        //循环双链表的倒置
{
    dList* p = head->next,
        * q = head->prior;
    //p、q不重合并且不交换
    while (q != p && p->prior != q)
    {
        //交换两节点的数据元素
        int t; t = p->data;
        p->data = q->data;
        q->data = t;
        //p指针从头到尾遍历，q指针从尾到头遍历
        p = p->next;
        q = q->prior;
    }
}

void add_dList(dList* head, int n)
{
    dList* p = head->next;
    dList* newNode = new dList{ n, nullptr, head };
    do
    {
        p = p->next;
    }while (p->next != head);

    p->next = newNode;
    newNode->prior = p;
    head->prior = newNode;
}

void printNode(dList* head)
{
    dList* p = head;
    while (p->next != head)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << p->data << ' ';
    cout << endl;
}

int main()
{
    dList* l = new dList;
    l->data = 0;
    l->next = l;
    l->prior = l;
    for (int i = 1; i < 6; i++)
        add_dList(l, i * 2);
   printNode(l);

   dlistReverse(l);

   printNode(l);
}
