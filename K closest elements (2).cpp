class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        int idx = -1;
        int n = arr.size();
        int l = 0, h = arr.size()-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(arr[mid] >= x)
                h = mid-1;
            else{
                idx = mid;
                l = mid+1;
            }
        }
        int left = idx, right = idx+1;
        if(right<n && arr[right]==x)
            right++;  
        vector<int> res;
        while(left>=0 && right<n && res.size()<k){
            int diffr = abs(arr[right] - x);
            int diffl = abs(arr[left] - x);
            if(diffl < diffr){
                res.push_back(arr[left]);
                left--;
            }
            else{
                res.push_back(arr[right]);
                right++;
            }
        }
        while(left>=0 && res.size()<k){
            res.push_back(arr[left]);
            left--;
        }
        while(right<n && res.size()<k){
            res.push_back(arr[right]);
            right++;
        }
        return res;
    }
};