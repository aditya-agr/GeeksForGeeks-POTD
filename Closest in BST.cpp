class Solution {
  public:
    void inorder(Node* root, int &mn, int&k){
        if(!root)
            return;
        inorder(root->left, mn, k);
        if(abs(root->data-k)<mn)
            mn = abs(root->data-k);
        inorder(root->right, mn, k);
    }
    int minDiff(Node *root, int k) {
        // code here
        int res = -1, mn = INT_MAX;
        inorder(root, mn, k);
        return mn;
    }
};
