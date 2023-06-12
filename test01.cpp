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
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
}

void reversevector(vector<int>& A) {
    int i = 0;
    int j = A.size() - 1;
    while (i < j) {
        swap(A[i], A[j]);
        i++;
        j--;
    }
}

//方法二：单链表
void reverselist(ListNode* head) {
    ListNode* first = head->next;

    ListNode* prev = nullptr;
    ListNode* curr = first;
    ListNode* next = curr->next;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    first = prev;

    head->next = first;
}

int main()
{
    cout << "list:" << endl;
    ListNode list{};
    for (int i = 1; i < 10; i++)
    {
        addListNode(&list, i * 2 + rand() % 100);
        //addListNode(&list, i * 2 + rand()%100);
    }
    printNode(&list);
    reverselist(&list);
    printNode(&list);
    cout << "----------------------" << endl;
    cout << "vector:" << endl;
    vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
    for (auto n : vec)
        cout << n << ' ';
    cout << endl;

    reversevector(vec);
    for (auto n : vec)
        cout << n << ' ';
    cout << endl;

    reverse(vec.begin(), vec.end());
    for (auto n : vec)
        cout << n << ' ';
    cout << endl;
}