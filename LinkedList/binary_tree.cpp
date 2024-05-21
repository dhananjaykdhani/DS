#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
public:
    Node *root;
    BinaryTree()
    {
        root = NULL;
    }
    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (root == NULL)
        {
            root = newNode;
            return;
        }
        Node *temp = root;
        while (temp != NULL)
        {
            if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
        }
    }
    void print(Node *root)
    {
        if (root == NULL)
            return;
        print(root->left);
        cout << root->data << " ";
        print(root->right);
    }
};

int main()
{
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);
    tree.print(tree.root);
    return 0;
}
