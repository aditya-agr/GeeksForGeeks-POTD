class Solution {
  public:
    bool dfs(vector<vector<int>> &adj, int u, int p, vector<int> &vis){
        vis[u] = 1;
        bool res = false;
        for(int v : adj[u]){
            if(v == p) continue;
            if(vis[v]) return true;
            res |= dfs(adj, v, u, vis);
        }
        return res;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(vector<int> e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(V);
        for(int i=0; i<V; i++)
            if(!vis[i] && dfs(adj, i, -1, vis))
                return true;
        return false;
    }
};