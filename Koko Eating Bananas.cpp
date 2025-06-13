class Solution {
  public:
    bool isValid(int mid, vector<int>& arr, int k){
        int n = arr.size();
        int hours = 0;
        for(int i=0; i<n; i++){
            hours += arr[i]/mid;
            if(arr[i]%mid)
                hours++;
        }
        return hours <= k;
    }
    int kokoEat(vector<int>& arr, int k) {
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