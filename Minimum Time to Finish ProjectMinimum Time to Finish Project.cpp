class Solution {
  public:
    bool cycle;
    vector<int> dp;
    int dfs(int u, vector<vector<int>> &adj, vector<int> &duration, vector<int> &vis){
        if(vis[u] == 1){
            cycle = true;
            return -1;
        }
        if(vis[u] == 2)
            return dp[u];
        vis[u] = 1;
        int res = 0;
        for(int v : adj[u]){
            res = max(res, dfs(v, adj, duration, vis));
            if(cycle) break;
        }
        vis[u] = 2;
        return dp[u] = duration[u] + res;
    }
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        // code here
        int n = duration.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(vector<int> d : dependencies){
            indegree[d[1]]++;
            adj[d[0]].push_back(d[1]);
        }
        int res = -1;
        cycle = false;
        dp.resize(n);
        vector<int> vis(n);
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                res = max(res, dfs(i, adj, duration, vis));
                if(cycle)
                    return -1;
            }
        }
        return res;
    }
};