class Solution {
  public:
    bool check(vector<int>& arr, int k, int h){
        int cnt = 1, sum = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum > h){
                sum = arr[i];
                cnt++;
            }
        }
        return cnt<=k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int l = *max_element(arr.begin(), arr.end());
        int h = accumulate(arr.begin(), arr.end(), 0);
        int res = h;
        
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(arr, k, mid)){
                res = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};