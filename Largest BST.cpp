struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    vector<int> solve(Node* root){
        if(!root) 
            return {INT_MAX, INT_MIN, 0};
            
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);
        
        if(left[1]<root->data && right[0]>root->data)
            return {
                min(root->data, left[0]),
                max(root->data, right[1]),
                left[2] + right[2] + 1
            };
        
        return {INT_MIN, INT_MAX, max(left[2], right[2])};
            
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	vector<int> res = solve(root);
    	return res[2];
    }
};