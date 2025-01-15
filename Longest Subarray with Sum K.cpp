class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mp;
        long long curr = 0;
        int n = arr.size(), res = 0;
        mp[0] = 0;
        for(int i=0; i<n; i++){
            curr += arr[i];
            if(mp.find(curr-k) != mp.end())
                res = max(res, i-mp[curr-k]+1);
            if(mp.find(curr) == mp.end())
                mp[curr] = i+1;
        }
        return res;
    }
};