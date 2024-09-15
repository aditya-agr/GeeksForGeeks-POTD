class Solution {
  public:
    Node *head=NULL, *last=NULL;
    void help(Node* node){
        if(!node)  
            return;
        help(node->left);
        if(!head)
            head = node;
        if(last)
            last->right = node;
        node->left = last;
        last = node;
        help(node->right);
    }
    Node* bToDLL(Node* root) {
        // code here
        help(root);
        return head;
    }
};