#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left, * right;
    Node(int x) : key(x), left(NULL), right(NULL) {}
};

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

Node* insert(Node* node, int key) {
    if (node == NULL) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    for (int i = 0; i < 10; i++) {
        root = insert(root, rand() % 100);
    }

    inorder(root);
    cout << endl;

    int key = 24;
    if (search(root, key) == NULL)
        cout << key << " not found" << endl;
    else
        cout << key << " found" << endl;

    return 0;
}
