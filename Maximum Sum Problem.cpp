class Solution {
  public:
    int maxSum(int n) {
        // code here.
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            int cur = dp[i/2]+dp[i/3]+dp[i/4];
            if(cur > i)
                dp[i] = cur;
            else
                dp[i] = i;
        }
        return dp[n];
    }
};