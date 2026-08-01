class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        vector<int> arr(n+1);
        int m = a.size();
        for(int i=0; i<m; i++){
            arr[a[i]] += k[i];
            arr[b[i]+1] -= k[i];
        }
        int res = arr[0];
        for(int i=1; i<n; i++){
            arr[i] += arr[i-1];
            res = max(res, arr[i]);
        }
        return res;
    }
};