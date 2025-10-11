class Solution {
  public:
    int solve(Node* root, int &res){
        if(!root)
            return 0;
        int left = max(0, solve(root->left, res));
        int right = max(0, solve(root->right, res));
        res = max(res, root->data+left+right);
        return root->data + max(left, right);
    }
    int findMaxSum(Node *root) {
        // code here
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};