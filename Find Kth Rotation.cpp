class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i] < arr[i-1])
                return i;
        }
        return 0;
    }
};
