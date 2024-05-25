class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        long long mx=0, cnt=0;
        for(int i=0; i<n; i++){
            if(arr[i]<=k)
                cnt += arr[i];
            else
                cnt = 0;
            mx = max(cnt, mx);
        }
        return mx;
    }
};