/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(vector<int> &res, Node* root){
        if(root == NULL)
            return;
        solve(res, root->left);
        solve(res, root->right);
        res.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> res;
        solve(res, root);
        return res;
    }
};