class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> ans(V, 1e8);
        ans[src] = 0;
        for(int i=0; i<V-1; i++){
            for(vector<int> &e : edges){
                if(ans[e[0]] == 1e8) 
                    continue;
                else
                    ans[e[1]] = min(ans[e[1]], ans[e[0]]+e[2]);
            }
        }
        for(vector<int> &e : edges){
            if(ans[e[0]] == 1e8) 
                continue;
            else{
                if(ans[e[1]] > ans[e[0]]+e[2])
                    return {-1};
            }
        }
        return ans;
    }
};