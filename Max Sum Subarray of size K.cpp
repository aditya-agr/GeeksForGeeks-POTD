class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int tot = 0;
        for(int i=0; i<k; i++)
            tot += arr[i];
        
        int res = tot;
        for(int i=k; i<n; i++){
            tot += arr[i];
            tot -= arr[i-k];
            res = max(res, tot);
        }
        return res;
    }
};