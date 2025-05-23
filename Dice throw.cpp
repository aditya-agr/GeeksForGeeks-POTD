class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(x+1));
        dp[0][0]= 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=x; j++){
                for(int k=1; k<=m; k++){
                    if(j-k>=0)
                        dp[i][j] += dp[i-1][j-k];
                }
            }
        }
        return dp[n][x];


        // if(n==0 && x==0)
        //     return 1;
        // if(n<=0 || x<=0)
        //     return 0;
        // int ways = 0;
        // for(int i=1; i<=m; i++)
        //     ways += noOfWays(m, n-1, x-i);
        // return ways;

    }
};