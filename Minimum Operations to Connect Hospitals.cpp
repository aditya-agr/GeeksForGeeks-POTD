class Solution {
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        int n = edges.size();
        if(n < V-1)
            return -1;
        
        vector<vector<int>> adj(V);
        for(int i=0; i<n; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt = 0;
        vector<int> vis(V);
        for(int i=0; i<V; i++){
            if(vis[i]) continue;
            cnt++;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v : adj[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }
        return cnt-1;
    }
};
