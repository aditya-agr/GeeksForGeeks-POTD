class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int mx=0;
        for(int i : arr)
            mx = max(mx, i);
        vector<int> t(mx+1);
        for(int i : arr)
            t[i]++;
        int cnt=0;
        for(int i=0; i<=mx; i++){
            if(t[i])
                cnt++;
            if(cnt == k)
                return i;
        }
        return -1;
    }
};