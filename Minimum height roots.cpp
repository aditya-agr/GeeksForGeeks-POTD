class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(vector<int> &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<pair<int, int>> q;
        q.push({0,-1});
        int far = -1;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                int u = q.front().first;
                int p = q.front().second;
                far = u;
                q.pop();
                for(int &v : adj[u]){
                    if(v == p) continue;
                    q.push({v, u});
                }
            }
        }
        q.push({far, -1});
        int cnt = 0, nfar = 0;
        vector<int> parent(V, -1);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                int u = q.front().first;
                int p = q.front().second;
                q.pop();
                nfar = u;
                for(int &v : adj[u]){
                    if(v == p) continue;
                    parent[v] = u;
                    q.push({v, u});
                }
            }
            cnt++;
        }
        vector<int> res;
        int half = 0, cur = nfar;
        while(cur != -1){
            if((cnt-1)/2 == half || cnt/2 == half)
                res.push_back(cur);
            cur = parent[cur];
            half++;
        }
        return res;
    }
};