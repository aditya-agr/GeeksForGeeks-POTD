#define P pair<int, int>
// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<P>> adj(V);
        for(vector<int> &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src});
        vector<int> res(V, 1e9+7);
        res[src] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto it : adj[u]){
                int v = it.first;
                int d = it.second;
                if(d+dist < res[v]){
                    res[v] = d+dist;
                    pq.push({d+dist, v});
                }
            }
        }
        return res;
    }
};