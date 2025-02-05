class Solution {
  public:
    Node* solve(Node* node){
        if(!node)
            return NULL;
        
        Node *l = solve(node->left);
        Node *r = solve(node->right);
        node->left = r;
        node->right = l;
        return node;
    }
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        solve(node);
    }
};