class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int n = arr.size();
        int l=0, h=n-1;
        int res=arr[h];
        while(l<h){
            int mid = l + (h-l)/2;
            if(arr[mid] < arr[h]){
                h = mid;
                res = arr[mid];
            }
            else{
                l = mid+1;
                res = arr[h];
            }
        }
        return res;
    }
};