class Solution {
  public:
    Node *first, *second, *prev, *temp;
    void inorder(Node* root){
        if(!root)
            return;
        inorder(root->left);
        if(prev && prev->data > root->data){
            if(!first){
                first = prev;
                temp = root;
            }
            else
                second = root;
        }
        prev = root;
        inorder(root->right);
    }
    void correctBST(Node* root) {
        // add code here.
        first = second = prev = temp = NULL;
        inorder(root);
        if(first && second) 
            swap(first->data, second->data);
        else if(first && !second)
            swap(first->data, temp->data);
    }
};