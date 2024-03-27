class DynamicSGTreeLazy{
public:
    int val;
    int lazy;
    DynamicSGTreeLazy *left, *right;
    DynamicSGTreeLazy(int val=0, int lazy=0){
        this->val = val;
        this->lazy = lazy;
        this->left = NULL;
        this->right = NULL;
    }
};

// helper -> performs range updates in a lazy manner
void helper(DynamicSGTreeLazy* root, int low, int high, int l, int r, int v){
    // since it is a dynamic segment tree we need to create childs dynamically
    if(low!=high){
        // child should exist
        if(!root->left) root->left = new DynamicSGTreeLazy();
        if(!root->right) root->right = new DynamicSGTreeLazy();
    }
    
    // since it is lazy updates, check pending updates
    if(root->lazy!=0){
        // updates are remaining
        root->val += root->lazy;
        // propagate the updates to childs
        if(low!=high){
            root->left->lazy += root->lazy;
            root->right->lazy += root->lazy;
        }
        // remove the pending update
        root->lazy = 0;
    }
    
    // since it is lazy segment tree (dynamic also)
    // we need to check range ovelaps
    
    // 1. no overlap
    if(r<low || high<l) return;
    
    // 2. full ovelap
    if(l<=low && high<=r){
        // perform lazy update on the node
        root->val += v;
        // propagate the updates to childs
        if(low!=high){
            root->left->lazy += v;
            root->right->lazy += v;
        }
        return;
    }
    
    // 3. partial overlap
    int mid = low + ((high - low) >> 1);
    helper(root->left, low, mid, l, r, v);
    helper(root->right, mid+1, high, l, r, v);
    
    // finally update current node after childs are updated
    root->val = max(root->left->val, root->right->val);
}