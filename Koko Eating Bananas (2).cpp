class Solution {
  public:
    bool check(int s, vector<int> & arr, int k){
        int cnt = 0;
        for(int &x : arr){
            cnt += x/s;
            if(x%s) cnt++;
        }
        return cnt <= k;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int l = 1;
        int h = *max_element(arr.begin(), arr.end());
        int res = h;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(check(mid, arr, k)){
                res = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};