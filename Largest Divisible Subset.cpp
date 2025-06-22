class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> dp(n, 1), hash(n, -1);
        int mxidx = -1, mx = 0;
        for(int i=n-2; i>=0; i--){
            for(int j=n-1; j>i; j--){
                if(arr[j]%arr[i] == 0){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        hash[i] = j;
                    }
                    if(dp[i] > mx){
                        mx = dp[i];
                        mxidx = i;
                    }
                }
            }
        }
        vector<int> res;
        int cur = mxidx;
        while(cur != -1){
            res.push_back(arr[cur]);
            cur = hash[cur];
        }
        if(res.empty())
            res.push_back(arr.back());
        return res;
    }
};