class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(), arr.end());
        vector<int> res;
        for(vector<int> &q : queries){
            int a = q[0];
            int b = q[1];
            int i = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
            int j = upper_bound(arr.begin(), arr.end(), b) - arr.begin();
            res.push_back(j-i);
        }
        return res;
    }
};