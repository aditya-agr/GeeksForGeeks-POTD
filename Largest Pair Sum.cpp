class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        return arr[n-1]+arr[n-2];
    }
};