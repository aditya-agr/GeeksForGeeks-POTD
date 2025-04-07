class Solution {
  public:
    bool solve(vector<vector<int>> &adj, vector<int> &visited, vector<int> &inRecursion, int u){
        visited[u] = 1;
        inRecursion[u] = 1;
        
        for(int &v : adj[u]){
            if(!visited[v] && solve(adj, visited, inRecursion, v))
                return true;
            else if(inRecursion[v] == 1)
                return true;
        }
        inRecursion[u] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(vector<int> &e : edges)
            adj[e[0]].push_back(e[1]);
            
        vector<int> visited(V);
        vector<int> inRecursion(V);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && solve(adj, visited, inRecursion, i))
                return true;
        }
        return false;
    }
};