class Solution {
  public:
    int solve(int i, int j ,int k, string& s1, string& s2, string& s3, vector<vector<vector<int>>> &dp){
        int n = s1.size();
        int m = s2.size();
        int l = s3.size();
        
        if(i == n || j == m || k == l)
            return 0;
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];   
        
        
        if(s1[i] == s2[j] && s2[j] == s3[k])
            return dp[i][j][k] = 1 + solve(i+1, j+1, k+1, s1, s2, s3, dp);
        else{
            int res = 0;
            res = max(res, solve(i, j+1, k+1, s1, s2, s3, dp));
            res = max(res, solve(i, j+1, k, s1, s2, s3, dp));
            res = max(res, solve(i, j, k+1, s1, s2, s3, dp));
            res = max(res, solve(i+1, j, k, s1, s2, s3, dp));
            res = max(res, solve(i+1, j, k+1, s1, s2, s3, dp));
            res = max(res, solve(i+1, j+1, k, s1, s2, s3, dp));
            return dp[i][j][k] = res;
        }
    }
    int lcsOf3(string& s1, string& s2, string& s3) {
        // Code here
        int n = s1.size();
        int m = s2.size();
        int l = s3.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(l, -1)));
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};
