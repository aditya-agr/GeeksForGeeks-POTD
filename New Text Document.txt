class Solution {
  public:
    int solve(vector<int> &arr, int i, vector<int>&dp, bool taken){
        int n = arr.size();
        if(i >= n)
            return 0;
        if(i == n-1){
            if(taken) return 0;
            return arr[i];
        }
        if(dp[i] != -1)
            return dp[i];
        int pick = arr[i] + solve(arr, i+2, dp, taken);
        int nopick = solve(arr, i+1, dp, taken);
        return dp[i] = max(pick, nopick);
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        vector<int> dp(n, -1);
        int taken = arr[0] + solve(arr, 2, dp, true);
        fill(dp.begin(), dp.end(), -1);
        int notaken = solve(arr, 1, dp, false);
        return max(taken, notaken);
    }
};