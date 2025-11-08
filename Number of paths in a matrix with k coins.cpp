class Solution {
  public:
    int solve(vector<vector<int>> &mat, int i, int j, int sum, int &k, vector<vector<vector<int>>> &dp){
        int n = mat.size();
        int m = mat[0].size();
        if(i<0 || i>=n || j<0 || j>=m)
            return 0;
        sum += mat[i][j];
        if(sum > k)
            return 0;
        if(dp[i][j][sum] != -1)
            return dp[i][j][sum];
        if(i==n-1 && j==m-1){
            if(sum == k)
                return 1;
            return 0;
        }
        int a = solve(mat, i+1, j, sum, k, dp);
        int b = solve(mat, i, j+1, sum, k, dp);
        return dp[i][j][sum] = a+b;
    }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
        return solve(mat, 0, 0, 0, k, dp);
    }
};