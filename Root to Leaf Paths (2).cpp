class Solution {
  public:
    vector<vector<int>> res;
    vector<int> ans;
    void solve(Node* root){
        if(!root)
            return;
        ans.push_back(root->data);
        if(!root->left && !root->right){
            res.push_back(ans);
        }
        solve(root->left);
        solve(root->right);
        ans.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        solve(root);
        return res;
    }
};