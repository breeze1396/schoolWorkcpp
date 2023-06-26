#pragma once

struct ListNode {
    char data;
    ListNode* next;
};

//37
int count_nodes(BinaryTree* r) {
    if (!r)  return 0;
    int count = 0;
    queue<BinTreeNode*> q;
    q.push(r->getRoot());
    while (!q.empty()) {
        BinTreeNode* node = q.front();
        q.pop();
        count++;
        if (node->leftChild) q.push(node->leftChild);
        if (node->rightChild) q.push(node->rightChild);
    }
    return count;
}

//38叶子节点
int count_leaf_nodes(BinaryTree* r) {
    if (!r)  return 0;
    int count = 0;
    queue<BinTreeNode*> q;
    q.push(r->getRoot());
    while (!q.empty()) {
        BinTreeNode* node = q.front();
        q.pop();
        if (!node->leftChild && !node->rightChild) count++;
        if (node->leftChild) q.push(node->leftChild);
        if (node->rightChild) q.push(node->rightChild);
    }
    return count;
}


//39
void connect_leaf_nodes(BinTreeNode* root, ListNode*& prev) {
    if (!root) return;
    if (!root->leftChild && !root->rightChild) {
        ListNode* curr = new ListNode{ root->data, nullptr };
        if (prev) prev->next = curr;
        prev = curr;
        return;
    }
    connect_leaf_nodes(root->leftChild, prev);
    connect_leaf_nodes(root->rightChild, prev);
}
ListNode* connect_leaf_nodes(BinaryTree* r) {
    ListNode* dummy = new ListNode{ 0, nullptr };
    ListNode* prev = dummy;
    connect_leaf_nodes(r->getRoot(), prev);
    return dummy->next;
}


//40
int tree_depth(BinaryTree* r) {
    if (!r) return 0;
    int depth = 0;
    queue<BinTreeNode*> q;
    q.push(r->getRoot());
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            BinTreeNode* node = q.front();
            q.pop();
            if (node->leftChild) q.push(node->leftChild);
            if (node->rightChild) q.push(node->rightChild);
        }
        depth++;
    }
    return depth;
}

//41节点在那一层数
map<BinTreeNode*, int> node_levels1(BinaryTree* r) {
    map<BinTreeNode*, int> levels;
    if (!r) return levels;
    int level = 1;
    queue<BinTreeNode*> q;
    q.push(r->getRoot());
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            BinTreeNode* node = q.front();
            q.pop();
            levels[node] = level;
            if (node->leftChild) q.push(node->leftChild);
            if (node->rightChild) q.push(node->rightChild);
        }
        level++;
    }
    return levels;
}

//42层次遍历
vector<vector<char>> level_order_traversal(BinaryTree* r)
{
    vector<vector<char>> result;
    if (!r) return result;
    queue<BinTreeNode*> q;
    q.push(r->getRoot());
    while (!q.empty()) {
        int size = q.size();
        vector<char> level;
        for (int i = 0; i < size; i++) {
            BinTreeNode* node = q.front();
            q.pop();
            level.push_back(node->data);
            if (node->leftChild) q.push(node->leftChild);
            if (node->rightChild) q.push(node->rightChild);
        }
        result.push_back(level);
    }
}
    //43 左右子树
void swap_subtrees(BinaryTree* r)
{
    if (!r) return;
    queue<BinTreeNode*> q;
    q.push(r->getRoot());
    while (!q.empty()) {
        BinTreeNode* node = q.front();
        q.pop();
        swap(node->leftChild, node->rightChild);
        if (node->leftChild) q.push(node->leftChild);
         if (node->rightChild) q.push(node->rightChild);
    }
}

// 44、	用非递归算法求出值为x的结点的所有祖先结点。
vector<BinTreeNode*> find_ancestors(BinaryTree* r, char x)
{
        vector<BinTreeNode*> result;
        BinTreeNode* root = r->getRoot();
        if (!r) return result;
        stack<BinTreeNode*> s;
        unordered_map<BinTreeNode*, BinTreeNode*> parent;
        s.push(root);
        while (!s.empty()) {
            BinTreeNode* node = s.top();
            s.pop();
            if (node->data == x) {
                while (node != root) {
                    result.push_back(parent[node]);
                    node = parent[node];
                }
                reverse(result.begin(), result.end());
                return result;
            }
            if (node->rightChild) {
                s.push(node->rightChild);
                parent[node->rightChild] = node;
            }
            if (node->leftChild) {
                s.push(node->leftChild);
                parent[node->leftChild] = node;
            }
        }
        return result;
}

