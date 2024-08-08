class Solution {
  public:
    bool isSumTree(Node* root) {
        // Your code here
        if(!root || (!root->left && !root->right))
            return true;
        
        bool lft = isSumTree(root->left);
        bool rgt = isSumTree(root->right);
        
        int sum = 0;
        if(root->left) 
            sum += root->left->data;
        if(root->right) 
            sum += root->right->data;
        
        int temp = root->data;
        root->data += sum;
        
        return (lft and rgt and temp==sum);
    }
};