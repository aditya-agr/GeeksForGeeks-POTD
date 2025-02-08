class Solution {
  public:
    void left(Node *root, vector<int> &ans){
        if(!root) return;
        if(!root->left && !root->right) return;
        ans.push_back(root->data);
        if(root->left)
            left(root->left, ans);
        else if(root->right)
            left(root->right, ans);
        else
            return;
    }
    void bottom(Node *root, vector<int> &ans){
        if(!root) return;
        if(!root->left && !root->right)
            ans.push_back(root->data);
        if(root->left)
            bottom(root->left, ans);
        if(root->right)
            bottom(root->right, ans);
        
    }
    void right(Node *root, vector<int> &ans){
        if(!root) return;
        if(root->right)
            right(root->right, ans);
        else if(root->left)
            right(root->left, ans);
        else
            return;
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        ans.push_back(root->data);
        left(root->left, ans);
        bottom(root->left, ans);
        bottom(root->right, ans);
        right(root->right, ans);
        return ans;
        
    }
};