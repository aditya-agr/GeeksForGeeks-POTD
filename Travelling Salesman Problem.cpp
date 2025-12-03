class Solution {
  public:
    int n;
    int allset;
    int dp[15][1<<15];
    int solve(int u, int mask, vector<vector<int>>& cost){
        if(mask == allset)
            return cost[u][0];
        if(dp[u][mask] != -1)
            return dp[u][mask];
        int res = INT_MAX;
        for(int v=0; v<n; v++){
            int bit = (1<<v);
            if((mask&bit) == 0)
                res = min(res, cost[u][v]+solve(v, mask|bit, cost));
        }
        return dp[u][mask] = res;
    }
    int tsp(vector<vector<int>>& cost) {
        // code here
        n = cost.size();
        allset = (1<<n)-1;
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, cost);
    }
};