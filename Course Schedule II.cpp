class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(vector<int> p : prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        vector<int> res;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                    res.push_back(nbr);
                }
            }
        }
        if(res.size() < n)
            res.clear();
        return res;
    }
};