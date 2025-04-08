class Solution {
  public:
    bool dfs(vector<vector<int>> &adj, int u, int c, int d, vector<bool> &vis){
        vis[u] = true;
        for(int v : adj[u]){
            if(!vis[v])
                dfs(adj, v, c, d, vis);
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>> adj(V);
        for(vector<int> &e : edges){
            if(e[0] == c && e[1] == d) continue;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(V, false);
        dfs(adj, c, c, d, vis);
        return !vis[d];
    }
};
