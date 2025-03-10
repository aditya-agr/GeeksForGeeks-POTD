class Solution {
  public:
    // Function to compute the edit distance between two strings
    vector<vector<int>> dp;
    int solve(string &s, string &t, int i, int j){
        if(i==s.size())
            return t.size() - j;
        if(j==t.size())
            return s.size() - i;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == t[j])
            return dp[i][j] = solve(s, t, i+1, j+1);
        else{
            int in = 1+solve(s, t, i, j+1);
            int rem = 1+solve(s, t, i+1, j);
            int rep = 1+solve(s, t, i+1, j+1);
            return dp[i][j] = min(in, min(rem, rep));
        }
    }
    int editDistance(string& s1, string& s2) {
        // code here
        dp.resize(s1.length()+1, vector<int>(s2.length()+1, -1));
        return solve(s1, s2, 0, 0);
    }
};