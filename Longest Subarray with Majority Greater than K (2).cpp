class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int sum = 0, res = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int n = arr.size();
        for(int i=0; i<n; i++){
            sum += (arr[i] > k) ? 1 : -1;
            if(sum > 0)
                res = max(res, i+1);
            if(mp.count(sum-1))
                res = max(res, i-mp[sum-1]);
            if(!mp.count(sum))
                mp[sum] = i;
        }
        return res;
    }
};