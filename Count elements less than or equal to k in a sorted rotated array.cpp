class Solution {
public:
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        int pivot = -1;
        
        // Find rotation point
        for(int i = 1; i < n; i++){
            if(arr[i] < arr[i-1]){
                pivot = i - 1;
                break;
            }
        }
        
        // Handle non-rotated array
        if(pivot == -1){
            int l = 0, h = n - 1, idx = -1;
            while(l <= h){
                int mid = l + (h - l) / 2;
                if(arr[mid] <= x){
                    idx = mid;
                    l = mid + 1;
                }
                else
                    h = mid - 1;
            }
            return idx + 1;
        }
        
        int res = 0;
        
        // Check first part [0...pivot]
        if(arr[0] <= x){
            int l = 0, h = pivot, idx = -1;
            while(l <= h){
                int mid = l + (h - l) / 2;
                if(arr[mid] <= x){
                    idx = mid;
                    l = mid + 1;
                }
                else
                    h = mid - 1;
            }
            if(idx != -1) res += idx + 1;
        }
        
        // Check second part [pivot+1...n-1]
        if(arr[pivot + 1] <= x){
            int l = pivot + 1, h = n - 1, idx = -1;
            while(l <= h){
                int mid = l + (h - l) / 2;
                if(arr[mid] <= x){
                    idx = mid;
                    l = mid + 1;
                }
                else
                    h = mid - 1;
            }
            if(idx != -1) res += idx - pivot;
        }
        
        return res;
    }
};