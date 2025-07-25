class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int mxsum=INT_MIN, mnsum=INT_MAX;
        int curmx=0, curmn=0, tot=0;
        for(int i=0; i<n; i++){
            tot += arr[i];
            curmx += arr[i];
            curmn += arr[i];
            mnsum = min(mnsum, curmn);
            if(curmn > 0)
                curmn = 0;
            mxsum = max(mxsum, curmx);
            if(curmx < 0)
                curmx = 0;
        }
        if(mxsum < 0) return mxsum;
        return max(mxsum, tot-mnsum);
    }
};