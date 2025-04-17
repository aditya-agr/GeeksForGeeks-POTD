#define P pair<int, int>
class Solution {
  public:
    int dijkstra(vector<vector<P>> &adj, int src, int dest){
        int n = adj.size();
        vector<int> res(n, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;
        res[src] = 0;
        pq.push({0, src});
      
        while(!pq.empty()){
            int dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for(auto &neg : adj[u]){
                int v = neg.first;
                int d = neg.second;
                if(u == src && v == dest || (u == dest && v == src))
                    continue;
                if(res[v] > d+dist){
                    res[v] = d+dist;
                    pq.push({res[v], v});
                }
            }
        }
        return res[dest];  
    }
 
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<P>> adj(V);
        for(vector<int> &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        int minCycle = INT_MAX;
        for(vector<int> &e : edges){
            int dist = dijkstra(adj, e[0], e[1]);
            if(dist != INT_MAX)
                minCycle = min(minCycle, dist+e[2]); 
        }
        return minCycle;
    }
};