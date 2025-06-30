class Solution {
  public:
    bool check(vector<int> &arr, int mid, int k, int &w){
        int n = arr.size();
        vector<int> dp(n+1);
        int cur = 0;
        for(int i=0; i<n; i++){
            if(i>0)
                dp[i] += dp[i-1];
            if(arr[i]+dp[i] < mid){
                int rem = mid-arr[i]-dp[i];
                k -= rem;
                dp[i] += rem;
                dp[min(n, i+w)] -= rem;
            }
            if(k<0)
                return false;
        }
        return k>=0;
    }
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        int mn = INT_MAX;
        for(int x : arr)
            mn = min(mn, x);
            
        int l=mn, h=mn+k;
        int res = 0;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(arr, mid, k, w)){
                res = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return res;
    }
};