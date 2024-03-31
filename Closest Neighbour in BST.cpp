class Solution {
  public:
    int ans=INT_MIN;
    void solve(Node *root, int n){
        if(root==NULL)
            return;
        if(root->key <= n){
            ans = max(root->key, ans);
            solve(root->right, n);
        }
        else
            solve(root->left, n); 
            
    }
    int findMaxForN(Node* root, int n) {
        // code here
        solve(root, n);
        if(ans==INT_MIN)
            return -1;
        return ans;
    }
};