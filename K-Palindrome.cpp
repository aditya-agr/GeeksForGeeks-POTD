
class Solution{
public:
    
    int lcs(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j] = 1 + lcs(s, t, i-1, j-1, dp);
        
        return dp[i][j] = max(lcs(s, t, i-1, j, dp), lcs(s, t, i, j-1, dp));
    }
    int kPalindrome(string str, int n, int k)
    {
        // code here
        string t = str;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        
        int len = lcs(str, t, n-1, n-1, dp);
        return k >= (n-len);
    }
};