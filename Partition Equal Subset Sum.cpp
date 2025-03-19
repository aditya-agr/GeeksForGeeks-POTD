class Solution {
  public:
    bool solve(vector<int> &arr, int i, int sum, vector<vector<int>> &dp){
        if(sum == 0)
            return true;
        if(i == arr.size())
            return false;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        int take = false;
        if(arr[i]<=sum){
            take = solve(arr, i+1, sum-arr[i], dp);
        }
        int notake = solve(arr, i+1, sum, dp);
        return dp[i][sum] = (take or notake);
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int tot = 0;
        for(int x : arr)
            tot += x;
        if(tot%2)
            return false;
        int target = tot/2;
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        return solve(arr, 0, target, dp);
    }
};