class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int l = 0;
        int h = arr.size()-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(arr[mid] == target)
                return mid;
            if(arr[mid-1] == target)
                return mid-1;
            if(arr[mid+1] == target)
                return mid+1;
            if(arr[mid] > target)
                h = mid-2;
            else
                l = mid+2;
        }
        return -1;
    }
};