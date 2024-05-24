class Solution {
  public:
    int mod=1e9+7;
    int solve(vector<int>& arr, int idx, int tar, vector<vector<int>> &dp){
        if(idx==-1){
            if(tar==0)
                return 1;
            return 0;
        }
        if(dp[idx][tar] != -1)
            return dp[idx][tar];
        int take=0, notake=0;
        if(arr[idx]<=tar)
            take = solve(arr, idx-1, tar-arr[idx], dp);
        notake = solve(arr, idx-1, tar, dp);
        dp[idx][tar] = (take%mod + notake%mod)%mod;
        return dp[idx][tar];            
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=0;
        for(auto &i : arr)
            sum += i;
        if(sum<d || (sum-d)%2)
            return 0;
        int target = (sum-d)/2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(arr, n-1, target, dp);
    }
};