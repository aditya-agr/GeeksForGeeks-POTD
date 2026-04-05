class Solution {
  public:
    int dp[51][1001];
    int solve(int i, int cur, vector<int> &arr, int &target){
        int n = arr.size();
        if(i == n){
            if(cur == target)
                return 1;
            return 0;
        }
        if(dp[i][cur] != -1)
            return dp[i][cur];
        int take = solve(i+1, cur+arr[i], arr, target);
        int notake = solve(i+1, cur-arr[i], arr, target);
        return dp[i][cur] = take + notake;
    }
    int totalWays(vector<int>& arr, int target) {
        //  code here
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, arr, target);
    }
};