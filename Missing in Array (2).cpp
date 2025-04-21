class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long res = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            res ^= arr[i];
            res ^= (i+1);
        }
        res ^= n+1;
        return res;
    }
};