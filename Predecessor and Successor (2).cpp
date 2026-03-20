/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, int &key, vector<Node*> &res){
        if(!root)
            return;
        inorder(root->left, key, res);
        if(root->data < key)
            res[0] = root;
        if(root->data > key && res[1] == NULL)
            res[1] = root;
        inorder(root->right, key, res);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> res(2, NULL);
        inorder(root, key, res);
        return res;
        
    }
};