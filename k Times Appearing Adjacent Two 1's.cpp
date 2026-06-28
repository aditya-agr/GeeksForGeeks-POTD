class Solution {
  public:
    long long mod = 1e9+7;
    long long solve(int p, int i, int &n, int k, vector<vector<vector<int>>> &dp){
        if(i == n)
            return k==0;
            
        if(dp[i][k][p] != -1)
            return dp[i][k][p];
        
        long long one = 0, zero = 0;
        if(p == 1){
            if(k>0)
                one = solve(1, i+1, n, k-1, dp);
        }
        else
            one = solve(1, i+1, n, k, dp);
        
        zero = solve(0, i+1, n, k, dp);
    
        return dp[i][k][p] = (one+zero)%mod;
        
    }
    int countStrings(int n, int k) {
        // code here
        if(k >= n)
            return 0;
        if(k+1 == n)
            return 1;
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2,-1)));
        
        return solve(0, 0, n, k, dp);
    }
};