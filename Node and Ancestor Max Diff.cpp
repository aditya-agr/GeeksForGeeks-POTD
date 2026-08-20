class Solution {
  public:
    void solve(int &res, Node *root, int mx){
        if(root == NULL)
            return;
        if(mx != INT_MIN)
            res = max(res, mx-root->data);
        mx = max(mx, root->data);
        solve(res, root->left, mx);
        solve(res, root->right, mx);
        
    }
    int maxDiff(Node* root) {
        // code here
        int res = INT_MIN;
        solve(res, root, INT_MIN);
        return res;
    }
};