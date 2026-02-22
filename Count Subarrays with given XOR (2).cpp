class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int res = 0, xr = 0;
        int n = arr.size();
        mp[0]++;
        for(int i=0; i<n; i++){
            xr ^= arr[i];
            res += mp[xr^k];
            mp[xr]++;
        }
        return res;
    }
};