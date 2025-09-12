class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mn=INT_MAX, mx=INT_MIN;
        int ans = arr[n-1]-arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]-k<0)
                continue;
            mn = min(arr[0]+k, arr[i]-k);
            mx = max(arr[n-1]-k, arr[i-1]+k);
            ans = min(ans, mx-mn);
        }
        return ans;
    }
};