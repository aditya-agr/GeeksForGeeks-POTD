class Solution {
  public:
    bool check(vector<int> &arr, int &k, int mid){
        int prev = arr[0];
        int cnt = 1;
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i]-prev >= mid){
                cnt++;
                prev = arr[i];
            }
        }
        return cnt >= k;
    }
    
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int l = 0;
        int h = arr[n-1]-arr[0];
        
        int res = h;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(arr, k, mid)){
                res = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return res;
    }
};
