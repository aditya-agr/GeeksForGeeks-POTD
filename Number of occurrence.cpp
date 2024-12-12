class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int st=0, n=arr.size();
        int l=0, h=n-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(arr[mid] == target){
                st = mid;
                h = mid-1;
            }
            else if(arr[mid] < target)
                l = mid+1;
            else
                h = mid-1;
        }
        int count = 0;
        while(st<n && arr[st++]==target)
            count++;
        return count;
    }
};