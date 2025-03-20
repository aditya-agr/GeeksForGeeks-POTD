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


        int n = prices.size();
        vector<int> profit(n+1, 0);
        int maxi = 0;
        for(int i=n-1; i>=0; i--){
            profit[i] = max(maxi - prices[i], profit[i+1]);
            maxi = max(maxi, prices[i]);
        }
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            profit[i] = max(prices[i] - mini + profit[i+1], profit[i-1]) ;
            mini = min(mini, prices[i]);
        }
        return profit[n-1];

    }
};


