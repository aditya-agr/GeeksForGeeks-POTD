
class Solution {
public:
    int solve(vector<int> adj[], vector<int> &vis, int &ans, int idx){
        vis[idx]=1;
        int cnt = 1;
        for(int i : adj[idx]){
            if(!vis[i]){
                int temp = solve(adj, vis, ans, i);
                cnt += temp;
                if(temp%2 == 0)
                    ans++;
            }
        }
        return cnt;
    }
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> adj[n+1];
	    int m = edges.size();
	    for(int i=0; i<m; i++){
	        adj[edges[i][0]].push_back(edges[i][1]);
	        adj[edges[i][1]].push_back(edges[i][0]);
	    }
	    vector<int> vis(n+1,0);
	    int ans=0;
	    for(int i=1; i<=n; i++){
	        if(!vis[i])
	            solve(adj, vis, ans, i);
	    }
	    return ans;
	}
};