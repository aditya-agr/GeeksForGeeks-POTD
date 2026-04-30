class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(2*i+1<n && arr[2*i+1] > arr[i])
                return false;
            if(2*i+2<n && arr[2*i+2] > arr[i])
                return false;
        }
        return true;
    }
};
