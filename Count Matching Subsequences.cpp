class Solution {
  public:
    int n, m;
    int mod = 1e9+7;
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(j == m)
            return 1;
        if(i == n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int res = 0;
        if(s1[i] == s2[j])
            res += solve(i+1, j+1, s1, s2, dp)%mod;
        res = res%mod + solve(i+1, j, s1, s2, dp)%mod;
        return dp[i][j] = res%mod;    
    }
    int countWays(string &s1, string &s2) {
        // code here
        n = s1.size();
        m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s1, s2, dp);
    }
};
