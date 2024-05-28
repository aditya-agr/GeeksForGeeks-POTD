class Solution {
  public:
    int solve(int i, int w, vector<int> &cost, vector<vector<int>> &dp){
        if(w==0)
            return 0;
        if(i<0)
            return 1e9;
        if(dp[i][w] != 1e9)
            return dp[i][w];
        int take=1e9, notake=1e9;
        if(w>=i+1)
            take = cost[i] + solve(i, w-i-1, cost, dp);
        notake = solve(i-1, w, cost, dp);
        return dp[i][w]=min(take, notake);
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(w+1, 1e9));
        return solve(n-1, w, cost, dp);
    }
};