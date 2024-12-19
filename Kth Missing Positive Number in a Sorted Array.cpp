class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size(), curr = 0, prev = 0;
        for(int i=0; i<n; i++){
            curr = arr[i] - i - 1;
            if(k>=prev && k<=curr)
                return arr[i-1] + (k - prev);
            prev = curr;
        }
        return arr[n-1] + (k-prev);
    }
};