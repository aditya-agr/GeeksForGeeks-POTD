class Solution {
  public:
    int solve(vector<int> &arr, int i, int prev, vector<vector<int>>&dp){
        if(i<0)
            return 0;
        if(dp[prev+1][i] != -1)
            return dp[prev+1][i];
        int take=0, notake=0;
        if(prev==-1 || abs(arr[prev]-arr[i])==1)
            take = 1 + solve(arr, i-1, i, dp);
        notake = solve(arr, i-1, prev, dp);
        return dp[prev+1][i] = max(take, notake);
    }
    int longestSubseq(int n, vector<int> &a) {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(a, n-1, -1, dp);
    }
};