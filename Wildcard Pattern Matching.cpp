class Solution {
  public:
    /*You are required to complete this method*/
    int solve(string &pattern, string &str, int i, int j, vector<vector<int>>&dp){
        if(i==pattern.size() && j==str.size())
            return 1;
        if(i==pattern.size()) return 0;
        if(j==str.size() && pattern[i]=='*') 
            return solve(pattern, str, i+1, j, dp);
        if(j==str.size()) return 0;
        if(pattern[i]!='*' && pattern[i]!='?' && pattern[i]!=str[j])
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int a=0, b=0, c=0;
        if(pattern[i]=='*'){
            a = solve(pattern, str, i+1, j, dp);
            b = solve(pattern, str, i, j+1, dp);
        }
        c = solve(pattern, str, i+1, j+1, dp);
        return dp[i][j] = a|b|c;
    }
    int wildCard(string pattern, string str) {
        // code here
        int n = pattern.size();
        int m = str.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(pattern, str, 0, 0, dp);
    }
};