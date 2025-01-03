class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> mp;
        int curr=0, cnt=0;
        mp[0] = 1;
        for(int x : arr){
            curr ^= x;
            cnt += mp[curr^k];
            mp[curr]++;
        }
        return cnt;
    }
};