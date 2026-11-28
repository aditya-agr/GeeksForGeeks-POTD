class Solution {
  public:
    bool checkPath(vector<vector<int>> &adj, int u, int v) {
        // code here
        queue<int> q;
        q.push(u);
        
        int V = adj.size();
        vector<int> vis(V);
        vis[u] = 1;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            if(n == v)
                return true;
            for(int m : adj[n]){
                if(!vis[m]){
                    vis[m] = 1;
                    q.push(m);
                }
            }
        }
        return false;
    }
};