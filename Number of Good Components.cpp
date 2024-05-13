class Solution {
  public:
    int bfs(vector<int> adj[], int idx, vector<int>&vis){
        queue<int>q;
        q.push(idx);
        vis[idx]=1;
        int num=0, edge=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            num++;
            edge += adj[node].size();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return num*(num-1) == edge;
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[v+1];
        for(int i=0; i<e; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(v+1);
        int ans=0;
        for(int i=1; i<=v; i++){
            if(bfs(adj, i, vis))
                ans++;
        }
        return ans;
    }
};