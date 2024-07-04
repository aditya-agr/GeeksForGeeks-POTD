class Solution {
  public:
    string solve(Node*root, unordered_map<string, int> &mp, vector<Node*>&res){
        if(!root)
            return "0";
        string s = "";
        s += solve(root->left, mp, res);
        s += solve(root->right, mp, res);
        s += to_string(root->data);
        if(mp[s]==1)
            res.push_back(root);
        mp[s]++;
        return s;
    }
    vector<Node*> printAllDups(Node* root) {
        // Code here
        vector<Node*> res;
        unordered_map<string, int> mp;
        solve(root, mp, res);
        return res;
    }
