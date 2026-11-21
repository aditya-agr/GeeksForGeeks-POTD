class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        // code here
        int start = 0, currSum = 0, n = arr.size(), ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            currSum += arr[i];
            while (currSum > x && start <= i) {
                ans = min(ans, i - start + 1);
                currSum -= arr[start++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};sss