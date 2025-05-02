class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        if(arr[0] > arr[1])
            return arr[0];
        int n = arr.size();
        for(int i=1; i<n-1; i++)
            if(arr[i] > arr[i+1])
                return arr[i];
        return arr[n-1];
    }
};
