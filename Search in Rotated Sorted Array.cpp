class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int pivot = findPivot(arr);
        if (pivot==-1)
            return binarySearch(arr,0,arr.size()-1,key); 
            
        if (arr[pivot]==key)
            return pivot;
        if (arr[0]<=key) 
            return binarySearch(arr,0,pivot-1,key);
        
        return binarySearch(arr,pivot+1,arr.size()-1,key);
    }

    int binarySearch(vector<int> &arr, int start, int end, int key){
        while (start<=end) {
            int mid = start+(end-start)/2;
            if (arr[mid]==key)
                return mid;
            else if (arr[mid]<key)
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;
    }
    
    int findPivot(vector<int> &arr) {
        int start = 0;
        int end = arr.size()-1;
    
        while (start<=end) {
            int mid = start+(end-start)/2;
            
            if (mid<end && arr[mid]>arr[mid+1])
                return mid;
            if (mid>start && arr[mid]<arr[mid-1])
                return mid-1;
                
            if (arr[start]>=arr[mid])
                end = mid-1;
            else
                start = mid+1;
        }
        return -1; 
    }
};