class Solution {
  public:
    void solve(Node* root, int &sum){
        if(!root)
            return;
        solve(root->right, sum);
        sum += root->data;
        root->data = sum - root->data;
        solve(root->left, sum);
    }
    void transformTree(Node *root) {
        // code here
        int sum = 0;
        solve(root, sum);
    }
};