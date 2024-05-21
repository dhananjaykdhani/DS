// Order Binary Tree
#include <iostream>
using namespace std;

class BinaryTree
{
public:
    int data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void preorder(BinaryTree *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(BinaryTree *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(BinaryTree *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    BinaryTree *root = new BinaryTree(10);
    root->left = new BinaryTree(20);
    root->right = new BinaryTree(30);
    root->left->left = new BinaryTree(40);
    root->left->right = new BinaryTree(50);
    root->right->left = new BinaryTree(60);
    root->right->right = new BinaryTree(70);
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    return 0;
}