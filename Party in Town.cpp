class Solution {
  public:
    int partyHouse(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        queue<int> q;
        vector<int> vis(n+1, -1);
        q.push(1);
        vis[1] = 0;
        int last = 1;
        int dia = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u-1]){
                if(vis[v] == -1){
                    q.push(v);
                    vis[v] = vis[u]+1;
                }
                if(vis[v] > dia){
                    last = v;
                    dia = vis[v];
                }
            }
        }
        dia = 0;
        q.push(last);
        for(int i=1; i<=n; i++)
            vis[i] = -1;
        vis[last] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u-1]){
                if(vis[v] == -1){
                    q.push(v);
                    vis[v] = vis[u]+1;
                }
                if(vis[v] > dia)
                    dia = vis[v];
            }
        }
        return (dia+1)/2;
    }
};