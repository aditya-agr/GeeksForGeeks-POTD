class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int pre = 1 , suf  =1 ,res = INT_MIN , n =arr.size();
        for(int i=0;i<n;i++){
            if(pre == 0) pre =1;
            if(suf == 0) suf = 1;
            pre *=arr[i];
            suf *= arr[n-1-i];
            res = max({res,pre , suf});
        }
        return res;
    }
};