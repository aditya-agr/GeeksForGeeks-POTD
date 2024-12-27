class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int ans = 0;
        unordered_map<int, int> mp;
        for(int x : arr){
            ans += mp[target-x];
            mp[x]++;
        }
        return ans;
    }
};