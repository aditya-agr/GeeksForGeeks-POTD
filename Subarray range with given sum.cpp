class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
        int sum=0, cnt=0;
        unordered_map<int, int> mp;
        mp[0]++;
        for(int x : arr){
            sum += x;
            cnt += mp[sum-tar];
            mp[sum]++;
        }
        return cnt;
    }
};