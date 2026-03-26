class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for(vector<int> &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ways(V), res(V, INT_MAX);
        pq.push({0,0});
        ways[0] = 1;
        res[0] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            int cw = pq.top().first;
            pq.pop();
            for(auto it : adj[u]){
                int v = it.first;
                int w = it.second;
                if(cw+w < res[v]){
                    res[v] = cw+w;
                    ways[v] = ways[u];
                    pq.push({res[v], v});
                }
                else if(cw+w == res[v])
                    ways[v] += ways[u];
            }
        }
        return ways[V-1];
    }
};