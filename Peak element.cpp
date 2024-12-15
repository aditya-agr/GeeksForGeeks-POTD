
class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        if(n==1)
            return 0;
        if(arr[0] > arr[1])
            return 0;
        if(arr[n-1] > arr[n-2])
            return n-1;
        int l=1, h=n-2;
        while(l<=h){
            int mid = (l+h)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid] > arr[mid-1])
                l = mid+1;
            else
                h = mid-1;
        }
        return -1;
    }
};