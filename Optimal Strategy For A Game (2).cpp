class Solution {
  public:
    int help(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
        if(i>j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int a = arr[i]+min(help(arr,i+2,j,dp),help(arr,i+1,j-1,dp));
        int b = arr[j]+min(help(arr,i,j-2,dp),help(arr,i+1,j-1,dp));
        
        return dp[i][j] = max(a,b);
    }
    int maximumAmount(vector<int> &arr){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int res  = help(arr, 0, n-1, dp);  
        return res;
    }
};