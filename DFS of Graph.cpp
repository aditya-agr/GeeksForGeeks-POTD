class Solution {
  public:
    void solve(int idx, vector<int> &vis, vector<int> &ans, vector<vector<int>>& adj){
        vis[idx] = 1;
        ans.push_back(idx);
        for(int v : adj[idx]){
            if(!vis[v])
                solve(v, vis, ans, adj);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n);
        vector<int> ans;
        solve(0, vis, ans, adj);
        return ans;
    }
};