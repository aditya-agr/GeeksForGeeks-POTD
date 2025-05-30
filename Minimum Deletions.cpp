class Solution {
  public:
    int lcs(string &s, string &t){
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][n];
    }
    int minDeletions(string s) {
        // code here
        string r = s;
        reverse(r.begin(), r.end());
        int n = s.length();
        int l = lcs(s, r);
        return n-l;
    }
};