class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int n = arr.size()-1;
        long long tot = 0;
        for(int i=0; i<n; i++){
            tot += arr[i];
            tot -= i+1;
        }
        tot += arr[n];
        return tot;
    }
};