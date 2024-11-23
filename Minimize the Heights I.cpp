class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mn=INT_MAX, mx=INT_MIN, res=arr[n-1]-arr[0];
        for(int i=0; i<n; i++){
            mn = min(arr[0]+k, arr[i+1]-k);
            mx = max(arr[n-1]-k, arr[i]+k);
            res = min(res, mx-mn);
        }
        return res;
    }
};