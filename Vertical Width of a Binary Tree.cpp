class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    void solve(Node *root, int &mn, int &mx, int i){
        if(!root)
            return;
        mn = min(mn, i);
        mx = max(mx, i);
        solve(root->left, mn, mx, i-1);
        solve(root->right, mn, mx, i+1);
    }
    int verticalWidth(Node* root) {
        // code here
        if(!root) 
            return 0;
        int mn=0, mx=0;
        solve(root, mn, mx, 0);
        return mx-mn+1;
    }
};