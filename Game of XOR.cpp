class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n = arr.size();
        int res = 0;
        for(int i=0; i<n; i++){
            int tot = (i+1)*(n-i);
            if(tot%2)
                res ^= arr[i];
        }
        return res;
    }
};