class Solution {
  public:
    bool solve(string &s, int idx, vector<string> &dict, vector<int> &dp){
        if(idx == s.length())
            return true;
        if(dp[idx] != -1)
            return dp[idx];
        int ans = false;
        for(string w : dict){
            int n = w.length();
            bool can = true;
            for(int i=0; i<n; i++){
                if(s[idx+i] != w[i]){
                    can = false;
                    break;
                }
            }
            if(can)
                ans =  ans or solve(s, idx+n, dict, dp);
        }
        return dp[idx] = ans;
    }
    bool wordBreak(string &s, vector<string> &dict) {
        // code here
        int n = s.length();
        vector<int> dp(n+1, -1);
        return solve(s, 0, dict, dp);
    }
};