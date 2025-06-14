class Solution {
  public:
    bool isMirror(Node *a, Node *b){
        if(!a && !b)
            return true;
        if(!a || !b)
            return false;
        return (a->data==b->data && isMirror(a->left, b->right) && isMirror(a->right, b->left));
    }
    bool isSymmetric(Node* root) {
        // Code here
        return isMirror(root->left, root->right);
    }
    
};