lass Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int ans = 0;
        for(int x : arr){
            ans += mp[x-k];
            ans += mp[x+k];
            mp[x]++;
        }
        return ans;
    }
};