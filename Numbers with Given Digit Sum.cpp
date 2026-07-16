class Solution {
  public:
    int solve(int n, int sum, vector<vector<int>> &dp){
        if(n == 0)
            return sum == 0;
        if(dp[n][sum] != -1)
            return dp[n][sum];
        int res = 0;
        for(int i=0; i<=9; i++){
            if(i > sum)
                break;
            res += solve(n-1, sum-i, dp);
        }
        return dp[n][sum] = res;
    }
    int countWays(int n, int sum) {
        // code here
        int res = 0;
        vector<vector<int>> dp(n, vector<int>(sum, -1));
        for(int i=1; i<=9; i++){
            if(i>sum)
                break;
            res += solve(n-1, sum-i, dp);
        }
        return res == 0 ? -1 : res;
    }
};