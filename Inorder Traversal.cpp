class Solution {
  public:
    vector<int> res;
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        if(!root) 
            return {};
        inOrder(root->left);
        res.push_back(root->data);
        inOrder(root->right);
        return res;
    }
};