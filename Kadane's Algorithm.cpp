class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        // code here...
        long long res=INT_MIN, curr=0;
        for(int it : arr){
            curr += it;
            res = max(res, curr);
            if(curr<0)
                curr = 0;
        }
        return res;
    }
};