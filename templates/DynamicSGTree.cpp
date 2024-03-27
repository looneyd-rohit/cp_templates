struct DynamicSGTree{
public:
    int val;
    DynamicSGTree *left, *right;
    DynamicSGTree(int val=0): val(val), left(NULL), right(NULL){
    }
};

void helper(DynamicSGTree* root, int low, int high, int l, int r, int v){
    // if current range has all marked then skip further markings
    if(root->val == (high-low+1)*v) return;
    
    // no overlap
    if(r<low || high<l) return;
    
    // full overlap
    if(l<=low && high<=r){
        root->val = (high-low+1) * v;
        return;
    }
    
    // partial overlap
    int mid = low + ((high - low) >> 1);
    if(!root->left) root->left = new DynamicSGTree();
    helper(root->left, low, mid, l, r, v);
    if(!root->right) root->right = new DynamicSGTree();
    helper(root->right, mid+1, high, l, r, v);
    
    // update
    root->val = root->left->val + root->right->val;
}