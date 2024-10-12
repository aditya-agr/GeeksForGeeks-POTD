class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        int res = -1;
        int n = arr.size();
        for(int i=0; i<n-1; i++)
            res = max(res, arr[i]+arr[i+1]);
        return res;
        
    }
};