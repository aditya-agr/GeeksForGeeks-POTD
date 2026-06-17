class Solution {
  public:
    long long solve(int n, vector<long long> & dp){
        if(n<=3)
            return n;
        if(dp[n] != -1)
            return dp[n];
        long long res = 0;
        for(int i=2; i<=n-2; i++)
            res = max(res, i*solve(n-i, dp));
        return dp[n] = res;
    }
    int maxProduct(int n) {
        // code here
        vector<long long> dp(n+1, -1);
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        long long res = solve(n, dp);
        return res;
    }
    
};