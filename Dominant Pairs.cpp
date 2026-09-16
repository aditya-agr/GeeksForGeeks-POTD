class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int res = 0;
        int n = arr.size();
        sort(arr.begin(), arr.begin()+n/2);
        for(int i=n/2; i<n; i++){
            int cur = arr[i]*5;
            int idx = lower_bound(arr.begin(), arr.begin()+n/2, cur) - arr.begin();
            res += n/2-idx;
        }
        return res;
    }
};