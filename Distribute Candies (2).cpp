class Solution {
  public:
    int ops;
    int solve(Node *root){
        if(!root)
            return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        int cur = l+r+root->data-1;
        ops += abs(cur);
        return cur;
    }
    int distCandy(Node* root) {
        // code here
        ops = 0;
        solve(root);
        return ops;
    }
};