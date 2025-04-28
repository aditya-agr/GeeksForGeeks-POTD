#define P pair<int,int>
class Solution {
  public:
    P solve(Node* root){
        if(!root)
            return {0, 0};
        P l = solve(root->left);
        P r = solve(root->right);
        int include = root->data + l.second + r.second;
        int exclude = max(l.first, l.second) + max(r.first, r.second);
        return {include, exclude};
    }
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        // code here
        P res = solve(root);
        return max(res.first, res.second);
    }
};