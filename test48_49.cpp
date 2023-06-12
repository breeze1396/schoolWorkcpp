#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<ctype.h>
#include<string>
#include<map>
#include<utility>
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
        addNode(list, rand() % 100 );
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

void selection_sort(Node* head) {
    for (Node* i = head; i; i = i->next) {
        Node* min_node = i;
        for (Node* j = i->next; j; j = j->next) {
            if (j->val < min_node->val) min_node = j;
        }
        swap(i->val, min_node->val);
    }
}

Node * insertion_sort(Node * head) {
    Node* dummy = new Node{ 0, nullptr };
    while (head) {
        Node* curr = head;
        head = head->next;
        Node* prev = dummy;

        while (prev->next && ((prev->next->val) > curr->val))
            prev = prev->next;
        curr->next = prev->next;
        prev->next = curr;
    }
    return dummy->next;
}
void insertion_sort1(Node* head) //有点问题
{
    Node* p = head->next,
        * start = p,
        * move = head,
        * temp = nullptr;
    while (p) {
        if (p->next && p->next->val > p->val)
        {
            while (move->next && move->next->val > p->next->val)
                move = move->next;

            temp = p->next;
            p->next = temp->next;
            temp->next = move->next;
            move->next = temp;
            move = head->next;
        }
        else
        {
            p = p->next;
        }
    }

}

void insertionSortList(Node* head) {
    if (!head || !head->next || !head->next->next) return;

    Node* move = head,
        * p = head->next,
        *temp = nullptr;
    while (p) {
        if (p->next && p->next->val > p->val) {
            while (move->next && move->next->val > p->next->val)
                move = move->next;

            temp = move->next;
            move->next = p->next;
            p->next = p->next->next;
            move->next->next = temp;
            move = head;
        }
        else {
            p = p->next;
        }
    }
}


int main()
{
    //Node* l1 = crateList();
    //printNode(l1);
    //selection_sort(l1);
    //printNode(l1);

    //cout << "-----------------------------------" << endl;
    Node* l2 = crateList();
    printNode(l2);
    insertion_sort1(l2);
    //insertionSortList(l2);
    printNode(l2);

}
