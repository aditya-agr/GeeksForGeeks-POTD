class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int res = 0;
        for(int x : arr)
            res ^= x;
        return res;
    }
};