class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int cut(int n, int x, int y, int z, vector<int> &dp){
        if(n<0) return INT_MIN;
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        int tmp = cut(n-x, x, y, z, dp);
        tmp = max(tmp, cut(n-y, x, y, z, dp));
        tmp = max(tmp, cut(n-z, x, y, z, dp));
        return dp[n] = 1+tmp;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1, -1);
        return max(cut(n, x, y, z, dp), 0);
    }
};