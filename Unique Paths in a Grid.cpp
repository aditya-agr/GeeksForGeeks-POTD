class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = grid[0][0] == 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    if(i>0 && j>0)
                        dp[i][j] = dp[i][j-1] + dp[i-1][j];
                    else if(i>0)
                        dp[i][j] = dp[i-1][j];
                    else if(j>0)
                        dp[i][j] = dp[i][j-1];
                }
             }
        }
        return dp[n-1][m-1];
    }
};