class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int maxSum = arr[0];
        int minSum = arr[0];
        int mx = 0, mn = 0;
        int total = 0, n = arr.size();
        for(int i=0; i<n; i++){
            mx = max(mx+arr[i], arr[i]);
            maxSum = max(maxSum, mx);
            mn = min(mn+arr[i], arr[i]);
            minSum = min(minSum, mn);
            total += arr[i];
        }
        return max(maxSum, total-minSum);
    }
    
};