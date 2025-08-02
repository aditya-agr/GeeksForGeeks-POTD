class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        unordered_map<int, int> mp;
        mp[0] = -1;
        int curr = 0;
        int n = arr.size();
        int res = 0;
        for(int i=0; i<n; i++){
            if(arr[i] > k)
                curr++;
            else
                curr--;
            if(curr > 0)
                res = max(res, i+1);
            if(!mp.count(curr))
                mp[curr] = i;
            if(mp.count(curr-1))
                res = max(res, i-mp[curr-1]);
        }
        return res;
    }
};