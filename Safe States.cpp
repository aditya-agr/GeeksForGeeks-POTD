class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<int> outdegree(V);
        for(vector<int> &e : edges){
            adj[e[1]].push_back(e[0]);
            outdegree[e[0]]++;
        }
        vector<int> res;
        queue<int> q;
        for(int i=0; i<V; i++){
            if(outdegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int &nbr : adj[node]){
                outdegree[nbr]--;
                if(outdegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        return res;
    }
};