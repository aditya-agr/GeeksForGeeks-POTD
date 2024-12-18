class Solution {
  public:
    bool check(vector<int> &arr, int curr, int k){
        int count=1, sum=0;
        for(int x : arr){
            sum += x;
            if(sum > curr){
                count++;
                sum = x;
            }
        }
        return count <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n<k) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int mid, res=INT_MAX;
        while(low <= high){
            mid = low + (high-low)/2;
            if(check(arr, mid, k)){
                res = min(res, mid);
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return res;
    }
};