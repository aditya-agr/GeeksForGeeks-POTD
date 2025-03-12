class Solution {
  public:
    int solve(int i, vector<int>& cost, vector<int>& dp){
        if(i >= cost.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int one = solve(i+1, cost, dp);
        int two = solve(i+2, cost, dp);
        int res = min(one, two);
        if(i != -1)
            res += cost[i];
        return dp[i] = res;
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(solve(0, cost, dp), solve(1, cost, dp));
    }
};
