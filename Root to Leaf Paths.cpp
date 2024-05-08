
class Solution {
  public:
    void solve(Node* root, vector<int> v, vector<vector<int>> &res){
        if(!root)
            return;
        v.push_back(root->data);
        if(!root->left && !root->right)
            res.push_back(v);
        solve(root->left, v, res);
        solve(root->right, v, res);
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> res;
        vector<int> v;
        solve(root, v, res);
        return res;
    }
};