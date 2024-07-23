class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder(Node* root, vector<int> &res){
        if(!root)
            return;
        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> a1, a2, res;
        inorder(root1, a1);
        inorder(root2, a2);
        int n=a1.size(), m=a2.size(), i=0, j=0;
        while(i<n && j<m){
            if(a1[i]<a2[j])
                res.push_back(a1[i++]);
            else
                res.push_back(a2[j++]);
        }
        while(i<n)
            res.push_back(a1[i++]);
        while(j<m)
            res.push_back(a2[j++]);
        return res;
    }
};