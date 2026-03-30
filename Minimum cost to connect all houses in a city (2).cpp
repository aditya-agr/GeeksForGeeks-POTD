#define pp pair<int,pair<int, int>>
class Solution {
  public:
    int calDist(vector<int> &a, vector<int> &b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(i==j)
                    continue;
                int d = calDist(houses[i], houses[j]);
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }
        vector<int> vis(n);
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0,{0, -1}});
        int sum = 0;
        while(!pq.empty()){
            int w = pq.top().first;
            int u = pq.top().second.first;
            int p = pq.top().second.second;
            pq.pop();
            if(vis[u])
                continue;
            vis[u] = 1;
            sum += w;
            for(auto &it : adj[u]){
                int v = it.first;
                int d = it.second;
                if(!vis[v])
                pq.push({d, {v, u}});
            }
        }
        return sum;
        
    }
};ss