class Solution {
  public:
    int solve(int i, int k, vector<int> &arr, vector<int> &dp){
        int n = arr.size();
        if(i==n-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans = INT_MAX;
        for(int j=i+1; j<=i+k && j<n; j++){
            int curr = abs(arr[j]-arr[i]) + solve(j, k, arr, dp);
            ans = min(ans, curr);
        }
        return dp[i] = ans;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, k, arr, dp);
    }
};