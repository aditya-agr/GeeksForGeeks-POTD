class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> dp(n+1);
        int cnt = 0;
        for(int i=0; i<=n-k; i++){
            if(i>0) dp[i] += dp[i-1];
            if((arr[i]+dp[i])%2 == 0){
                dp[i]++;
                dp[i+k]--;
                cnt++;
            }
        }
        for(int i=n-k+1; i<n; i++){
            dp[i] += dp[i-1];
            if((arr[i]+dp[i])%2 == 0)
                return -1;
        }
        return cnt;
    }
};