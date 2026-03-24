class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        for(vector<int> &p : prerequisites){
            int x = p[0];
            int y = p[1];
            adj[x].push_back(y);
            indegree[y]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt++;
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        return cnt == n;
    }
};