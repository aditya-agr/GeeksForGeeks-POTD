class Solution {
  public:
    long long solve(int i, int j, int n, vector<vector<vector<long long>>> &dp){
        if(i<0 || i>3 || j<0 || j>2)
            return 0;
        if((i==3) && (j==0 || j==2))
            return 0;
        if(n==1)
            return 1;
        if(dp[i][j][n] != -1)
            return dp[i][j][n];
        int dx[] = {0 ,0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        long long res=0;
        for(int x=0; x<4; x++)
            res += solve(i+dx[x], j+dy[x], n-1, dp);
        return dp[i][j][n]=res+solve(i, j, n-1, dp);
    }
    long long getCount(int n) {
        // Your code goes here
        long long res=0;
        vector<vector<vector<long long>>> dp(4, vector<vector<long long>>(3, vector<long long>(n+1, -1)));
        for(int i=0; i<4; i++)
            for(int j=0; j<3; j++)
                res += solve(i, j, n, dp);
        return res;
    }
};