class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> rem(n);
        for(int i=0; i<n; i++){
            rem[i] = (arr[i]%k) ? k-(arr[i]%k) : 0;
        }
        sort(rem.begin(), rem.end());
        int res = 0;
        for(int i=0; i<(n+1)/2; i++){
            res += rem[i];
        }
        return res;
    }
};