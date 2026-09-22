#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::max;

class Node {

    public:
    int data;
    Node* left ,*right;

    Node(int data) {
        this->data=data;
        left=right=nullptr;
    }
};

static int idx=-1;

Node* buildTree(vector<int> preOrder) {
    idx++;

    if(preOrder[idx] == -1) return NULL;

    Node*root= new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

void preorder(Node *root) {
    if(root==nullptr) return;

    std::cout<<root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

int height(Node* root) {
    if (root == nullptr)
        return 0;

    int h1 = height(root->left);
    int h2 = height(root->right);

    return 1 + std::max(h1, h2);
}

int main() {
    vector<int> pre = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(pre);

    preorder(root);

    std::cout<<"HEIGHT : " << height(root)<<std::endl;
    return 0;
}