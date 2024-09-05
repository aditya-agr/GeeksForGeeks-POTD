class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {
        // Your code goes here
        int res=1;
        for(int i=0; i<n-1; i++)
            res = res+i+2-arr[i];
        return res;
    }
};