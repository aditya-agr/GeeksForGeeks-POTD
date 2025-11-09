class Solution {
  public:
    int solve(int r1, int c1, int r2, int c2, vector<vector<int>> &mat, unordered_map<string, int> &dp){
        int n = mat.size();
        if(r1>=n || c1>=n || r2>=n || c2>=n || mat[r1][c1]==-1 || mat[r2][c2]==-1)
            return INT_MIN;
        
        if(r1==n-1 && c1==n-1)
            return mat[n-1][n-1];
        
        string key = to_string(r1)+":"+to_string(c1)+":"+to_string(r2)+":"+to_string(c2);
        if(dp.count(key))
            return dp[key];
            
        int tot = 0;
        if(r1==r2 && c1==c2)
            tot = mat[r1][c1];
        else
            tot = mat[r1][c1] + mat[r2][c2];

        int d1 = solve(r1+1, c1, r2+1, c2, mat, dp);
        int d2 = solve(r1+1, c1, r2, c2+1, mat, dp);
        int d3 = solve(r1, c1+1, r2+1, c2, mat, dp);
        int d4 = solve(r1, c1+1, r2, c2+1, mat, dp);
        tot += max(d1, max(d2, max(d3, d4)));
        return dp[key] = tot;
        
    }
    int chocolatePickup(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        unordered_map<string, int> dp;
        int res = solve(0, 0, 0, 0, mat, dp);
        return max(res, 0);
        
    }
};