class Solution {
  public:
    // Function should return all the ancestor of the target node
    vector<int> ans;
    void solve(Node *root, int &target, vector<int> &temp){
        if(!root) return;
        if(root->data == target){
            ans = temp;
            return;
        }
        temp.push_back(root->data);
        solve(root->left, target, temp);
        solve(root->right, target, temp);
        temp.pop_back();
    }
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        vector<int> temp;
        solve(root, target, temp);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};