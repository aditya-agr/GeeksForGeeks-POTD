class Solution {
  public:
    bool check(vector<int> &arr, int mid, int k){
      int curr = 0, cnt=1;
      int n = arr.size();
      for(int i=0; i<n; i++){
          curr += arr[i];
          if(curr>mid){
              curr = arr[i];
              cnt++;
          }
      }
      return cnt<=k;
    }
    int splitArray(vector<int>& arr, int k) {
        // code here
        int tot = 0, mx = 0;
        for(int x : arr){
            mx = max(mx, x);
            tot += x;
        }
        
        int l = mx;
        int h = tot;
        int res = 0;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(arr, mid, k)){
                res = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};