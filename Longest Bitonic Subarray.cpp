class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> left(n), right(n);
        for(int i=1; i<n; i++){
            if(arr[i-1]<=arr[i])
                left[i] = left[i-1]+1;
        }
        for(int i=n-2; i>=0; i--){
            if(arr[i+1]<=arr[i])
                right[i] = right[i+1]+1;
        }
        int res = 0;
        for(int i=0; i<n; i++){
            int cur = left[i]+right[i]+1;
            res = max(res, cur);
        }
        return res;
    }
};