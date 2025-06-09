class Solution {
  public:
    bool solve(Node *root, int mn, int mx){
        if(!root)
            return false;
        int x = root->data;
        if(root->data==mn && root->data==mx)
            return true;
        bool left = solve(root->left, mn, x-1);
        bool right = solve(root->right, x+1, mx);
        return left or right;
    }
    bool isDeadEnd(Node *root) {
        // Code here
        return solve(root, 1, 1e8);
    }
};