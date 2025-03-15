class Solution {
  public:
    int solve(vector<int> &coins, int sum, int i, vector<vector<int>> &dp){
        if(sum == 0)
            return 0;
        if(sum < 0 || i >= coins.size())
            return 1e9;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        int pick = 1e9;
        if(coins[i]<=sum)
            pick = 1+solve(coins, sum-coins[i], i, dp);
        int nopick = solve(coins, sum, i+1, dp);
        return dp[i][sum] = min(pick, nopick);
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1,-1));
        int res = solve(coins, sum, 0, dp);
        return res >= 1e09 ? -1 : res;
    }
};
