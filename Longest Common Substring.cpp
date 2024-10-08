class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        int n = str1.size();
        int m = str2.size();
        int res=0;
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};