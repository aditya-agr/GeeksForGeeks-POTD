class Solution {
  public:
    int dfs(vector<vector<int>> &adj, int u, int dest, vector<int> &dp){
        if(u == dest)
            return 1;
        if(dp[u]!= -1)
            return dp[u];
        int ways = 0;
        for(int v : adj[u])
            ways += dfs(adj, v, dest, dp);
        return dp[u] = ways;
    }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>> adj(V);
        for(vector<int> e : edges)
            adj[e[0]].push_back(e[1]);
        vector<int> dp(1001, -1); 
        return dfs(adj, src, dest, dp);
    }
};