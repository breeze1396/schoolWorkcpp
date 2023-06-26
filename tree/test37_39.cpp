#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include "BinaryTree.h"
#include"testFunction.h"
using namespace std;

void TEST()
{
    BinaryTree tree;

    //通过广义表创建二叉树
     tree.CreateBinTree("A(B(C(D,E)),15,M(N,O(P(Q,R),S(T,),I(J(K,L)))),U(V,W(X,Y(Z))))#"); //input: A(B(D,E(G,)),C(,F))#
     tree.printTree();
     //tree.PrintBinTree();  //print: A(B(D,E(G,)),C(,F))
     //cout << endl;

    //通过前序遍历创建二叉树
    //tree.CreateBinTree_PreOrder("ABD##EG###C#F##"); // input: ABD##EG###C#F##
    // tree.PrintBinTree();           // print: A(B(D,E(G,)),C(,F))

    //使用前序遍历和中序遍历创建二叉树
    //tree.CreateBinTreeBy_Pre_In("ABDEGCF", "DBGEACF");
    //tree.PrintBinTree(); // print: A(B(D,E(G,)),C(,F))
    //cout << endl;

    ////使用后序遍历和中序遍历创建二叉树
    //tree.CreateBinTreeBy_Post_In("DGEBFCA", "DBGEACF");
    //tree.PrintBinTree(); // print: A(B(D,E(G,)),C(,F))
    // cout << endl;

    ////二叉树的先序遍历(递归)
    // tree.PreOrder(); // print: A B D E G C F
    // cout << endl;

    ////二叉树的中序遍历(递归)
    // tree.InOrder(); // print: D B G E A C F
    // cout << endl;

    ////二叉树的后序遍历(递归)
    // tree.PostOrder(); // print: D G E B F C A
    // cout << endl;

    //二叉树先序遍历(非递归1)
    // tree.PreOrder_NoRecurve1(); // print: A B D E G C F

    //二叉树先序遍历(非递归2)
    // tree.PreOrder_NoRecurve2(); // print: A B D E G C F

    //中序遍历(非递归)
    // tree.InOrder_NoRecurve(); // print: D B G E A C F

    //二叉树的后序遍历(非递归)
    // tree.PostOrder_NoRecurve(); // print: D G E B F C A

    //二叉树的层次遍历(非递归)
    // tree.LevelOrder(); // print: A B C D E F G

    //二叉树的Size
    // cout << tree.Size() << endl; // print: 7

    //二叉树的销毁
    // tree.Destroy();
    // cout << tree.Size() << endl; // print: 0
    //二叉树是否为空
    // cout << tree.Empty() << endl; // print: 1

    //二叉树的高度
    // cout << tree.Height() << endl; // print: 4

    //拷贝二叉树
    // BinaryTree<char> tree2 = tree;
    // tree2.PrintBinTree(); // print: A(B(D,E(G,)),C(,F))

    //判断两颗二叉树是否相等
    // cout << (tree2 == tree) << endl; // print: 1

    //翻转二叉树
    // tree2.InvertTree();
    // tree2.PrintBinTree(); //print: A(C(F,),B(E(,G),D))
}

bool cmp(pair<BinTreeNode*, int>& l, pair<BinTreeNode*, int>& r)
{
    // 如果value相等，比较key值
    if (l.second == r.second)
        return l.first->data < r.first->data;
    else
        // 否则比较value值
        return  l.second < r.second;
}


void test37_38_40()
{
    BinaryTree tree;
    tree.CreateBinTree("A(B(D(X,Y(,Z)),E(G,)),C(G(H,I(J(K,O),)),F))#");
    tree.printTree();
    cout << "节点个数为：" << count_nodes(&tree) << endl;
    cout << "叶子节点个数为：" << count_leaf_nodes(&tree) << endl;
    cout << "树的高度为：" << tree_depth(&tree) << endl;
}
void test39()
{
    BinaryTree tree;
    tree.CreateBinTree("A(B(D(X,Y(,Z)),E(G,)),C(G(H,I(J(K,O),)),F))#");
    tree.printTree();
    ListNode* ans = connect_leaf_nodes(&tree),
        * p=ans;
    while (p)
    {
        cout << p->data << "  ";
        p = p->next;
    }
}
void test41()
{
    BinaryTree tree;
    tree.CreateBinTree("A(B(D(X,Y(,Z)),E(G,)),C(G(H,I(J(K,O),)),F))#");
    tree.printTree();
    map<BinTreeNode*, int> a = node_levels1(&tree);
    vector<pair<BinTreeNode*, int>> vec{};
    for (auto& n : a)
        vec.emplace_back(n);

    sort(vec.begin(), vec.begin(), cmp);

    for (auto& n : vec)
        cout << n.first->data << ' ' << n.second << endl;

}
void test42()
{
    BinaryTree tree;
    tree.CreateBinTree("A(B(D(X,Y(,Z)),E(G,)),C(G(H,I(J(K,O),)),F))#");
    tree.printTree();
    vector<vector<char>> ans = level_order_traversal(&tree);
    for (auto& a : ans)
    {
        for (auto& b : a)
        {
            cout << b << ' ';
        }
        cout << endl;
    }
}
void test43()
{
    BinaryTree tree;
    tree.CreateBinTree("A(B(D(X,Y(,Z)),E(G,)),C(G(H,I(J(K,O),)),F))#");
    tree.printTree();
    swap_subtrees(&tree);
    tree.printTree();
}
void test44()
{
    BinaryTree tree;
    tree.CreateBinTree("A(B(D(X,Y(,Z)),E(G,)),C(G(H,I(J(K,O),)),F))#");
    tree.printTree();

    vector<BinTreeNode*> ans = find_ancestors(&tree, 'O');
    vector<BinTreeNode*> ans1 = find_ancestors(&tree, 'K');
    cout << "O的所有祖节点：";
    for (auto& n : ans)
    {
        cout << n->data << ' ';
    }
    cout << "\nk的所有祖节点：";
    for (auto& n : ans1)
    {
        cout << n->data << ' ';
    }
    cout << endl;
}

int main()
{
    test44();

    return 0;
}
