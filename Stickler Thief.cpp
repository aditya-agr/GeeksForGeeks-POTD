class Solution {
  public:
    int solve(vector<int>& arr, int idx, vector<int> &dp){
        int n = arr.size();
        if(idx>=n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int pick = arr[idx] + solve(arr, idx+2, dp);
        int nopick = solve(arr, idx+1, dp);
        return dp[idx] = max(pick, nopick);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return solve(arr, 0, dp);
    }
};