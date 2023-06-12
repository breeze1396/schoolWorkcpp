#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<ctype.h>
using namespace std;

struct Node {
    char val;
    Node* next;
    Node(char n = ' ', Node* next_ = nullptr) :
        val(n), next(next_) {}
};

void addNode(Node* head, char n)
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
Node* crateList(string& s)
{
    Node* list = new Node{ -1, nullptr };
    for (int i = 0; i < s.size(); i++)
    {
        addNode(list, s[i]);
    }
    return list;
}
void printNode(Node* head)
{
    if (head==nullptr) return;
    Node* p = head->next;
    while (p)
    {
        std::cout << p->val << ' ';
        p = p->next;
    }
    std::cout << endl;
}

string list_to_string(Node* l)
{
    string s;
    l = l->next;
    while (l)
    {
        s += l->val;
        l = l->next;
    }
    return s;
}
Node* string_to_list(string& s)
{
    Node* list = new Node{ -1, nullptr };
    for (int i = 0; i < s.size(); i++)
    {
        addNode(list, s[i]);
    }
    return list;
}
string reverseFirstMatch(string s, string t) {
    if (s.empty() || t.empty()) {
        return s;
    }
    int pos = s.find(t);
    if (pos != string::npos) {
        reverse(s.begin() + pos, s.begin() + pos + t.length());
    }
    return s;
}



int main() {
    string sString = "hello_world";
    string tString = "lo_wor";
    Node* sHead = crateList(sString);
    Node* tHead = crateList(tString);
    

    printNode(sHead);
    printNode(tHead);
    string s = list_to_string(sHead);
    string t = list_to_string(tHead);
    string ans = reverseFirstMatch(s, t);

    sHead = crateList(ans);
    
    printNode(sHead);
}
