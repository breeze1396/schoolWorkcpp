#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include<iomanip>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;
//二叉树结点类型定义
struct BinTreeNode
{
    char data;
    BinTreeNode* leftChild, * rightChild;
    BinTreeNode(char x = 0, BinTreeNode* l = nullptr, BinTreeNode* r = nullptr) : 
        data(x), leftChild(l), rightChild(r) {}
};

class BinaryTree
{
public:
    BinaryTree() : root(nullptr), RefValue('#') {}
    BinaryTree(int value) : root(nullptr), RefValue(value) {}
    ~BinaryTree() { Destroy(root); }
    BinaryTree(BinaryTree& s) { root = Copy(s.getRoot()); }    //拷贝二叉树(前序遍历的应用)

    //使用广义表创建二叉树，以'#'字符代表结束
    void CreateBinTree(const string& s);

    //前序遍历创建二叉树(前序遍历的应用)，用#表示空结点
    void CreateBinTree_PreOrder(const string& s) { CreateBinTree_PreOrder(s,root); }
    void CreateBinTree_PreOrder(const string & s, BinTreeNode*& subTree);

    //使用先序遍历和中序遍历创建二叉树
    void CreateBinTreeBy_Pre_In(const char* pre, const char* in) 
    { CreateBinTreeBy_Pre_In(root, pre, in, strlen(pre)); };

    //使用后序遍历和中序遍历创建二叉树
    void CreateBinTreeBy_Post_In(const char* post, const char* in) 
    { CreateBinTreeBy_Post_In(root, post, in, strlen(post)); };

    //递归：先序，中序，后序
    void PreOrder() { PreOrder(root); }
    void InOrder() { InOrder(root); }
    void PostOrder() { PostOrder(root); }

    //先序遍历(非递归1)
    void PreOrder_NoRecurve1() { PreOrder_NoRecurve1(root); }
    //先序遍历(非递归2)
    void PreOrder_NoRecurve2() { PreOrder_NoRecurve2(root); }
    //中序遍历(非递归)
    void InOrder_NoRecurve() { InOrder_NoRecurve(root); }
    //后序遍历(非递归)
    void PostOrder_NoRecurve() { PostOrder_NoRecurve(root); }
    //层次遍历(非递归)
    void LevelOrder() { LevelOrder(root); }

    //获取二叉树的根节点
    BinTreeNode* getRoot() const 
    { return root; }

    //获取current结点的父节点
    BinTreeNode* Parent(BinTreeNode* current) 
    { return (root == nullptr || root == current) ? nullptr : Parent(root, current); } //如果没有根节点或current结点就是root结点，就没有父节点
    
    //获取current结点的左结点
    BinTreeNode* LeftChild(BinTreeNode* current) 
    { return (current != nullptr) ? current->leftChild : nullptr; }
    
    //获取current结点的右结点
    BinTreeNode* RightChild(BinTreeNode* current) 
    { return (current != nullptr) ? current->rightChild : nullptr; }

    //销毁函数
    void Destroy() { Destroy(root); };

    //判断两颗二叉树是否相等(前序遍历的应用)
    bool operator==(BinaryTree& s) 
    { return (equal(this->getRoot(), s.getRoot())); }

    //计算二叉树的结点的个数(后序遍历的应用)
    int Size() { return Size(root); }

    //计算二叉树的高度（后序遍历的应用）
    int Height() { return Height(root); }

    //判断二叉树是否为空
    bool Empty() { return (root == nullptr) ? true : false; }

    //以广义表的形式输出二叉树(前序遍历的应用)
    void PrintBinTree() { PrintBinTree(root); }

    //翻转二叉树
    void InvertTree() { InvertTree(root); }

    //稍微可视化的观看
    void printTreeInP() 
    { printTreeInP(root); }
    void printTreeInP(BinTreeNode* root, int indent = 0) {
        if (root == nullptr) return;
        printTreeInP(root->rightChild, indent + 4);
        if (indent != 0) {
            cout << setw(indent) << " ";
            cout << "+---";
        }
        cout << root->data << endl;
        printTreeInP(root->leftChild, indent + 4);
    }

    //更强的可视化
    std::vector<BinTreeNode*> inorderTraversal(BinTreeNode* root) {
        std::vector<BinTreeNode*> res;
        std::stack<BinTreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->leftChild;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root);
            root = root->rightChild;
        }
        return res;
    }
    void printTree()
    {
        printTree(root);
    }
    void printTree(BinTreeNode* root);









protected:
    void CreateBinTreeBy_Pre_In(BinTreeNode*& cur, const char* pre, const char* in, int n);
    void CreateBinTreeBy_Post_In(BinTreeNode*& cur, const char* post, const char* in, int n);
   
    void PreOrder(BinTreeNode*& subTree);
    void InOrder(BinTreeNode*& subTree);
    void PostOrder(BinTreeNode*& subTree);
    void PreOrder_NoRecurve1(BinTreeNode* p);
    void PreOrder_NoRecurve2(BinTreeNode* p);
    void InOrder_NoRecurve(BinTreeNode* p);
    void PostOrder_NoRecurve(BinTreeNode* p);
    void LevelOrder(BinTreeNode* p);


    BinTreeNode* Parent(BinTreeNode* subTree, BinTreeNode* current);
    void Destroy(BinTreeNode*& subTree);
    BinTreeNode* Copy(BinTreeNode* originNode);
    bool equal(BinTreeNode* a, BinTreeNode* b);
    int Size(BinTreeNode* subTree) const;
    int Height(BinTreeNode* subTree);

    //以广义表的形式输出二叉树
    void PrintBinTree(BinTreeNode* BT);  
    void InvertTree(BinTreeNode* originNode);

 
private:
    BinTreeNode* root;
    int RefValue = 0;           //数据输入停止的标志，需要一个构造函数
};

