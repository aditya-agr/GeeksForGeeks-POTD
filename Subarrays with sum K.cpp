class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        mp[0] = 1;
        int n = arr.size(), curr = 0, res = 0;
        for(int i=0; i<n; i++){
            curr += arr[i];
            mp[curr]++;
            res += mp[curr-k];
        }
        return res;
    }
};