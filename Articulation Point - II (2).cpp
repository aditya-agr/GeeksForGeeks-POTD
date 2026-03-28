class Solution {
  public:
    vector<int> low;
    vector<int> dis;
    vector<int> vis;
    vector<bool> arti;
    int timer;
    void dfs(int u, int p, vector<vector<int>> &adj){
        vis[u] = 1;
        timer++;
        low[u] = timer;
        dis[u] = timer;
        int child = 0;
        for(int &v : adj[u]){
            if(v == p)
                continue;    
            if(vis[v])
                low[u] = min(low[u], dis[v]);
            else{
                child++;
                dfs(v, u, adj);
                low[u] = min(low[u], low[v]);
                if(p != -1 && low[v] >= dis[u])
                    arti[u] = true;
            }
        }
        if(p==-1 && child>1)
            arti[u] = true;
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(vector<int> &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        low.resize(V);
        dis.resize(V);
        vis.resize(V);
        arti.resize(V);
        timer = 0;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1, adj);
            }
        }
        vector<int> res;
        for(int i=0; i<V; i++){
            if(arti[i])
                res.push_back(i);
        }
        if(res.size() == 0)
            return {-1};
        return res;
    }
};