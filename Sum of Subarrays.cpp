class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int sum = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            sum += arr[i]*(n-i);
        }
        int res = sum;
        for(int i=1; i<n; i++){
            sum -= arr[i-1]*(n-i+1);
            res += sum;
        }
        return res;
    }
};