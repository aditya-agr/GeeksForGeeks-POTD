class Solution {
  public:
    int solve(Node *root, int &dia){
        if(!root)
            return 0;
        int lh = solve(root->left, dia);
        int rh = solve(root->right, dia);
        dia = max(dia, lh+rh);
        return max(lh, rh)+1;
    }
    int diameter(Node* root) {
        // Your code here
        int dia = 0;
        solve(root, dia);
        return dia;
    }
};