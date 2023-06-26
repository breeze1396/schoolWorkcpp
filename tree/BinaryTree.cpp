#include "BinaryTree.h"

//使用广义表创建二叉树函数, 以'#'字符代表结束
void BinaryTree::CreateBinTree(const string& str)
{
    stack<BinTreeNode*> s;
    BinTreeNode* BT = nullptr;
    BinTreeNode* p{}, * t{}; //p用来记住当前创建的节点，t用来记住栈顶的元素
    int k = 0, i = 0;

    while (str[i] != RefValue)
    {
        switch (str[i])
        {
        case '(': 
            s.push(p);
            k = 1;
            break;

        case ')': 
            s.pop();
            break;

        case ',':
            k = 2;
            break;

        default:
            p = new BinTreeNode(str[i]); //构造一个结点
            if (BT == nullptr)
            {
                BT = p;
            }
            else if (k == 1) //入左孩子
            {
                t = s.top();                
                t->leftChild = p;
            }
            else //入右孩子
            {
                t = s.top();
                t->rightChild = p;
            } 
        }
        ++i;
    }
    this->root = BT;
}

//创建二叉树(利用已知的二叉树的前序遍历创建)用'#'表示空结点
void BinaryTree::CreateBinTree_PreOrder(const string& s, BinTreeNode*& subTree)
{
    static int i=-1;
    if (i < s.size() || i<0)
    ++i;
        if (s[i] != RefValue)
        {
            subTree = new BinTreeNode(s[i]); //构造结点
            if (subTree == nullptr)
            {
                cout << "空间分配错误！" << endl;
                exit(1);
            }
            CreateBinTree_PreOrder(s, subTree->leftChild);  //递归创建左子树
            CreateBinTree_PreOrder(s, subTree->rightChild); //递归创建右子树
        }
        else
        {
            subTree = nullptr;
        }
}

//使用先序遍历和中序遍历创建二叉树
void BinaryTree::CreateBinTreeBy_Pre_In(BinTreeNode*& cur, const char* pre, const char* in, int n)
{
    if (n <= 0)
    {
        cur = nullptr;
        return;
    }
    int k = 0;
    while (pre[0] != in[k]) //再中序中找到pre[0]的值
    {
        k++;
    }
    cur = new BinTreeNode(in[k]); //创建结点
    CreateBinTreeBy_Pre_In(cur->leftChild, pre + 1, in, k);
    CreateBinTreeBy_Pre_In(cur->rightChild, pre + k + 1, in + k + 1, n - k - 1);
}

//使用后序遍历和中序遍历创建二叉树
void BinaryTree::CreateBinTreeBy_Post_In(BinTreeNode*& cur, const char* post, const char* in, int n)
{
    if (n == 0)
    {
        cur = nullptr;
        return;
    }

    char r = *(post + n - 1);    //根结点值
    cur = new BinTreeNode(r); //构造当前结点

    int k = 0;
    const char* p = in;
    while (*p != r)
    {
        k++;
        p++;
    }
    CreateBinTreeBy_Post_In(cur->leftChild, post, in, k);
    CreateBinTreeBy_Post_In(cur->rightChild, post + k, p + 1, n - k - 1);
}

//二叉树的遍历(递归)
void BinaryTree::PreOrder(BinTreeNode*& subTree)
{
    if (subTree != nullptr)
    {
        cout << subTree->data << " ";
        PreOrder(subTree->leftChild);
        PreOrder(subTree->rightChild);
    }
}
void BinaryTree::InOrder(BinTreeNode*& subTree)
{
    if (subTree != nullptr)
    {
        InOrder(subTree->leftChild);
        cout << subTree->data << " ";
        InOrder(subTree->rightChild);
    }
}
void BinaryTree::PostOrder(BinTreeNode*& subTree)
{
    if (subTree != nullptr)
    {
        PostOrder(subTree->leftChild);
        PostOrder(subTree->rightChild);
        cout << subTree->data << " ";
    }
}

//二叉树先序遍历(非递归1)
void BinaryTree::PreOrder_NoRecurve1(BinTreeNode* p)
{
    stack<BinTreeNode*> S;
    S.push(nullptr); //最先push一个nullptr，到最后一个结点没有左右子树时，栈里只有一个nullptr了，令指针p指向这个nullptr，再判断就会结束循环
    while (p != nullptr)
    {
        cout << p->data << " ";
        if (p->rightChild != nullptr) //预留右子树指针在栈中
        {
            S.push(p->rightChild);
        }

        if (p->leftChild != nullptr) //进左子树
        {
            p = p->leftChild;
        }
        else //左子树为空
        {
            p = S.top();
            S.pop();
        }
    }
}

//二叉树先序遍历(非递归2)
void BinaryTree::PreOrder_NoRecurve2(BinTreeNode* p)
{
    stack<BinTreeNode*> S;
    BinTreeNode* t;
    S.push(p);         //根节点进栈
    while (!S.empty()) //当栈不为空
    {
        t = S.top(); //p先记住栈顶元素，然后栈顶出栈
        S.pop();
        cout << t->data << " ";    //访问元素
        if (t->rightChild != nullptr) //右孩子不为空，右孩子近栈
        {
            S.push(t->rightChild);
        }
        if (t->leftChild != nullptr) //左孩子不为空，左孩子进栈
        {
            S.push(t->leftChild);
        }
    }
}

//二叉树的中序遍历(非递归)
void BinaryTree::InOrder_NoRecurve(BinTreeNode* p)
{
    stack<BinTreeNode*> S;
    do
    {
        while (p != nullptr)
        {
            S.push(p);
            p = p->leftChild;
        }
        if (!S.empty())
        {
            p = S.top();
            S.pop();
            cout << p->data << " ";
            p = p->rightChild;
        }
    } while (p != nullptr || !S.empty());
}

//二叉树的后序遍历(非递归)
void BinaryTree::PostOrder_NoRecurve(BinTreeNode* p)
{
    if (root == nullptr)
        return;
    stack<BinTreeNode*> s;
    s.push(p);
    BinTreeNode* lastPop = nullptr;
    while (!s.empty())
    {
        while (s.top()->leftChild != nullptr)
            s.push(s.top()->leftChild);
        while (!s.empty())
        {
            //右叶子结点 || 没有右结点
            if (lastPop == s.top()->rightChild || s.top()->rightChild == nullptr)
            {
                cout << s.top()->data << " ";
                lastPop = s.top();
                s.pop();
            }
            else if (s.top()->rightChild != nullptr)
            {
                s.push(s.top()->rightChild);
                break;
            }
        }
    }
}

//二叉树的层次遍历(非递归遍历)
void BinaryTree::LevelOrder(BinTreeNode* p)
{
    queue<BinTreeNode*> Q;
    Q.push(p); //根节点进队
    BinTreeNode* t;
    while (!Q.empty())
    {
        t = Q.front(); //t先记住队头,再将队头出队
        Q.pop();
        cout << t->data << " "; //访问队头元素的数据

        if (t->leftChild != nullptr)
        {
            Q.push(t->leftChild);
        }

        if (t->rightChild != nullptr)
        {
            Q.push(t->rightChild);
        }
    }
}

//从结点subTree开始，搜索结点current的父节点,找到返回父节点的地址，找不到返回nullptr
BinTreeNode* BinaryTree::Parent(BinTreeNode* subTree, BinTreeNode* current)
{
    if (subTree == nullptr)
    {
        return nullptr;
    }
    if (subTree->leftChild == current || subTree->rightChild == current) //如果找到，返回父节点subTree
    {
        return subTree;
    }
    BinTreeNode* p;
    if ((p = Parent(subTree->leftChild, current)) != nullptr) //递归在左子树中搜索
    {
        return p;
    }
    else
    {
        return Parent(subTree->rightChild, current); //递归右子树中搜索
    }
}

//二叉树的销毁
void BinaryTree::Destroy(BinTreeNode*& subTree)
{
    if (subTree != nullptr)
    {
        Destroy(subTree->leftChild);
        Destroy(subTree->rightChild);
        delete subTree;
        subTree = nullptr;
    }
}

//复制二叉树，返回一个指针，给出一个以originNode为根复制的二叉树的副本
BinTreeNode* BinaryTree::Copy(BinTreeNode* originNode)
{
    if (originNode == nullptr)
    {
        return nullptr;
    }
    BinTreeNode* temp = new BinTreeNode; //创建根结点
    temp->data = originNode->data;
    temp->leftChild = Copy(originNode->leftChild);
    temp->rightChild = Copy(originNode->rightChild);
    return temp;
}

//判断两颗二叉树是否相等
bool BinaryTree::equal(BinTreeNode* a, BinTreeNode* b)
{
    if (a == nullptr && b == nullptr) //两者都为空
    {
        return true;
    }
    if (a != nullptr && b != nullptr && a->data == b->data && equal(a->leftChild, b->leftChild) && equal(a->rightChild, b->rightChild)) //两者都不为空，且两者的结点数据相等，且两者的左右子树的结点都相等
    {
        return true;
    }
    return false;
}

//计算二叉树以subTree为根的结点的个数
int BinaryTree::Size(BinTreeNode* subTree) const
{
    if (subTree == nullptr) //递归结束，空树结点个数为0
    {
        return 0;
    }
    return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}

//计算二叉数以subTree为根的高度
int BinaryTree::Height(BinTreeNode* subTree)
{
    if (subTree == nullptr) //递归结束，空树高度为0
    {
        return 0;
    }
    int i = Height(subTree->leftChild);
    int j = Height(subTree->rightChild);
    return i < j ? j + 1 : i + 1;
}


void BinaryTree::PrintBinTree(BinTreeNode* BT)
{
    if (BT != nullptr) //树为空时结束递归
    {
        cout << BT->data;
        if (BT->leftChild != nullptr || BT->rightChild != nullptr)
        {
            cout << '(';
            if (BT->leftChild != nullptr)
            {
                PrintBinTree(BT->leftChild);
            }
            cout << ',';
            if (BT->rightChild != nullptr)
            {
                PrintBinTree(BT->rightChild);
            }
            cout << ')';
        }
    }
}

//翻转二叉树
void BinaryTree::InvertTree(BinTreeNode* originNode)
{
    if (originNode == nullptr)
        return;
    BinTreeNode* tempNode = originNode->leftChild;
    originNode->leftChild = originNode->rightChild;
    originNode->rightChild = tempNode;
    InvertTree(originNode->leftChild);
    InvertTree(originNode->rightChild);
}

void BinaryTree::printTree(BinTreeNode* root) {
    if (!root)return;
    auto tmp = root;
    std::vector<BinTreeNode*> intv = inorderTraversal(tmp);//中序遍历节点数组
    std::string template_str;//模板string，表示每行打印string的长度
    int location = 0;
    std::unordered_map<BinTreeNode*, int> first_locations;//存储节点对应在本行string中的首位置
    for (auto& i : intv) {
        location = template_str.size();
        //template_str += std::to_string(i->data) + " ";
        template_str += i->data; template_str += " ";
        first_locations[i] = location;
    }
    for (auto& i : template_str)i = ' ';//把模板全部置为空格方便后续使用
    //层序遍历
    std::queue<BinTreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int currentLevelSize = q.size();
        int cur_loc = 0;
        std::string tmp_str1 = template_str, tmp_str2 = template_str;//1为节点所在行，2为其下一行
        for (int i = 1; i <= currentLevelSize; ++i) {
            auto node = q.front();
            q.pop();
            cur_loc = first_locations[node];
            //std::string num_str = std::to_string(node->data);
            std::string num_str(1, node->data);
            //左边，如果存在左孩子，那么在第二行对应位置打印'/'，在第一行补上'_'
            if (node->leftChild) {
                q.push(node->leftChild);
                int first_loc = first_locations[node->leftChild] + 1;
                tmp_str2[first_loc++] = '/';
                while (first_loc < cur_loc)tmp_str1[first_loc++] = '_';

            }
            //中间,对应位置打印节点值（有可能为多位数）
            for (int j = 0; j < num_str.length(); ++j, ++cur_loc) {
                tmp_str1[cur_loc] = num_str[j];
            }
            //右边，如果存在右孩子，那么在第二行对应位置打印'\'，在第一行补上'_'
            if (node->rightChild) {
                q.push(node->rightChild);
                int last_loc = first_locations[node->rightChild] - 1;
                tmp_str2[last_loc] = '\\';
                while (cur_loc < last_loc) {
                    tmp_str1[cur_loc++] = '_';
                }
            }
        }
        //打印两行
        std::cout << tmp_str1 << std::endl;
        std::cout << tmp_str2 << std::endl;
    }
}











