class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int mx = arr[0], res = arr[0];
        int n = arr.size();
        for(int i=1; i<n; i++){
            mx = max(mx+arr[i], arr[i]);
            res = max(res, mx);
        }
        return res;
    }
};