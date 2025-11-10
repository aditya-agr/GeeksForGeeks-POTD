class Solution {
  public:
    int solve(vector<int> &arr, int i, int hold, vector<vector<int>> &dp){
        if(i >= arr.size())
            return 0;
        if(dp[i][hold] != -1)
            return dp[i][hold];
        
        int notake = solve(arr, i+1, hold, dp);
        
        int take = 0;
        if(hold == 0)
            take = solve(arr, i+1, 1, dp) - arr[i];
        else
            take = solve(arr, i+2, 0, dp) + arr[i];
        
        return dp[i][hold] = max(take, notake);
    }
    int maxProfit(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(arr, 0, 0, dp);
    }
};