class Solution {
  public:
    int res;
    void dfs(int u, vector<bool> &vis, vector<bool> &inrecur, vector<int> &count, vector<vector<int>> &adj){
        vis[u] = true;
        inrecur[u] = true;
        for(int &v : adj[u]){
            if(!vis[v]){
                count[v] = count[u]+1;
                dfs(v, vis, inrecur, count, adj);
            }
            else if(inrecur[v]){
                res = max(res, count[u]-count[v]+1);
            }
        }
        inrecur[u] = false;
    }
    
    int longestCycle(int V, vector<vector<int>>& edges) {
        // code here
        res = -1;

        vector<vector<int>> adj(V);
        for(auto &e : edges){
            if(e[1] != -1)
                adj[e[0]].push_back(e[1]);
        }
    
        vector<bool> visited(V, false);
        vector<bool> inRecur(V, false);
        vector<int> count(V, 0);
    
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                count[i] = 1;
                dfs(i, visited, inRecur, count, adj);
            }
        }
    
        return res;
    }
};
