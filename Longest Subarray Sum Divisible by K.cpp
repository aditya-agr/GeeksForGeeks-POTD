class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // code here
        vector<int> dp(k, INT_MAX);
        dp[0] = -1;
        int sum = 0, res = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            sum += arr[i];
            int rem = sum%k;
            rem = (rem+k)%k;
            if(dp[rem] != INT_MAX)
                res = max(res, i-dp[rem]);
            else
                dp[rem] = i;
        }
        return res;
        
    }
};