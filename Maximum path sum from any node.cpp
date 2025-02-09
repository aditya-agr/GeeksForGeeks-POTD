class Solution {
  public:
    int maxi;
    int solve(Node *root){
        if(!root)
            return 0;
        int leftsum = solve(root->left);
        int rightsum = solve(root->right);
        int curr = root->data + max(0,leftsum) + max(0, rightsum);
        maxi = max(maxi, curr);
        int sum = max(0, max(leftsum, rightsum));
        sum += root->data;
        return sum;
    }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        maxi = INT_MIN;
        solve(root);
        return maxi;
    }
};