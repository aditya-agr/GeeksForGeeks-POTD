class Solution {
  public:
    int lcs(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(s1[i] == s2[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int lc = lcs(s1, s2);
        int n = s1.size();
        int m = s2.size();
        return (n+m-lc);
    }
};