class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int res = 0;
        for(int x : arr){
            int rem = x%k;
            res += mp[(k-rem)%k];
            mp[rem]++;
        }
        return res;
    }
};