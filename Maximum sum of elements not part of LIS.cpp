class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> dpsum = arr;
        int mn = arr[0], len = 1;
        int total = arr[0];
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[j] < arr[i]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        dpsum[i] = arr[i]+dpsum[j];
                    }
                    else if(dp[j]+1 == dp[i]){
                        dpsum[i] = min(dpsum[i], arr[i]+dpsum[j]);
                    }
                }
            }
            if(dp[i] > len){
                len = dp[i];
                mn = dpsum[i];
            }
            else if(dp[i] == len)
                mn = min(mn, dpsum[i]);
            total += arr[i];
        }
        return total-mn;
    }
};