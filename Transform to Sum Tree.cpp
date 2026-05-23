class Solution {
  public:
    int solve(Node *root){
        if(!root)
            return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        int cur = l+r+root->data;
        root->data = l+r;
        return cur;
    }
    void toSumTree(Node *root) {
        // code here
        solve(root);
    }
};