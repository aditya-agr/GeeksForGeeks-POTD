class Solution {
  public:
    int solve(int i, int curr, vector<int> &arr, vector<vector<int>> &dp){
        if(i == arr.size())
            return curr;
        if(dp[i][curr] != -1)
            return dp[i][curr];
        int take = solve(i+1, curr^arr[i], arr, dp);
        int notake = solve(i+1, curr, arr, dp);
        return dp[i][curr] = take+notake;
    }
    int subsetXORSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2001, -1)); 
        return solve(0, 0, arr, dp);
    }
};