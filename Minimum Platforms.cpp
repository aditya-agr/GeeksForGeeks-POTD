class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i=0, j=0;
        int n = arr.size();
        int res = 0, count = 0;
        while(i<n){
            if(arr[i] <= dep[j]){
                i++;
                count++;
            }
            else{
                j++;
                count--;
            }
            res = max(res, count);
        }
        return res;
    }
};