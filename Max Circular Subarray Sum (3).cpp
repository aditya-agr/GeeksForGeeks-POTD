class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int mx = 0, mn = 0;
        int mxSum = INT_MIN, mnSum = INT_MAX;
        int tot = 0;
        for(int i=0; i<n; i++){
            mn += arr[i];
            mx += arr[i];
            mxSum = max(mx, mxSum);
            mnSum = min(mn, mnSum);
            if(mx < 0)
                mx = 0;
            if(mn > 0)
                mn = 0;
            tot += arr[i];
        }
        if(mxSum < 0)
            return mxSum;
            
        return max(mxSum, tot-mnSum);
    }
};ss