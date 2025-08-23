class Solution {
  public:
    bool check(vector<int> &arr, int mid, int k){
        int cnt = 1, curr = 0;
        for(int x : arr){
            curr += x;
            if(curr > mid){
                curr = x;
                cnt++;
            }
        }
        return cnt <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k>n)
            return -1;
        
        int l = *max_element(arr.begin(), arr.end());
        int h = 0;
        for(int x : arr)
            h += x;
        
        int res = h;
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