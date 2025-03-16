class Solution {
  public:
    int solve(vector<int> &arr, int idx, vector<int> &dp){
        if(idx >= arr.size()-1)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int steps = 1e9;
        for(int i=idx+1; i<=idx+arr[idx]; i++)
            steps = min(steps, 1+solve(arr, i, dp));
        return dp[idx] = steps;
    }
    int minJumps(vector<int>& arr) {
        // code here
        int n  = arr.size();
        vector<int> dp(n+1, -1);
        int res = solve(arr, 0, dp);
        return res >= 1e9 ? -1 : res;
    }
};