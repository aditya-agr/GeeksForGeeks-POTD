class Solution {
  public:
    int solve(Node* root, int &res){
        if(root == NULL)
            return 0;
        int left = solve(root->left, res);
        int right = solve(root->right, res);
        res += abs(left)+abs(right);
        return left+right+root->data-1;
    }
    int distCandy(Node* root) {
        // code here
        int res = 0;
        solve(root, res);
        return res;
    }
};