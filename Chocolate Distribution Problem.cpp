class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(), a.end());
        int n = a.size();
        int res = INT_MAX;
        for(int i=0; i<n-m+1; i++){
            int j = i+m-1;
            res = min(res, a[j]-a[i]);
        }
        return res;
    }
};