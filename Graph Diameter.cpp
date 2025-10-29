class Solution {
  public:
    int dfs(int node, int &ans, vector<bool> &vis, vector<vector<int>> &adj){
        vis[node] = true;
        priority_queue<int> pq;
        for(int v : adj[node]){
            if(!vis[v])
                pq.push(1+dfs(v, ans, vis, adj));
        }
        if(pq.empty())
            return 0;
        int a = pq.top();
        pq.pop();
        int b = 0;
        if(!pq.empty())
            b = pq.top();
        ans = max(ans, a+b);
        return a;
    }
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(vector<int> &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        vector<bool> vis(V);
        dfs(0, ans, vis, adj);
        
        return ans;
    }
};
