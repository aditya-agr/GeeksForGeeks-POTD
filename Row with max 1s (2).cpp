// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int res = -1, mx = 0;
        int n = arr.size();
        int m = arr[0].size();
        
        for(int i=0; i<n; i++){
            int idx = lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin();
            int cnt1 = m-idx;
            if(mx < cnt1){
                mx = cnt1;
                res = i;
            }
        }
        return res;
    }
};