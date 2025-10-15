class Solution {
  public:
    void solve(Node* root, int &k, int &res){
        if(!root)
            return;
        solve(root->left, k, res);
        k--;
        if(k == 0){
            res = root->data;
            return;
        }
        solve(root->right, k, res);
    }
    int kthSmallest(Node *root, int k) {
        // code here
        int res = -1;
        solve(root, k, res);
        return res;
    }
};