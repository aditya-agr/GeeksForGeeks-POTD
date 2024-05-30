class Solution {
  public:
    int m = 1e9+7;
    int solve(string &s, string &t, int i, int j, vector<vector<int>>&dp){
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        int cnt=0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i]==t[j])
            cnt = solve(s, t, i-1, j-1, dp)%m + solve(s, t, i-1, j, dp)%m;
        else
            cnt = solve(s, t, i-1, j, dp)%m;
        return dp[i][j]=cnt%m;
        
    }
    int countWays(string s1, string s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s1, s2, n-1, m-1, dp);
    }
};