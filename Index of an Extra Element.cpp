class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        int l=0, h=n-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(arr1[mid] == arr2[mid])
                l=mid+1;
            else{
                if(mid-1>=0 && arr1[mid] == arr2[mid-1])
                    h=mid;
                else if(mid+1<n-1 && arr1[mid] == arr2[mid+1])
                    l=mid;
                else
                    return mid;
            }
        }
        return -1;
    }
};