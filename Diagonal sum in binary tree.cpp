class Solution {
  public:
    void help(Node *root, map<int, int> &mp, int lvl){
        if(root==NULL)
            return;
        mp[lvl]+=root->data;
        help(root->right, mp, lvl);
        help(root->left, mp, lvl+1);
    }
    vector<int> diagonalSum(Node* root) {
        // Add your code here
        map<int, int> mp;
        help(root, mp, 0);
        vector<int> ans;
        for(auto i : mp)
            ans.push_back(i.second);
        return ans;
    }
};