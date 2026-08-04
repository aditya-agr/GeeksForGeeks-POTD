class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        int ans = 0;
        for(int i=0; i<n; i++){
            int ind = lower_bound(arr.begin(), arr.end(), arr[i]+k) - arr.begin();
            ind--;
            ans += (ind-i);
        }
        return ans;
    }
};