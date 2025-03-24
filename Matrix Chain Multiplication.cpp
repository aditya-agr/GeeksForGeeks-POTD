class Solution {
  public:
    int solve(int st, int ed, vector<int> &arr, vector<vector<int>> &dp){
        if(ed - st == 1)
            return 0;
        if(dp[st][ed] != -1)
            return dp[st][ed];
        int ans = INT_MAX;
        for(int i=st+1; i<ed; i++){
            int left = solve(st, i, arr, dp);
            int right = solve(i, ed, arr, dp);
            int cost = left+right+arr[st]*arr[ed]*arr[i];
            ans = min(ans, cost);
        }
        return dp[st][ed] = ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, arr, dp);
    }
};
