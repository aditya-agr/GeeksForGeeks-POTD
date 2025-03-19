class Solution {
  public:
    int solve(vector<int>& prices, int i, int k, bool canbuy, vector<vector<vector<int>>> &dp){
        if(i==prices.size() || k == 0)
            return 0;
        if(dp[i][k][canbuy] != -1)
            return dp[i][k][canbuy];
        int pick = 0, nopick = 0;
        if(canbuy){
            pick = -prices[i] + solve(prices, i+1, k, false, dp);
            nopick = solve(prices, i+1, k, true, dp);
        }
        else{
            pick = prices[i] + solve(prices, i+1, k-1, true, dp);
            nopick = solve(prices, i+1, k, false, dp);
        }
        return dp[i][k][canbuy] = max(pick, nopick);
    }
    
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        bool canbuy = true;
        return solve(prices, 0, k, canbuy, dp);
    }
};