class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, 0)));
        for(int i=n-1; i>=0; i--){
            for(int k=1; k<=2; k++){
                for(int buy=0; buy<=1; buy++){
                    int profit = 0;
                    if(buy){
                        int buy = -prices[i] + dp[i+1][k][0];
                        int skip = dp[i+1][k][1];
                        profit = max(buy, skip);
                    }
                    else{
                        int sell = prices[i] + dp[i+1][k-1][1];
                        int skip = dp[i+1][k][0];
                        profit = max(sell, skip);
                    }
                    dp[i][k][buy] = profit;
                }
            }
        }
        return dp[0][2][1];
    }
};