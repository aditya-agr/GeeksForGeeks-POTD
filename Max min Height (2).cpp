class Solution {
  public:
    bool check(int h, vector<int> &arr, int &k, int &w){
        int cnt = 0;
        int n = arr.size();
        vector<int> idx(n);
        for(int i=0; i<n; i++){
            if(i > 0)
                idx[i] += idx[i-1];
            if(arr[i]+idx[i] < h){
                int rem = h-arr[i]-idx[i];
                idx[i] += rem;
                if(i+w < n) idx[i+w] -= rem;
                cnt += rem;
            }
        }
        return cnt<=k;
    }
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        int l = *min_element(arr.begin(), arr.end());
        int h = *max_element(arr.begin(), arr.end()) + k;
        int res = l;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(check(mid, arr, k, w)){
                res = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return res;
    }
};