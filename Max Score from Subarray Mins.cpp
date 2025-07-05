class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int res = 0;
        for(int i=1; i<n; i++)
            res = max(res, arr[i]+arr[i-1]);
        return res;
    }
};