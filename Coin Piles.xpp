class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> pre(n);
        pre[0] = arr[0];
        for(int i=1; i<n; i++)
            pre[i] = arr[i] + pre[i-1];
        
        int prev = 0;   
        int res = INT_MAX;
        for(int i=0; i<n; i++){
            if(i>0)
                prev = pre[i-1];
            int idx = upper_bound(arr.begin(), arr.end(), arr[i]+k) - arr.begin();
            int total = pre[n-1] - pre[idx-1];
            int allowed = (n-idx) * (arr[i]+k);
            int extra = prev + total - allowed;
            res = min(res, extra);
        }
        return res;
        
    }
};
