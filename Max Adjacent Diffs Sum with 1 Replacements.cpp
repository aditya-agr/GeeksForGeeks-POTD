class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int keep = 0, replace = 0;
        for(int i=1; i<n; i++){
            int nkeep = max(keep+abs(arr[i]-arr[i-1]), replace+abs(arr[i]-1));
            int nreplace = max(keep+abs(1-arr[i-1]), replace);
            keep = nkeep;
            replace = nreplace;
        }
        return max(keep, replace);
        
    }
};