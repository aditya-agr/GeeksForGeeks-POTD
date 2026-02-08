class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        long long mn = INT_MIN;
        long long res = INT_MIN, prod = 1;
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                prod = 1;
                mn = INT_MIN;
                res = max(res, 0LL);
                continue;
            }
            prod *= arr[i];
            if(prod < 0){
                if(mn != INT_MIN)
                res = max(res, prod/mn);
                mn = max(mn, prod);
            }
            res = max(res, prod);
        }
        return res;
    }
};