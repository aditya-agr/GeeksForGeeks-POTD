class Solution {
  public:
    vector<long long> dp;
    long long catalan(int n){
        if(n==0 || n==1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        long long res = 0;
        for(int i=0; i<n; i++)
            res += catalan(i)*catalan(n-i-1);
        return dp[n] = res;
    }
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        int n = arr.size();
        dp.resize(7, -1);
        dp[0] = dp[1] = 1;
        vector<int> res(n);
        for(int i=0; i<n; i++){
            int l=0, r=0;
            for(int j=0; j<n; j++){
                if(i == j)
                    continue;
                if(arr[i] > arr[j])
                    l++;
                else
                    r++;
            }
            res[i] = catalan(l)*catalan(r);
        }
        return res;
    }
};