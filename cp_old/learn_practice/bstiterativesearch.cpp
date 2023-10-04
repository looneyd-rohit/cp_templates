#include <bits/stdc++.h>
using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
};

tree *createNode(int data)
{
    tree *e = new tree();
    e->data = data;
    e->left = NULL;
    e->right = NULL;
    return e;
}

bool isBST(tree *node)
{
    static tree *predecessor = NULL;
    if (node != NULL)
    {
        if (!isBST(node->left))
            return false;

        if (predecessor != NULL && (predecessor->data >= node->data))
            return false;

        predecessor = node;
        return isBST(node->right);
    }
    else
    {
        return true;
    }
}

bool iterativeBST(tree *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return true;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int main()
{
    // tree structure
    tree *root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(4);

    // iterative search for this tree
    cout << iterativeBST(root, 4) << endl;
    return 0;
}