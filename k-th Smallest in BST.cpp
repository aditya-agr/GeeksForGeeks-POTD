class Solution {
  public:
    int ans = -1;
    void solve(Node *root, int &k){
        if(!root)
            return;
        solve(root->left, k);
        k--;
        if(k==0)
            ans = root->data;
        solve(root->right, k);
        
        
    }
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here.
        solve(root, k);
        return ans;
    }
};