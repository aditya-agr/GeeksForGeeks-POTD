class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, res = 0;
        for(int x : arr){
            sum += x;
            res += mp[sum-k];
            mp[sum]++;
        }
        return res;
    }
};