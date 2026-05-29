class Solution {
  public:
    int dp[101][1001];
    int solve(int idx, string &s, int prev){
        int n = s.length();
        if(idx == n)
            return 1;
        if(dp[idx][prev] != -1)
            return dp[idx][prev];
        int cur = 0;
        int cnt = 0;
        for(int i=idx; i<n; i++){
            cur += (s[i]-'0');
            if(cur >= prev)
                cnt += solve(i+1, s, cur);
        }
        return dp[idx][prev] = cnt;
    }
    int validGroups(string &s) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(0, s, 0);
    }
};