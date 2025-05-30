class Solution {
  public:
    int res;
    void solve(Node* root, int k){
        if(!root)
            return;
        solve(root->left, k);
        if(root->data <= k)
            res = root->data;
        solve(root->right, k);
    }
    int findMaxFork(Node* root, int k) {
        // code here
        res = -1;
        solve(root, k);
        return res;
    }
};