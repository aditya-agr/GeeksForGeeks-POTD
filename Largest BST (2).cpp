/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

struct Info {
    bool isBST;
    int sz;
    int mn;
    int mx;
};

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int res;
    Info solve(Node* root){
        if(!root)
            return {true, 0, INT_MAX, INT_MIN};
        Info l = solve(root->left);
        Info r = solve(root->right);
        
        Info cur;
        cur.sz = l.sz + r.sz + 1;
        cur.mn = min(l.mn, root->data);
        cur.mx = max(r.mx, root->data);
        
        if(l.isBST && r.isBST && root->data > l.mx && root->data < r.mn){
            cur.isBST = true;
            res = max(res, cur.sz);
        }
        else
            cur.isBST = false;
            
        return cur;
    }
    int largestBst(Node *root) {
        // Your code here
        res = 0;
        solve(root);
        return res;
    }
};