
class Solution {
  public:
    int solve(int i, int target, vector<int> &arr, vector<vector<int>> &dp){
        int n = arr.size();
        if(i == n){
            if(target == 0)
                return 1;
            return 0;
        }
        if(dp[i][target] != -1)
            return dp[i][target];
        int notake = solve(i+1, target, arr, dp);
        int take = 0;
        if(target >= arr[i])
            take = solve(i+1, target-arr[i], arr, dp);
        return dp[i][target] = take + notake;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int tot = 0;
        int n = arr.size();
        
        for(int &x : arr)
            tot += x;
            
        if((tot-diff)%2 != 0 || tot < diff)
            return 0;
        int target = (tot-diff)/2;
        
        
        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return solve(0, target, arr, dp);
    }
};