class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        // Your code here
        if(!root) return false;
        int sum = target - root->data;
        if(!root->left && !root->right)
            return sum == 0;
        bool l = hasPathSum(root->left, sum);
        bool r = hasPathSum(root->right, sum);
        return l || r;
    }
};