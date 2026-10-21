class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i=0; i<n; i++)
            arr[i] *= -1;
        
        int mx = 0, len = 0, res = INT_MIN;
        for(int i=0; i<n; i++){
            mx += arr[i];
            res = max(res, arr[i]);
            if(mx <= 0)
                mx = 0;
            else
                res = max(res, mx);
        }
        return -1*res;
    }
};