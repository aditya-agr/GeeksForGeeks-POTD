class Solution{
  public:
    void dfs(Node * root, map<int, int> &mp, int idx){
        if(root==NULL)
            return;
        mp[idx] += root->data;
        dfs(root->left, mp, idx-1);
        dfs(root->right, mp, idx+1);
    }
    vector <int> verticalSum(Node *root) {
        // add code here.
        map<int, int> mp;
        dfs(root, mp, 0);
        vector<int> ans;
        // sort(mp.begin(), mp.end());
        for(auto i : mp)
            ans.push_back(i.second);
        return ans;
    }
};