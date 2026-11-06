class Solution {
  public:
    long long MOD = 1e9+7;
    int countBT(int h) {
        // code here
        vector<int>dp(h+1 , 1);
        for(int i = 2 ; i<=h ; i++){
            dp[i] = dp[i-1] *(dp[i-1] + 2LL*dp[i-2]) %MOD;
        }
        return dp[h];
    }
};