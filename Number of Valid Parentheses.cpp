class Solution {
  public:
    int dp[21][21];
    int solve(int i, int cnt){
        if(i <= 0)
            return (cnt==0);
        if(dp[i][cnt] != -1)
            return dp[i][cnt];
        int take = solve(i-1, cnt+1);
        int skip = 0;
        if(cnt)
            skip = solve(i-1, cnt-1);
        return dp[i][cnt] = take + skip;
    }
    int findWays(int n) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(n, 0);
    }
};