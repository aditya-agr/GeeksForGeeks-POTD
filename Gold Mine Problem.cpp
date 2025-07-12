class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        int res = 0;
        for(int j=m-1; j>=0; j--){
            for(int i=n-1; i>=0; i--){
                int mx = 0;
                if(i<n-1 && j<m-1) mx = max(mx, dp[i+1][j+1]);
                if(i>0 && j<m-1) mx = max(mx, dp[i-1][j+1]);
                if(j<m-1) mx = max(mx, dp[i][j+1]);
                dp[i][j] = mat[i][j] + mx;
                if(j==0)
                    res = max(res, dp[i][j]);
            }
        }
        return res;
        
    }
};