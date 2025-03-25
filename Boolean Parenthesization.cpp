class Solution {
  public:
    bool evaluate(int b1, int b2, char op){
        if(op == '&')
            return b1&b2;
        else if(op == '|')
            return b1|b2;
        else
            return b1^b2;
    }
    int solve(int st, int ed, int req, string &s, vector<vector<vector<int>>> &dp){
        if(st == ed)
            return (req == (s[st]=='T')) ? 1 : 0;
        if(dp[st][ed][req] != -1)
            return dp[st][ed][req];
        
        int ans = 0;
        for(int k=st+1; k<ed; k++){
            int leftTrue = solve(st, k-1, 1, s, dp);
            int leftFalse = solve(st, k-1, 0, s, dp);
            
            int rightTrue = solve(k+1, ed, 1, s, dp);
            int rightFalse = solve(k+1, ed, 0, s, dp);
            
            if(evaluate(1,1, s[k]) == req)
                ans += leftTrue * rightTrue;
            if(evaluate(1,0, s[k]) == req)
                ans += leftTrue * rightFalse;
            if(evaluate(0,1, s[k]) == req)
                ans += leftFalse * rightTrue;
            if(evaluate(0,0, s[k]) == req)
                ans += leftFalse * rightFalse;
            
        }
        return dp[st][ed][req] = ans;
    }
    int countWays(string &s) {
        // code here
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(0, n-1, 1, s, dp);
    }
};