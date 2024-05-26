class Solution {

  public:
    int lcs(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int take=0, notake=0;
        if(s[i]==t[j])
            take = 1 + lcs(s, t, i-1, j-1, dp);
        notake = max(lcs(s, t, i, j-1, dp), lcs(s, t, i-1, j, dp));
        return dp[i][j] = max(take,notake);
    }
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        int n = x.size();
        int m = y.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        int len = lcs(x, y, n-1, m-1, dp);
        int ans = (n-len)*costX + (m-len)*costY;
        return ans;
    }
}