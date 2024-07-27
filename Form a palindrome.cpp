class Solution{
  public:
    int lcs(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int take=0, notake=0;
        if(s[i]==t[j])
            take = 1 + lcs(s, t, i-1, j-1, dp);
        else
            notake = max(lcs(s, t, i-1, j, dp), lcs(s, t, i, j-1, dp));
        return dp[i][j] = max(take, notake);
    }
  
    int countMin(string str){
    //complete the function here
        string rstr = str;
        reverse(rstr.begin(), rstr.end());
        int n = str.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return n - lcs(str, rstr, n-1, n-1, dp);
    }
};