class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for(vector<int> &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<pair<int, int>> q;
        vector<int> res(V, INT_MIN);
        q.push({src, 0});
        res[src] = 0;
        
        while(!q.empty()){
            int u = q.top().first;
            int w = q.top().second;
            q.pop();
            for(auto &[v, d] : adj[u]){
                if(w+d > res[v]){
                    res[v] = max(res[v], w+d);
                    q.push({v, w+d});
                }
            }
        }
        return res;
    }
};