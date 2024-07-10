class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        int res=0;
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i][j] = mat[i][j];
                if(i>0 && j>0 && mat[i][j])
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], 
                    dp[i-1][j-1]));
                    
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};