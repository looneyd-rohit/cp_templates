#include <bits/stdc++.h>
using namespace std;
#define max(a,b) ((a)>(b))?(a):(b)

struct tree
{
    int data;
    tree *left;
    tree *right;
    int height;
    int balance_factor;
};

int getHeight(tree* node){
    if(node==NULL){
        return -1;
    }
    // int left= getHeight(node->left);
    // int right= getHeight(node->right);
    // node->height=max(left,right)+1;
    // return node->height+1;

    int l = getHeight(node->left);
    int r = getHeight(node->right);
     
    if(l>r){
    return l+1;
    }
    else{
    return r+1;
    }
}

int getBalanceFactor(tree* node){
    if(node==NULL ){
        return 0;
    }
    return (getHeight(node->left) - getHeight(node->right));
}

tree *createNode(int data)
{
    tree *e = new tree();
    e->data = data;
    e->left = NULL;
    e->right = NULL;
    e->height=0;
    e->balance_factor=0;
    return e;
}

void showTree(tree *node)
{
    if (node != NULL)
    {
        showTree(node->left);
        node->height=getHeight(node);
        node->balance_factor=getBalanceFactor(node);
        cout << node->data <<" "<<"height = "<<node->height<< " "<<"balance_factor = "<<node->balance_factor<<endl;;
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

bool iterativeSearchBST(tree *root, int key)
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

bool recursiveSearchBST(tree *root, int key)
{
    if (root != NULL)
    {
        if (root->data == key)
            return true;
        else if (root->data > key)
            return recursiveSearchBST(root->left, key);
        else
            return recursiveSearchBST(root->right, key);
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
    return 0; // element not found so returns 0
}

tree *findInOrderPreNodeBST(tree *node)
{
    node = node->left;
    while (node->right != NULL)
    {
        node = node->right;
    }
    return node;
}

tree *inOrderDeleteBST(tree *root, int key)
{
    // if (root == NULL)
    //     return NULL;

    if (root->data == key)
    {
        if (root->left == NULL)
        {
            tree *t = root->right;
            delete root;
            return t;
        }
        else if (root->right == NULL)
        {
            tree *t = root->left;
            delete root;
            return t;
        }
        tree *inOrderPre = findInOrderPreNodeBST(root);
        root->data = inOrderPre->data;
        root->left = inOrderDeleteBST(root->left, key);
    }
    else if (root->data > key)
    {
        root->left = inOrderDeleteBST(root->left, key);
    }
    else
    {
        root->right = inOrderDeleteBST(root->right, key);
    }
    return root;
}

// rotation towards right
tree* llRotation(tree* node){
    tree* l = node->left;
    tree* temp = l->right;
    l->right = node;
    node->left= temp;
    return l;
}

// rotation towards left
tree* rrRotation(tree* node){
    tree* r = node->right;
    tree* temp = r->left;
    r->left = node;
    node->right= temp;
    return r;
}

void updateHandBF(tree* node){
    if(node==NULL)
    return;

    // getHeight(node);
    updateHandBF(node->left);
    node->height=getHeight(node);
    node->balance_factor=getBalanceFactor(node);
    updateHandBF(node->right);
}

int main()
{
    // tree structure
    // tree *root = createNode(5);
    // root->left = createNode(3);
    // root->right = createNode(6);
    // root->left->left = createNode(1);
    // root->left->right = createNode(4);

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

    // showTree(root);
    // cout << endl;
    // cout << inOrderDeleteBST(root, 5)->data << endl;
    // showTree(root);


    // AVL trees
    tree *root = createNode(10);
    // iterativeInsertionBST(root,5);
    // iterativeInsertionBST(root,4);
    // iterativeInsertionBST(root,3);
    // iterativeInsertionBST(root,2);
    // iterativeInsertionBST(root,15);
    root->left = createNode(5);
    root->left->left = createNode(4);
    root->left->left->left = createNode(3);
    root->left->left->left->left = createNode(2);
    root->right=createNode(15);

    // updateHandBF(root);
    // getHeight(root);



    cout<<root->data<<" ";
    cout<<root->left->data<<" ";
    cout<<root->left->left->data<<" ";
    cout<<root->left->left->left->data<<" ";
    cout<<root->left->left->left->left->data<<" ";
    cout<<root->right->data<<" "<<endl;

    // cout<<getHeight(root)<<endl;

    // getHeight(root);
    // updateHandBF(root);
    showTree(root);

    inOrderDeleteBST(root,15);
    // updateHandBF(root);
    showTree(root);


    

    return 0;
}