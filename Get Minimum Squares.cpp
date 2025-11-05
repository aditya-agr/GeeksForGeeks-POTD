class Solution {
  public:
    int minSquares(int n) {
        // Code here
        vector<int> dp(n+1, INT_MAX);
        for(int i=1; i<=101; i++)
            if(i*i <= n)
                dp[i*i] = 1;
        
        for(int i=2; i<=n; i++){
            for(int j=1; j<i; j++)
                dp[i] = min(dp[i], dp[j]+dp[i-j]);
        }
        return dp[n];
    }
};