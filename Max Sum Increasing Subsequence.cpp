class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n);
        dp[0] = arr[0];
        int res = dp[0];
        for(int i=1; i<n; i++){
            dp[i] = arr[i];
            for(int j=0; j<i; j++){
                if(arr[i] > arr[j]){
                    dp[i] = max(dp[i], dp[j]+arr[i]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};