class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        long long tot = 0, curr = 0;
        for(int x : arr)
            tot += x;
        int n = arr.size();
        for(int i=0; i<n; i++){
            tot -= arr[i];
            if(curr == tot)
                return i;
            curr += arr[i];
        }
        return -1;
    }
};