class Solution {
  public:
    int n, m;
    int dp[70][70][70];
    vector<vector<int>> grid;
    int solve(int i, int j1, int j2){
        if(j1<0 || j1>=m || j2<0 || j2>=m || i>=n)
            return 0;
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        int res = 0;
        res = max(res, solve(i+1, j1+1, j2+1));
        res = max(res, solve(i+1, j1+1, j2));
        res = max(res, solve(i+1, j1+1, j2-1));
        
        res = max(res, solve(i+1, j1, j2+1));
        res = max(res, solve(i+1, j1, j2));
        res = max(res, solve(i+1, j1, j2-1));
        
        res = max(res, solve(i+1, j1-1, j2+1));
        res = max(res, solve(i+1, j1-1, j2));
        res = max(res, solve(i+1, j1-1, j2-1));
        res += (j1==j2) ? grid[i][j1] : grid[i][j1]+grid[i][j2];
        return dp[i][j1][j2] = res;
    }
    int maxChocolate(vector<vector<int>>& grids) {
        // code here
        grid = grids;
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m-1);        
    }
};