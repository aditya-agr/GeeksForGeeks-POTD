class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int l = 0;
        int h = arr.size()-1;
        
        if(k < arr[l])
            return 0;
        if(k > arr[h])
            return h+1;
        
        while(l <= h){
            int mid = l + (h-l)/2;
            if(arr[mid] == k)
                return mid;
            else if(arr[mid] < k){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return l;
    }
};