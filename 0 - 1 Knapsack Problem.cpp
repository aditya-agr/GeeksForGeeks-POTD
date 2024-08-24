class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int idx, int w, vector<int>& wt, vector<int>& val, vector<vector<int>> &dp){
        if(idx == wt.size())
            return 0;
        if(dp[idx][w]!=-1)
            return dp[idx][w];
        int take=0, notake=0;
        if(w >= wt[idx])
            take = val[idx] + solve(idx+1, w-wt[idx], wt, val, dp);
        notake = solve(idx+1, w, wt, val, dp);
        return dp[idx][w] = max(take, notake);
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return solve(0, W, wt, val, dp);
    }
};