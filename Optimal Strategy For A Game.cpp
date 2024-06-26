class Solution{
    public:
    long long help(int i,int j,int arr[],vector<vector<long long>> &dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int sum1=arr[i],sum2=arr[j];
        sum1+=min(help(i+2,j,arr,dp),help(i+1,j-1,arr,dp));
        sum2+=min(help(i+1,j-1,arr,dp),help(i,j-2,arr,dp));
        return dp[i][j] = max(sum1,sum2);
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<long long>> dp(n,vector<long long>(n,-1));
        return help(0,n-1,arr,dp);
    }
};