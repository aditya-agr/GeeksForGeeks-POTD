class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        queue<int> q;
        q.push(0);
        int n = adj.size();
        vector<int> vis(n);
        vector<int> res;
        vis[0] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(int v : adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        return res;
        
    }
};