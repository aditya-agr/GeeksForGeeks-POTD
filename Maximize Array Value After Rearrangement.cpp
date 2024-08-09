class Solution {
  public:
    int Maximize(vector<int> arr) {
        // Complete the function
        int n=arr.size(), m=1e9+7;
        long long res=0;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++)
            res = (res%m + (1LL*arr[i]*i)%m)%m;
        return res;
    }
};