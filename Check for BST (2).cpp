class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool checkBST(Node *root, int mn, int mx){
        if(!root)
            return true;
        if(root->data<=mn || root->data>=mx)
            return false;
        return checkBST(root->left, mn, root->data) &
                checkBST(root->right, root->data, mx);
    }
    bool isBST(Node* root) {
        // Your code here
        return checkBST(root, 0, 1e9+1);
    }
};
