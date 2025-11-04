class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i=0; i<n-2; i++){
            dp[i+1] = min(dp[i+1], dp[i]+abs(height[i]-height[i+1]));
            dp[i+2] = min(dp[i+2], dp[i]+abs(height[i]-height[i+2]));
        }
        dp[n-1] = min(dp[n-1], dp[n-2]+abs(height[n-2]-height[n-1]));
        return dp[n-1];
    }
};