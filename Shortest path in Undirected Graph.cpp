class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adj(N);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> res(N, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        res[src] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            for(int &i : adj[node]){
                if(dist+1 < res[i]){
                    q.push({i, dist+1});
                    res[i] = dist+1;
                }
            }
        }
        for(int i=0; i<N; i++)
            if(res[i]==INT_MAX) res[i] = -1;
        return res;
    }
};