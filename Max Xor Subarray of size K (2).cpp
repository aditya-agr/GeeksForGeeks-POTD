class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int curr = 0;
        for(int i=0; i<k; i++)
            curr ^= arr[i];
        
        int res = curr;
        for(int i=k; i<n; i++){
            curr ^= arr[i]; 
            curr ^= arr[i-k]; 
            res = max(res, curr);
        }
        return res;
    }
};