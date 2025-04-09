class Solution {
  public:
    void dfs(int u, vector<vector<int>> &adj, vector<int> &disc, 
    vector<int> &low, vector<int> &parent, vector<bool> &ap, int &time){
        int child = 0;
        disc[u] = low[u] = time++;
        for(int v : adj[u]){
            if(disc[v] == -1){
                parent[v] = u;
                child++;
                dfs(v, adj, disc, low, parent, ap, time);
                low[u] = min(low[u], low[v]);
                if(parent[u] == -1 && child > 1)
                    ap[u] = true;
                if(parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = true;
            }
            else if(v != parent[u])
                low[u] = min(low[u], disc[v]);
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(vector<int> &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> disc(V, -1), low(V, -1), parent(V,-1);
        vector<bool> ap(V, false);
        int time = 0;
        for(int i=0; i<V; i++)
            if(disc[i] == -1)
                dfs(i, adj, disc, low, parent, ap, time);
        
        vector<int> res;
        for(int i=0; i<V; i++)
            if(ap[i])
                res.push_back(i);
            
        if(res.empty())
            res.push_back(-1);
        return res;
                
    }
};