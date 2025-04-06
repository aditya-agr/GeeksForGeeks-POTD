class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> indegree(V);
        for(vector<int> &e : edges){
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int> q;
        vector<int> res;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    res.push_back(v);
                }
            }
        }
        return res;
    }
};