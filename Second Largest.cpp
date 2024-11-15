class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int mx=-1, mx2=-1;
        for(int x : arr)
            mx = max(mx, x);
        for(int x : arr)
            if(x != mx)
                mx2 = max(mx2, x);
        return mx2;
    }
};