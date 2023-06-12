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

ListNode* createList(int mode, int num = 10, int x = 1)
{
    ListNode* list = new ListNode{ -1, nullptr };
    if (mode == 1) {
        for (int i = 1; i < num; i++)
        {
            addListNode(list, rand() % 100 * x);
        }
    }
    else
    {
        for (int i = 1; i < num + 1; i++)
        {
            addListNode(list, i * x);
        }
    }
    return list;
}

ListNode* merge_sorted_lists(ListNode* ha, ListNode* hb) {
    ListNode* dummy = new ListNode{ 0, nullptr };
    ListNode* curr = dummy;
    while (ha && hb) {
        if (ha->val < hb->val) {
            curr->next = ha;
            ha = ha->next;
        }
        else {
            curr->next = hb;
            hb = hb->next;
        }
        curr = curr->next;
    }
    if (ha) curr->next = ha;
    if (hb) curr->next = hb;
    return dummy->next;
}

int main()
{
    ListNode* l1 = createList(2,10,1),
        * l2 = createList(2,10,2),
        * l3{};
    printNode(l1);
    printNode(l2);
    l3 = merge_sorted_lists(l1->next, l2->next);

    printNode(l3);
}
