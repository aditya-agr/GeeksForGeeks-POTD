class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        long long sum = 0, tot = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            sum += i*arr[i];
            tot += arr[i];
        }
        long long res = sum;
        for(int i=0; i<n; i++){
            sum -= (tot-arr[i]);
            sum += (n-1)*arr[i];
            res = max(res, sum);
        }
        return res;
    }
};