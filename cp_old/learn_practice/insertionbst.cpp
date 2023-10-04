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

void showTree(tree *node)
{
    if (node != NULL)
    {
        showTree(node->left);
        cout << node->data << " ";
        showTree(node->right);
    }
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

bool recursiveBST(tree *root, int key)
{
    if (root != NULL)
    {
        if (root->data == key)
            return true;
        else if (root->data > key)
            return recursiveBST(root->left, key);
        else
            return recursiveBST(root->right, key);
    }
    else
    {
        return false;
    }
}

int iterativeInsertionBST(tree *node, int key)
{
    while (node != NULL)
    {
        if (node->data == key)
        {
            return 0;
        }
        else if (node->data < key)
        {
            if (node->right == NULL)
            {
                node->right = createNode(key);
                return 1;
            }
            else
                node = node->right;
        }
        else
        {
            if (node->left == NULL)
            {
                node->left = createNode(key);
                return 1;
            }
            else
                node = node->left;
        }
    }
    return 0; // required only if tree is not there i.e. [root == NULL]
}

int recursiveInsertionBST(tree *node, int key)
{
    if (node != NULL)
    {
        if (node->data == key)
        {
            return 0;
        }
        else if (node->data < key)
        {
            if (node->right == NULL)
            {
                node->right = createNode(key);
                return 1;
            }
            else
                return recursiveInsertionBST(node->right, key);
        }
        else
        {
            if (node->left == NULL)
            {
                node->left = createNode(key);
                return 1;
            }
            else
                return recursiveInsertionBST(node->left, key);
        }
    }
    return 0;
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
    // cout << iterativeBST(root, 4) << endl;

    // recursive search for this tree
    // cout << recursiveBST(root, 9) << endl;

    // iterative insertion in a bst
    // cout << "old tree: ";
    // showTree(root);
    // cout << "\ninsertion status= " << iterativeInsertionBST(root, 4) << endl;
    // cout << "new tree: ";
    // showTree(root);

    // recursive insertion in a bst
    // cout << "old tree: ";
    // showTree(root);
    // cout << "\ninsertion status= " << recursiveInsertionBST(root, 4) << endl;
    // cout << "new tree: ";
    // showTree(root);

    return 0;
}