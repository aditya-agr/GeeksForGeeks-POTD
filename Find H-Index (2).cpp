class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        vector<int> dp(n+1);
        for(int i=0; i<n; i++){
            if(citations[i]<=n)
                dp[citations[i]]++;
            else
                dp[n]++;
        }
        if(dp[n] >= n)
            return n;
        for(int i=n-1; i>=0; i--){
            dp[i] += dp[i+1];
            if(dp[i] >= i)
                return i;
        }
        return 0;
    }
};