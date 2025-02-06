class Solution {
  public:
    unordered_map<int, int> mp;
    Node* solve(int s, int e, int &x, vector<int> &preorder){
        if(s>e)
            return NULL;
        int val = preorder[x++];
        Node * curr = new Node(val);
        curr->left = solve(s, mp[val]-1, x, preorder);
        curr->right = solve(mp[val]+1, e, x, preorder);
        return curr;
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n = inorder.size();
        for(int i=0; i<n; i++)
            mp[inorder[i]] = i;
        int x = 0;
        Node *root = solve(0, n-1, x, preorder);
        return root;
    }
};