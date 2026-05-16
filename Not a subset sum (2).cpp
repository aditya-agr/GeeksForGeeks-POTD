class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        sort(arr.begin(), arr.end());
        long long res = 1; // Start with the smallest positive integer
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > res) {
                break;
            }
            res += arr[i];
        }
        
        return res;
    }
};