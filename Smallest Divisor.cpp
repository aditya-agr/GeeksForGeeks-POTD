class Solution {
  public:
    bool isValid(int mid, vector<int>& arr, int k){
        int div = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            div += arr[i]/mid;
            if(arr[i]%mid)
                div++;
        }
        return div<=k;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int l = 1;
        int h = *max_element(arr.begin(), arr.end());
        int res = 0;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(isValid(mid, arr, k)){
                res = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};
