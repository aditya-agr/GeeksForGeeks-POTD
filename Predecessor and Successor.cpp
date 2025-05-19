class Solution {
  public:
    Node *predecessor, *successor;
    void solve(Node *root, int key){
        if(!root)
            return;
        solve(root->left, key);
        if(root->data < key)
            predecessor = root;
        if(root->data > key && successor == NULL)
            successor = root;
        solve(root->right, key);
        
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        predecessor=NULL;
        successor=NULL;
        solve(root, key);
        return {predecessor, successor};
        
    }
};