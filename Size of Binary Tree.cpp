/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int recurr(Node*root){
         // base case
         if(root==NULL) return -1;
         // branches
         int left=1+recurr(root->left);
         int right=1+recurr(root->right);
         return left+right;
     }
    int getSize(Node* root) {
        // code here
        return recurr(root)+1;
    }
};