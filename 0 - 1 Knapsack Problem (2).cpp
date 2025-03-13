class Solution {
  public:
    int solve(int W, int i, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if(i == val.size())
            return 0;
        if(dp[i][W] != -1)
            return dp[i][W];
        int nopick = solve(W, i+1, val, wt, dp);
        int pick = 0;
        if(W>=wt[i])
            pick = val[i] + solve(W-wt[i], i+1, val, wt, dp);
        return dp[i][W] = max(pick, nopick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(1001, -1));
        return solve(W, 0, val, wt, dp);
    }
};