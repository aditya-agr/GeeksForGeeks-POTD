class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &i : edges){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        vector<int> res(n+1, INT_MAX);
        res[1]=0;
        vector<int> parent(n+1);
        for(int i=1; i<=n; i++)
            parent[i] = i;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,1});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int idx = it.second;
            int dist = it.first;
            for(auto &i : adj[idx]){
                int d = i.second;
                int node = i.first;
                if(d+dist < res[node]){
                    res[node] = d+dist;
                    pq.push({res[node], node});
                    parent[node] = idx;
                }
            }
        }
        vector<int> path;
        int node = n;
        if(res[node] == INT_MAX)
            return {-1};
        while(parent[node]!=node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        path.push_back(res[n]);
        reverse(path.begin(), path.end());
        return path;
    }
};