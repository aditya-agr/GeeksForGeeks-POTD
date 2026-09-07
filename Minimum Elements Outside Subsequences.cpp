class Solution {
  public:
    int n;
    int dp[102][102][102];
    int solve(int idx, int inc, int dec, vector<int> &arr){
        if(idx == n)
            return 0;
        if(dp[idx][inc][dec] != -1)
           return dp[idx][inc][dec]; 
        int a = 101, b = 101, c = 101;
        if(arr[idx] > inc)
            a = solve(idx+1, arr[idx], dec, arr);
        if(arr[idx] < dec)
            b = solve(idx+1, inc, arr[idx], arr);
        c = 1 + solve(idx+1, inc, dec, arr);
        return dp[idx][inc][dec] = min(a, min(b, c));
    }
    int minCount(vector<int>& arr) {
        // code here
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 101, arr);
    }
};