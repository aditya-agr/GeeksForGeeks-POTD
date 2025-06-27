class Solution {
  public:
    int dp[4][3][16];
    int solve(int i, int j, int n){
        if(i<0 || i>=4 || j<0 || j>=3 || (i==3 && (j==0 || j==2)))
            return 0;
        if(n == 1)
            return 1;
        if(dp[i][j][n] != -1)
            return dp[i][j][n];
        int count = solve(i, j, n-1);
        count += solve(i-1, j, n-1);
        count += solve(i+1, j, n-1);
        count += solve(i, j-1, n-1);
        count += solve(i, j+1, n-1);
        return dp[i][j][n] = count;
    }
    int getCount(int n) {
        // code here
        long long count = 0;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                count += solve(i, j, n);
            }
        }
        return count;
    }
};