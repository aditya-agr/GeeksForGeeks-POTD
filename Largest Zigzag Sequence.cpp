class Solution {
  public:
    int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
        int n = mat.size();
        if(i == n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int res = 0;
        for(int col=0; col<n; col++){
            if(col != j)
                res = max(res, mat[i][col] + solve(i+1, col, mat, dp));
        }
        return dp[i][j] = res;
    }
    int zigzagSequence(vector<vector<int>>& mat) {
        // code here
        int res = 0;
        int n = mat.size();
        vector<vector<int>> dp(n , vector<int>(n, -1));
        for(int j=0; j<n; j++){
            int cur = mat[0][j] + solve(1, j, mat, dp);
            res = max(res, cur);
        }
        return res;
    }
};